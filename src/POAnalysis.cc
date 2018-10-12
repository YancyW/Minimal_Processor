#include "Minimal_Processor.h"
#include "CRC.h"


bool Minimal_Processor::analysePOParticle(LCCollection* PFOs_col, LCRelationNavigator* navPFOToMC, Minimal_Processor_Information &info, Minimal_Processor_Counter& counter){

	std::vector<ReconstructedParticle*> po = ToolSet::CRC::Get_POParticle(PFOs_col);

	std::vector<std::vector<MCParticle*> > origin_source;
	ToolSet::CRC::Get_MC_From_PFO_Vec(po,origin_source, navPFOToMC);

	info.data_variable_vec.Get_POParticles_Information( po);

	counter.pass_all++ ;
	return(true);
}



