#include "Minimal_Processor.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>
#include <cmath>

#include <EVENT/LCCollection.h>
#include <EVENT/MCParticle.h>
#include <IMPL/LCCollectionVec.h>

// ----- include for verbosity dependend logging ---------
#include <marlin/VerbosityLevels.h>

#include <TMath.h>
#include <TVector3.h>
#include <TLorentzVector.h>


Minimal_Processor aMinimal_Processor ;

Minimal_Processor::Minimal_Processor()
	: Processor("Minimal_Processor") {

		// Processor description
		_description = "Isolated Photon Finder Processor" ;

		// register steering parameters: name, description, class-variable, default value
		registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
				"InputCollection" ,
				"Input collection of ReconstructedParticles",
				_inputPFOsCollection,
				std::string("PandoraPFOs"));

		registerProcessorParameter( "RootFileName",
				"Name of Root file (default: output.root)",
				_rootfilename, 
				std::string("../result/output.root") );

	}


void Minimal_Processor::init() { 
	std::cout << "   init Minimal_Processor " << std::endl ;
	makeNTuple();
	_nRun = 0;
	_nEvt = 0;
	printParameters() ;
}

void Minimal_Processor::processRunHeader( LCRunHeader* run) { 
} 

void Minimal_Processor::processEvent( LCEvent * evt ) { 

	//init
	_nEvt ++;
	if( _nEvt % 50 == 0 ) std::cout << "processing event "<< _nEvt << std::endl;
    memset( &po_info,    0, sizeof(po_info) );
    po_info.init();
    po_counter.init();



	// PFO loop
	_pfoCol = evt->getCollection( _inputPFOsCollection ) ;
	int npfo = _pfoCol->getNumberOfElements();

	po_counter.evt++;
	for (int i = 0; i < npfo; i++ ) {
		ReconstructedParticle* pfo = dynamic_cast<ReconstructedParticle*>( _pfoCol->getElementAt(i) );

		int output_iso =  GetJetInformation( pfo , po_info);
	}


    _datatrain->Fill();

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

	//Define root tree
	po_info.data_jet.Fill_Data(_datatrain,"jet");
	return;

}











int Minimal_Processor::GetJetInformation( ReconstructedParticle* pfo, Information info ) {
	// energy
	float ecale = pfo->getEnergy();
	// 3-momentum 
	float p     = TVector3( pfo->getMomentum() ).Mag();
	// costheta 
	float angle_costheta = abs(TVector3( pfo->getMomentum() ).CosTheta());
	// costheta 
	float angle_phi = abs(TVector3( pfo->getMomentum() ).Phi());

	info.data_jet.e = ecale;
	info.data_jet.p = p;
	info.data_jet.costheta = angle_costheta;
	info.data_jet.phi= angle_phi;

	// 
	return 0;
}




