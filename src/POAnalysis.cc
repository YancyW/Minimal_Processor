#include "Minimal_Processor.h"
#include "CRC.h"


bool Minimal_Processor::analysePOParticle(LCCollection* PFOs_col, Minimal_Processor_Information &info, Minimal_Processor_Counter& counter){

	std::vector<ReconstructedParticle*> pos = ToolSet::CRC::Get_POParticle(PFOs_col);

	std::vector<std::vector<MCParticle*> > origin_source;
	TrackGetSource(pos,origin_source, _navpo);

	for (int i=0;i<pos.size();i++){
		int output_iso    =  Get_POParticle_Information( pos[i] , info.data_variable);
	}

	counter.pass_all++ ;
	return(true);
}

int Minimal_Processor::Get_POParticle_Information( ReconstructedParticle* input, Minimal_Processor_Variable &var) {
	var.pdg      =input->getType();
	var.p        =ToolSet::CMC::Cal_P(input);
	var.pt       =ToolSet::CMC::Cal_PT(input);
	var.costheta =ToolSet::CMC::Cal_CosTheta(input);
	var.phi      =ToolSet::CMC::Cal_Azimuth(input);
	var.e        =input->getEnergy();
	var.mass     =input->getMass();
	return 0;
}


int Minimal_Processor::Get_POParticles_Information( std::vector<ReconstructedParticle*> input, Minimal_Processor_Variable_Vec &var) {
	// energy
	for(unsigned int i=0;i<input.size();i++){
		var.pdg      .push_back(input[i]->getType());
		var.p        .push_back(ToolSet::CMC::Cal_P(input[i]));
		var.pt       .push_back(ToolSet::CMC::Cal_PT(input[i]));
		var.costheta .push_back(ToolSet::CMC::Cal_CosTheta(input[i]));
		var.phi      .push_back(ToolSet::CMC::Cal_Azimuth(input[i]));
		var.e        .push_back(input[i]->getEnergy());
		var.mass     .push_back(input[i]->getMass());
	}

	// 
	return 0;
}

void Minimal_Processor::TrackGetSource(std::vector<ReconstructedParticle*> &source, std::vector<std::vector<MCParticle*> >  &to, LCRelationNavigator* &relation)
{
	for( unsigned int i = 0; i < source.size(); i++ ){
		std::vector<MCParticle*> to_tmp;

		LCObjectVec frompars = relation->getRelatedToObjects(source[i]);

		for( unsigned int j = 0; j < frompars.size(); j++ ){
			MCParticle* recpfo = dynamic_cast< MCParticle* >( frompars[j] );
			to_tmp.push_back(recpfo);
		}
		to.push_back(to_tmp);
		to_tmp.clear();
	}

	return;
}



void Minimal_Processor::TrackGetObject(std::vector<MCParticle*> &source, std::vector<std::vector<ReconstructedParticle*> >  &to, LCRelationNavigator* &relation)
{
	for( unsigned int i = 0; i < source.size(); i++ ){
		std::vector<ReconstructedParticle*> to_tmp;

		LCObjectVec frompars = relation->getRelatedToObjects(source[i]);

		for( unsigned int j = 0; j < frompars.size(); j++ ){
			ReconstructedParticle* recpfo = dynamic_cast< ReconstructedParticle* >( frompars[j] );
			to_tmp.push_back(recpfo);
		}
		to.push_back(to_tmp);
		to_tmp.clear();
	}

	return;
}


void Minimal_Processor::TrackGetSource(std::vector<Track*> &source, std::vector<std::vector<MCParticle*> >  &to, LCRelationNavigator* &relation)
{
	for( unsigned int i = 0; i < source.size(); i++ ){
		std::vector<MCParticle*> to_tmp;

		LCObjectVec frompars = relation->getRelatedToObjects(source[i]);

		for( unsigned int j = 0; j < frompars.size(); j++ ){
			MCParticle* recpfo = dynamic_cast< MCParticle* >( frompars[j] );
			to_tmp.push_back(recpfo);
		}
		to.push_back(to_tmp);
		to_tmp.clear();
	}

	return;
}



