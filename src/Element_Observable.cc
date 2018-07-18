#include "Element_Observable.h"
void Variable::Fill_Data(TTree* tree, std::string prefix){
	tree->Branch( (prefix+"p").c_str(), &p,(prefix+"p").c_str());
	tree->Branch( (prefix+"costheta").c_str(), &costheta,(prefix+"costheta").c_str());
	tree->Branch( (prefix+"phi").c_str(), &phi,(prefix+"phi").c_str());
	tree->Branch( (prefix+"e").c_str(), &e,(prefix+"e").c_str());
}

