#include "Minimal_Processor_Element_Observable.h"
void Minimal_Processor_Variable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"higgs_channel").c_str()       , &higgs_channel       ,(prefix+"higgs_channel").c_str()       );
	tree->Branch( (prefix+"p").c_str()       , &p       ,(prefix+"p").c_str()       );
	tree->Branch( (prefix+"costheta").c_str(), &costheta,(prefix+"costheta").c_str());
	tree->Branch( (prefix+"phi").c_str()     , &phi     ,(prefix+"phi").c_str()     );
	tree->Branch( (prefix+"e").c_str()       , &e       ,(prefix+"e").c_str()       );
}

void Minimal_Processor_Variable_Vec::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"higgs_channel_vec").c_str()  , &higgs_channel);
	tree->Branch( (prefix+"p_vec")            .c_str()  , &p            );
	tree->Branch( (prefix+"costheta_vec")     .c_str()  , &costheta     );
	tree->Branch( (prefix+"phi_vec")          .c_str()  , &phi          );
	tree->Branch( (prefix+"e_vec")            .c_str()  , &e            );
}

