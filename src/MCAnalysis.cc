#include "Minimal_Processor.h"
#include "CMC.h"

using namespace lcio;
using namespace marlin;
using ToolSet::operator<<;

bool Minimal_Processor::analyseMCParticle( LCCollection* Allmc,   Information &info) {
	//generate all basic sorts 
	std::vector<MCParticle*> MCs =ToolSet::CMC::Get_MCParticle(Allmc);

	std::vector<MCParticle*> hs_FS  =ToolSet::CMC::Get_MC_HardScattering_FS(MCs);

	std::vector<MCParticle*> hs_higgs     =ToolSet::CMC::Get_MCParticleType(hs_FS,25);


	if(hs_higgs.size()>0){
		info.data_jet.higgs_channel = ToolSet::CMC::Get_DecayChannel(hs_higgs[0]);
	}

}






