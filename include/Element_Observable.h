#ifndef ELEMENT_DATATYPE_H
#define ELEMENT_DATATYPE_H  
#include "TTree.h"

class Counter{
	public:
		//***********
		//event number
		//***********
		float evt         ;
		float pass_all    ;

		void init(){
			evt           =0;
			pass_all      =0;
		}
};

//Stored data 
class Variable{
	public:
		//************************
		//inserted by process file
		//************************
		float p                   ;        
		float costheta             ;        
		float phi                  ;        
		float e                    ;        
		void init(){
		    p               =-10.1;        
		    costheta         =-10.1;        
		    phi              =-10.1;        
		    e                =-10.1;        
		}

		void Fill_Data(TTree* tree, std::string prefix);
};

class Information{
	public:
		Variable                        data_jet;


		Information(){
		}


		void init(){
			data_jet.init();
		}


		~Information(){
		}
}; 

#endif
