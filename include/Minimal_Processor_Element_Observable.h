#ifndef Minimal_Processor_ELEMENT_DATATYPE_H
#define Minimal_Processor_ELEMENT_DATATYPE_H  
#include "TTree.h"
#include <string>
#include <iostream>

class Minimal_Processor_Global_Counter{
	public:
		//***********
		//event number
		//***********
		float evt         ;
		float pass_mc     ;
		float pass_po     ;
		float pass_all    ;

		void Init(){
			evt           =0;
			pass_all      =0;
			pass_mc       =0;
			pass_po       =0;
		}

		void Print(){
			std::cout << "in the Global counter, there are " << pass_mc << " pass MC, and " << pass_po << " pass PO, and " <<pass_all << " pass all criterion." << std::endl; 
		}
};

class Minimal_Processor_Counter{
	public:
		//***********
		//event number
		//***********
		float evt         ;
		float pass_all    ;

		void Init(){
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
		float pdg                  ;        
		float p                    ;        
		float pt                   ;        
		float costheta             ;        
		float phi                  ;        
		float e                    ;        
		float mass                 ;        

		void Init(){
		    pdg              =-10000.1;        
		    p                =-10000.1;        
		    pt               =-10000.1;        
		    costheta         =-10000.1;        
		    phi              =-10000.1;        
		    e                =-10000.1;        
		    mass             =-10000.1;        
		}

		void Fill_Data(TTree* tree, std::string prefix);
};

class Minimal_Processor_Variable_Vec{
	public:
		//************************
		//inserted by process file
		//************************
		std::vector<float> pdg                  ;        
		std::vector<float> p                    ;        
		std::vector<float> pt                   ;        
		std::vector<float> costheta             ;        
		std::vector<float> phi                  ;        
		std::vector<float> e                    ;        
		std::vector<float> mass                 ;        

		void Init(){
		    pdg              .clear();        
		    p                .clear();        
		    pt               .clear();        
		    costheta         .clear();        
		    phi              .clear();        
		    e                .clear();        
		    mass             .clear();        
		}

		void Fill_Data(TTree* tree, std::string prefix);
};

class Minimal_Processor_Information{
	public:
		Minimal_Processor_Variable                        data_jet;
		Minimal_Processor_Variable_Vec                    data_jet_vec;


		Minimal_Processor_Information(){
		}


		void Init(){
			data_jet.Init();
			data_jet_vec.Init();
		}


		~Minimal_Processor_Information(){
		}
}; 

#endif
