#include "Minimal_Processor.h"
#include "CRC.h"


bool Minimal_Processor::analysePOParticle(LCCollection* PFOs_col, Minimal_Processor_Information &info){

	std::vector<ReconstructedParticle*> pos = ToolSet::CRC::Get_POParticle(PFOs_col);

	for (int i=0;i<pos.size();i++){
		int output_iso    =  GetFSInformation( pos[i] , info.data_jet);
	}

	return(true);
}

int Minimal_Processor::GetFSInformation( ReconstructedParticle* pfo, Minimal_Processor_Variable &var) {
	// energy
	float ecale = pfo->getEnergy();
	// 3-momentum 
	float p     = TVector3( pfo->getMomentum() ).Mag();
	// costheta 
	float angle_costheta = abs(TVector3( pfo->getMomentum() ).CosTheta());
	// costheta 
	float angle_phi = abs(TVector3( pfo->getMomentum() ).Phi());

	var.e = ecale;
	var.p = p;
	var.costheta = angle_costheta;
	var.phi= angle_phi;

	// 
	return 0;
}




