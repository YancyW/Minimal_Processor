#include "Minimal_Processor_Element_Observable.h"
void Minimal_Processor_Variable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"pdg").c_str()     , &pdg     ,(prefix+"pdg").c_str()     );
	tree->Branch( (prefix+"p").c_str()       , &p       ,(prefix+"p").c_str()       );
	tree->Branch( (prefix+"pt").c_str()      , &pt      ,(prefix+"pt").c_str()      );
	tree->Branch( (prefix+"costheta").c_str(), &costheta,(prefix+"costheta").c_str());
	tree->Branch( (prefix+"phi").c_str()     , &phi     ,(prefix+"phi").c_str()     );
	tree->Branch( (prefix+"e").c_str()       , &e       ,(prefix+"e").c_str()       );
	tree->Branch( (prefix+"mass").c_str()    , &mass    ,(prefix+"mass").c_str()    );
}

void Minimal_Processor_Variable_Vec::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"pdg_vec")          .c_str()  , &pdg          );
	tree->Branch( (prefix+"p_vec")            .c_str()  , &p            );
	tree->Branch( (prefix+"pt_vec")           .c_str()  , &pt           );
	tree->Branch( (prefix+"costheta_vec")     .c_str()  , &costheta     );
	tree->Branch( (prefix+"phi_vec")          .c_str()  , &phi          );
	tree->Branch( (prefix+"e_vec")            .c_str()  , &e            );
	tree->Branch( (prefix+"mass_vec")         .c_str()  , &mass         );
}

