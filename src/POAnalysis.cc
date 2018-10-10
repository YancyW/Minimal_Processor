#include "Minimal_Processor.h"
#include "CRC.h"


bool Minimal_Processor::analysePOParticle(LCCollection* PFOs_col, Minimal_Processor_Information &info, Minimal_Processor_Counter& counter){

	std::vector<ReconstructedParticle*> pos = ToolSet::CRC::Get_POParticle(PFOs_col);

	std::vector<std::vector<MCParticle*> > origin_source;
	TrackGetSource(pos,origin_source, _navpo);

	for (int i=0;i<pos.size();i++){
		int output_iso    =  Get_POParticle_Information( pos[i] , info.data_jet);
	}

	counter.pass_all++ ;
	return(true);
}

int Minimal_Processor::Get_POParticle_Information( ReconstructedParticle* input, Minimal_Processor_Variable &var) {
	// energy
	float ecale = input->getEnergy();
	// 3-momentum 
	float p     = TVector3( input->getMomentum() ).Mag();
	// costheta 
	float angle_costheta = abs(TVector3( input->getMomentum() ).CosTheta());
	// costheta 
	float angle_phi = abs(TVector3( input->getMomentum() ).Phi());
	var.e = ecale;
	var.p = p;
	var.costheta = angle_costheta;
	var.phi= angle_phi;

	// 
	return 0;
}


int Minimal_Processor::Get_POParticles_Information( std::vector<ReconstructedParticle*> input, Minimal_Processor_Variable_Vec &var) {
	// energy
	for(unsigned int i=0;i<input.size();i++){
		float ecale = input[i]->getEnergy();
		// 3-momentum 
		float p     = TVector3( input[i]->getMomentum() ).Mag();
		// costheta 
		float angle_costheta = abs(TVector3( input[i]->getMomentum() ).CosTheta());
		// costheta 
		float angle_phi = abs(TVector3( input[i]->getMomentum() ).Phi());
		
		var.e        .push_back(ecale);
		var.p        .push_back(p);
		var.costheta .push_back(angle_costheta);
		var.phi      .push_back(angle_phi);
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



