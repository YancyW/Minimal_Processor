#include "Minimal_Processor.h"
#include "CMC.h"
using namespace lcio;

bool Minimal_Processor::analyseMCParticle( LCCollection* Allmc,   Minimal_Processor_Information &info, Minimal_Processor_Counter& counter) {
	//generate all basic sorts 
    std::vector<MCParticle*> MCs          =ToolSet::CMC::Get_MCParticle(Allmc);

    std::vector<MCParticle*> hs_FS        =ToolSet::CMC::Get_MC_HardScattering_FS(MCs);

    std::vector<MCParticle*> hs_higgs     =ToolSet::CMC::Get_MCParticleType(hs_FS,25);

    if(hs_higgs.size()>0){
    	info.data_jet.higgs_channel = ToolSet::CMC::Get_DecayChannel(hs_higgs[0]);
    }

	counter.pass_all++;
	return(info.data_jet.higgs_channel);
}


int Minimal_Processor::Get_MCParticle_Information( MCParticle* input, Minimal_Processor_Variable &var) {
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


int Minimal_Processor::Get_MCParticles_Information( std::vector<MCParticle*> input, Minimal_Processor_Variable_Vec &var) {
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




