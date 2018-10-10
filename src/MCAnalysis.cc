#include "Minimal_Processor.h"
#include "CMC.h"
using namespace lcio;

bool Minimal_Processor::analyseMCParticle( LCCollection* Allmc,   Minimal_Processor_Information &info, Minimal_Processor_Counter& counter) {
	//generate all basic sorts 
    std::vector<MCParticle*> MCs          =ToolSet::CMC::Get_MCParticle(Allmc);

    std::vector<MCParticle*> hs_FS        =ToolSet::CMC::Get_MC_HardScattering_FS(MCs);

    std::vector<MCParticle*> hs_higgs     =ToolSet::CMC::Get_MCParticleType(hs_FS,25);

    if(hs_higgs.size()>0){
    	info.data_jet.pdg= ToolSet::CMC::Get_DecayChannel(hs_higgs[0]);
    }

	counter.pass_all++;
	return(true);
}


int Minimal_Processor::Get_MCParticle_Information( MCParticle* input, Minimal_Processor_Variable &var) {
	var.pdg      =input->getPDG();
	var.p        =ToolSet::CMC::Cal_P(input);
	var.pt       =ToolSet::CMC::Cal_PT(input);
	var.costheta =ToolSet::CMC::Cal_CosTheta(input);
	var.phi      =ToolSet::CMC::Cal_Azimuth(input);
	var.e        =input->getEnergy();
	var.mass     =input->getMass();
	return 0;
}


int Minimal_Processor::Get_MCParticles_Information( std::vector<MCParticle*> input, Minimal_Processor_Variable_Vec &var) {
	for(unsigned int i=0;i<input.size();i++){
		var.pdg      .push_back(input[i]->getPDG());
		var.p        .push_back(ToolSet::CMC::Cal_P(input[i]));
		var.pt       .push_back(ToolSet::CMC::Cal_PT(input[i]));
		var.costheta .push_back(ToolSet::CMC::Cal_CosTheta(input[i]));
		var.phi      .push_back(ToolSet::CMC::Cal_Azimuth(input[i]));
		var.e        .push_back(input[i]->getEnergy());
		var.mass     .push_back(input[i]->getMass());
	}
	return 0;
}




