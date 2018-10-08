#include "Minimal_Processor.h"

Minimal_Processor aMinimal_Processor ;

Minimal_Processor::Minimal_Processor()
	: Processor("Minimal_Processor") {

		// Processor description
		_description = "Isolated Photon Finder Processor" ;

		// register steering parameters: name, description, class-variable, default value
		registerInputCollection( LCIO::MCPARTICLE,
				"InputMCParticleCollection", 
				"Name of the MC particle collection",
				_inputMCsCollection,
				std::string("MCParticlesSkimmed") );

		registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
				"InputPOParticleCollection" ,
				"Input collection of ReconstructedParticles",
				_inputPOsCollection,
				std::string("PandoraPFOs"));

	    registerInputCollection( LCIO::LCRELATION,
	    		"InputRecoMCTruthLink",
	    		"Relation between MC and PFO particles",
	    		_mcpoRelation,
	    		std::string("MCTruthMarlinTrkTracksLink"));

		registerProcessorParameter( "RootFileName",
				"Name of Root file (default: output.root)",
				_rootfilename, 
				std::string("../result/output.root") );

	}


void Minimal_Processor::init() { 
	std::cout << "   init Minimal_Processor " << std::endl ;
	std::cout << "the output root file is " << _rootfilename << std::endl; 

	// usually a good idea to
	printParameters();

	// make Ntuple
	makeNTuple();

	_nRun = 0;
	_nEvt = 0;
}

void Minimal_Processor::processRunHeader( LCRunHeader* run) { 
	_nRun++;
} 

void Minimal_Processor::processEvent( LCEvent * evt ) { 

	//init
	_nEvt ++;
	if( _nEvt % 50 == 0 ) std::cout << "processing event "<< _nEvt << std::endl;
    memset( &_mc_info,    0, sizeof(_mc_info) );
    memset( &_po_info,    0, sizeof(_po_info) );
    memset( &_po_counter, 0, sizeof(_po_counter) );
    memset( &_mc_counter, 0, sizeof(_mc_counter) );
    _mc_info.init();
    _po_info.init();
    _mc_counter.init();
    _po_counter.init();



	// PFO loop
    _mcCol = evt->getCollection( _inputMCsCollection  ) ;
	_poCol = evt->getCollection( _inputPOsCollection ) ;
    _navpo = new LCRelationNavigator( evt->getCollection( _mcpoRelation ) );


    bool JMC,JPO;

    JMC =analyseMCParticle(_mcCol, _mc_info);
    if(JMC){
    	_mc_counter.pass_all++;
    }
    else{
		ToolSet::ShowMessage(1,"in processEvent: not pass analyseMCParticle ");
    }



    JPO=analysePOParticle(_poCol, _po_info);

    if(JPO){
    	_po_counter.pass_all++;
    }
    else{
		ToolSet::ShowMessage(1,1,"in processEvent: not pass analysePOParticle ");
    }


    _datatrain->Fill();

	// delete
    delete _navpo;

	streamlog_out(DEBUG) << "   processing event: " << evt->getEventNumber() 
		<< "   in run:  " << evt->getRunNumber() 
		<< std::endl ;

}

void Minimal_Processor::check( LCEvent * evt ) { 
}

void Minimal_Processor::end() { 
	_otfile->cd();
	_datatrain->Write();
	_otfile->Close();
	std::cout << "Minimal_Processor::end()  " << std::endl;
}




void Minimal_Processor::makeNTuple() {

	//Output root file
	std::cout << _rootfilename << std::endl;
	_otfile = new TFile( _rootfilename.c_str() , "RECREATE" );
	_datatrain= new TTree( "datatrain" , "events" );

	//Define root tree
	_mc_info.data_jet.Fill_Data(_datatrain,"mc_jet");
	_po_info.data_jet.Fill_Data(_datatrain,"po_jet");
	return;

}











