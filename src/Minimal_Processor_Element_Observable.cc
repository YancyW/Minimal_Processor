#include "Minimal_Processor_Element_Observable.h"
void Minimal_Processor_Observable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"_visible_energy").c_str()     , &visible_energy,(prefix+"_visible_energy").c_str()     );
}

void Minimal_Processor_Variable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"_pdg").c_str()     , &pdg     ,(prefix+"_pdg").c_str()     );
	tree->Branch( (prefix+"_p").c_str()       , &p       ,(prefix+"_p").c_str()       );
	tree->Branch( (prefix+"_pt").c_str()      , &pt      ,(prefix+"_pt").c_str()      );
	tree->Branch( (prefix+"_costheta").c_str(), &costheta,(prefix+"_costheta").c_str());
	tree->Branch( (prefix+"_phi").c_str()     , &phi     ,(prefix+"_phi").c_str()     );
	tree->Branch( (prefix+"_e").c_str()       , &e       ,(prefix+"_e").c_str()       );
	tree->Branch( (prefix+"_mass").c_str()    , &mass    ,(prefix+"_mass").c_str()    );
}

void Minimal_Processor_Variable_Vec::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"_pdg_vec")          .c_str()  , &pdg          );
	tree->Branch( (prefix+"_p_vec")            .c_str()  , &p            );
	tree->Branch( (prefix+"_pt_vec")           .c_str()  , &pt           );
	tree->Branch( (prefix+"_costheta_vec")     .c_str()  , &costheta     );
	tree->Branch( (prefix+"_phi_vec")          .c_str()  , &phi          );
	tree->Branch( (prefix+"_e_vec")            .c_str()  , &e            );
	tree->Branch( (prefix+"_mass_vec")         .c_str()  , &mass         );
}

