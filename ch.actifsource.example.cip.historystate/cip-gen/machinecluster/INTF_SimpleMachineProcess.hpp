/*********************************************************************
	SYSTEM HistorystateSystem
	IMPLEMENTATION Historystate_cpp
	cip process SimpleMachineProcess interface header file for PROCESS SimpleMachineProcess
	Filename: INTF_SimpleMachineProcess.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_SimpleMachineProcess__)
    #define __INTF_SimpleMachineProcess__


#include "PROC_CipProcess.hpp"
#include "INTF_SimpleMachineProcessNames.hpp"
#include "CipEnumIndexedArray.hpp"

namespace historystatesunit
{
    
	namespace machinecluster
	{
        
		/** 
		* class INTF_SimpleMachineProcess
		* interface for process SimpleMachineProcess
		*/
		class INTF_SimpleMachineProcess : 
			public cipmachine::PROC_CipProcess
		{
		friend class PROC_SimpleMachineProcess;
	public: 
            
		/** constructors / destructors */
		INTF_SimpleMachineProcess(void) :
			cipmachine::PROC_CipProcess(),
			STATE(INTF_SimpleMachineProcessNames::PowerOff),
			TEMP_STATE(INTF_SimpleMachineProcessNames::PowerOff)
		{
			HISTORY_STATE[INTF_SimpleMachineProcessNames::E_HistoryState::PowerOn_HistoryState] = INTF_SimpleMachineProcessNames::Idle;
		}

		virtual ~INTF_SimpleMachineProcess(void){}

		/** initialize the pointers to interaction processes */
		virtual void initInteraction(  
			void* i_SimpleMachineProcess) = 0;
		
		/** startup the entry function from the process */	
		virtual void startup(void) = 0;

		/** INPORT EVENT_PORT */
		/** 
		* Trigger the process with message C1_powerOn
		*/
		virtual void C1_powerOn(void) = 0;
		
		/** 
		* Trigger the process with message C1_powerOff
		*/
		virtual void C1_powerOff(void) = 0;
		
		/** 
		* Trigger the process with message C1_doMachineStuff
		*/
		virtual void C1_doMachineStuff(void) = 0;
		
		/** 
		* Trigger the process with message C1_nextWorkload
		*/
		virtual void C1_nextWorkload(void) = 0;
		
		/** 
		* Trigger the process with message C1_powerFail
		*/
		virtual void C1_powerFail(void) = 0;
		
	    
	protected: 
 
		/** status variables */

		INTF_SimpleMachineProcessNames::E_State STATE;
		INTF_SimpleMachineProcessNames::E_State TEMP_STATE;
		ciplibrary::CipEnumIndexedArray<INTF_SimpleMachineProcessNames::E_State, INTF_SimpleMachineProcessNames::E_HistoryState, 1> HISTORY_STATE;

	private: 
            
		/** prohibitted default functions */
		INTF_SimpleMachineProcess(const INTF_SimpleMachineProcess&);
		INTF_SimpleMachineProcess& operator=(const INTF_SimpleMachineProcess&);

        }; // class INTF_SimpleMachineProcess

    } // namespace machinecluster
} // namespace historystatesunit

#endif // __INTF_SimpleMachineProcess__

/*********************************************************************
    End of cip process SimpleMachineProcess interface header for PROCESS SimpleMachineProcess
*********************************************************************/
/* Actifsource ID=[e2fd58fb-0973-11e3-b902-17aaca85d2fd,1d05cec7-9ac1-11ef-9dfa-835f60e5a95d,73ed890e-9ac0-11ef-9dfa-835f60e5a95d,f0198f93-9ac0-11ef-9dfa-835f60e5a95d,1d05cec6-9ac1-11ef-9dfa-835f60e5a95d,1d05cec5-9ac1-11ef-9dfa-835f60e5a95d,3eff29c8-9ac1-11ef-9dfa-835f60e5a95d,d8702bbe-9ac1-11ef-9dfa-835f60e5a95d,Y0YDkApaGDnU2yr4K/fGrB4daok=] */
