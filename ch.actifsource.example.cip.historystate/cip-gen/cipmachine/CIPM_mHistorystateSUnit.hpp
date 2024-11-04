/*********************************************************************
	SYSTEM HistorystateSystem
	IMPLEMENTATION Historystate_cpp
	cip machine header file for CIP MACHINE mHistorystateSUnit
	Filename: CIPM_mHistorystateSUnit.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__CIPM_mHistorystateSUnit__)
    #define __CIPM_mHistorystateSUnit__

#include "INTF_Constant.hpp"
#include "INTF_ActionMessagePort.hpp"
#include "INTF_mHistorystateSUnit.hpp"
#include "INTF_ReadNames.hpp"
#include "LOCAL_QueueData.hpp"
#include "INTF_SimpleMachineProcess.hpp"
#include "CipTimerQueue.hpp"
#include "CipChainQueue.hpp"
#include "CipAutoQueue.hpp"
#include "CipReadQueue.hpp"

namespace historystatesunit
{
	namespace cipmachine
	{
        
		/** 
		* class CIPM_mHistorystateSUnit
		* cip machine for unit HistorystateSUnit
		*/
		class CIPM_mHistorystateSUnit : 
			public historystatesunit::cipshell::INTF_mHistorystateSUnit, 
			public historystatesunit::cipshell::INTF_Constant
		{
		public: 
            
			/** consructors / destructors */
				explicit
			CIPM_mHistorystateSUnit(
				historystatesunit::cipshell::INTF_ActionMessagePort* i_amp);
	
			CIPM_mHistorystateSUnit(void){}
	
			virtual ~CIPM_mHistorystateSUnit(void);
	
			/** event message interface */
			/** 
			* Triggers CIP Machine by input message doMachineStuff (channel Event_1).
			*/
			virtual void C1_doMachineStuff(void);
	            
			/** 
			* Triggers CIP Machine by input message nextWorkload (channel Event_1).
			*/
			virtual void C1_nextWorkload(void);
	            
			/** 
			* Triggers CIP Machine by input message powerFail (channel Event_1).
			*/
			virtual void C1_powerFail(void);
	            
			/** 
			* Triggers CIP Machine by input message powerOff (channel Event_1).
			*/
			virtual void C1_powerOff(void);
	            
			/** 
			* Triggers CIP Machine by input message powerOn (channel Event_1).
			*/
			virtual void C1_powerOn(void);
	            
			/** extension interface */
			
			/** 
			* Triggers CIP Machine to increment time by one tick.
			*/
			virtual void TICK_(void);
	            
			/** 
			* Triggers CIP Machine to execute one pending internal activation.
			*  Search order: CHAIN_, TIMEUP_, READ_
			*/
			virtual void STEP_(void);
	            
			/** 
			* Triggers CIP Machine to execute one pending timeup activation.
			*/
			virtual void TIMEUP_(void);
	            
			/** 
			* Triggers CIP Machine to execute one pending chain activation.
			*/
			virtual void CHAIN_(void);
	            
			/** 
			* Trigger CIP Machine to execute one internally buffered message.
			*/
			virtual void READ_(void);
	            
			/** 
			* Trigger CIP Machine to execute one AUTO_
			*/
			virtual void AUTO_(void);
	
			/** 
			* Test if any local step activation is pending and return the result.
			* @return  if local step activation is pending.
			*/
			virtual bool hasSTEP_(void);
	            
			/** 
			* Test if a chain activation is pending and return the result.
			* @return  if a chain activation is pending.
			*/
			virtual bool hasCHAIN_(void);
	            
			/** 
			* Test if a timeup activation is pending and return the result.
			* @return  if a timeup activation is pending.
			*/
			virtual bool hasTIMEUP_(void);
	            
			/** 
			* Test if a read activation is pending and return the result.
			* @return  if a read activation is pending.
			*/
			virtual bool hasREAD_(void);
	            
			/** 
			* Test if an auto activation is pending and return the result.
			* @return  if a auto activation is pending.
			*/
			virtual bool hasAUTO_(void);
	
		private: 
	            
			/** prohibitted default functions */
	
			CIPM_mHistorystateSUnit(const CIPM_mHistorystateSUnit&);
			CIPM_mHistorystateSUnit& operator=(const CIPM_mHistorystateSUnit&);
	
	
			/** member variables */
	            
			/** user implemented output message handler */
			historystatesunit::cipshell::INTF_ActionMessagePort* m_ActionMessagePort;
	            
	
	            
			/** timer queue */
			ciplibrary::CipTimerQueue<cipmachine::PROC_CipProcess > m_timerQueue;
	            
			/** chain queue */
			ciplibrary::CipChainQueue<cipmachine::PROC_CipProcess > m_chainQueue;
	            
			/** auto queue */
			ciplibrary::CipAutoQueue<cipmachine::PROC_CipProcess > m_autoQueue;
	            
			/** read queue */
			ciplibrary::CipReadQueue<ciplibrary::CipRead<cipmachine::LOCAL_QueueData, cipmachine::INTF_ReadNames::E_Reads, cipmachine::PROC_CipProcess >, ciplibrary::INTF_CipError<char > >* m_readQueue;
	 
			/** Status vectors of cluster MachineCluster */
	
			/** Process SimpleMachineProcess */
			historystatesunit::machinecluster::INTF_SimpleMachineProcess* SimpleMachineProcess;
	            
		}; // class CIPM_mHistorystateSUnit

	} // namespace cipmachine
} // namespace historystatesunit

#endif // __CIPM_mHistorystateSUnit__

/*********************************************************************
    End of cip machine header for CIP MACHINE mHistorystateSUnit
*********************************************************************/

/* Actifsource ID=[65dba398-0beb-11e3-b115-a3f7f19b76fe,1d05cec7-9ac1-11ef-9dfa-835f60e5a95d,73ed890e-9ac0-11ef-9dfa-835f60e5a95d,f0198f93-9ac0-11ef-9dfa-835f60e5a95d,1d05cec6-9ac1-11ef-9dfa-835f60e5a95d,1d05cec5-9ac1-11ef-9dfa-835f60e5a95d,OYqXlmRwK/R69NynYSbVSMGPDLM=] */