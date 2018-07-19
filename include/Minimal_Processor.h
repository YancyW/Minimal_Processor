/**
 * @brief Marlin processor for finding jet.
 * @author Yan Wang <yan.wang@desy.de>
 * @version $Id:$
 *
 * Given a list of ReconstructedParticle, identify isolated photons
 * based on the ecal energy, photon identification,
 */
#ifndef Minimal_Processor_h
#define Minimal_Processor_h 1

#include <string>
#include <map>

#include <marlin/Processor.h>
#include <lcio.h>

#include <EVENT/ReconstructedParticle.h>
#include <EVENT/MCParticle.h>
#include <UTIL/LCRelationNavigator.h>
#include "TTree.h"
#include "TFile.h"


#include "Minimal_Processor_Element_Observable.h"
//header in the ToolSet
#include "CPrint.h"
#include "CFormat.h"

class TFile;
class TTree;

using namespace lcio ;
using namespace marlin ;
using namespace std;
using ToolSet::operator<<;

class Minimal_Processor : public Processor {

	public:

		virtual Processor*  newProcessor() { return new Minimal_Processor ; }

		Minimal_Processor() ;

		virtual void init() ;
		virtual void processRunHeader( LCRunHeader* run ) ;
		virtual void processEvent( LCEvent * evt ) ; 
		virtual void check( LCEvent * evt ) ; 
		virtual void end() ;

	protected:

		// input 
		std::string _inputPOsCollection;
		std::string _inputMCsCollection;
		std::string _rootfilename;
		std::string _mcpoRelation;

		// parameter 
		LCCollection* _poCol;
		LCCollection* _mcCol;
		LCRelationNavigator* _navpo;
		int  _nEvt; 
		int _nRun;

		// output 
		TFile* _otfile;
		TTree* _datatrain;


		//function

		/** Calculates the cone energy */
		bool analyseMCParticle( LCCollection* MCs_col, Minimal_Processor_Information &info) ;
		bool analysePOParticle( LCCollection* POs_col, Minimal_Processor_Information &info);


		int GetFSInformation( ReconstructedParticle* po, Minimal_Processor_Variable& var) ;
		void makeNTuple();

	public:
		Minimal_Processor_Counter      _mc_counter;
		Minimal_Processor_Counter      _po_counter;
		Minimal_Processor_Information  _mc_info;
		Minimal_Processor_Information  _po_info;

} ;

#endif

