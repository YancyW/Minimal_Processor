#ifndef Minimal_Processor_ELEMENT_DATATYPE_H
#define Minimal_Processor_ELEMENT_DATATYPE_H  
#include "TTree.h"
#include <string>

class Minimal_Processor_Counter{
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
class Minimal_Processor_Variable{
	public:
		//************************
		//inserted by process file
		//************************
		float higgs_channel        ;        
		float p                    ;        
		float costheta             ;        
		float phi                  ;        
		float e                    ;        

		void init(){
		    higgs_channel    =-10000.1;        
		    p                =-10000.1;        
		    costheta         =-10000.1;        
		    phi              =-10000.1;        
		    e                =-10000.1;        
		}

		void Fill_Data(TTree* tree, std::string prefix);
};

class Minimal_Processor_Information{
	public:
		Minimal_Processor_Variable                        data_jet;


		Minimal_Processor_Information(){
		}


		void init(){
			data_jet.init();
		}


		~Minimal_Processor_Information(){
		}
}; 

#endif
