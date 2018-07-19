#include "Minimal_Processor_Element_Observable.h"
void Minimal_Processor_Variable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"higgs_channel").c_str()       , &higgs_channel       ,(prefix+"higgs_channel").c_str()       );
	tree->Branch( (prefix+"p").c_str()       , &p       ,(prefix+"p").c_str()       );
	tree->Branch( (prefix+"costheta").c_str(), &costheta,(prefix+"costheta").c_str());
	tree->Branch( (prefix+"phi").c_str()     , &phi     ,(prefix+"phi").c_str()     );
	tree->Branch( (prefix+"e").c_str()       , &e       ,(prefix+"e").c_str()       );
}

