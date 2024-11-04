/*********************************************************************
	SYSTEM HistorystateSystem
	IMPLEMENTATION Historystate_cpp
	cip machine file for CIP MACHINE mHistorystateSUnit
	Filename: CIPM_mHistorystateSUnit.cpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/

#include "CIPM_mHistorystateSUnit.hpp"
#include "PROC_SimpleMachineProcess.hpp"


namespace historystatesunit
{
	namespace cipmachine
	{
        
		/** consructors / destructors */
		CIPM_mHistorystateSUnit::CIPM_mHistorystateSUnit(
			historystatesunit::cipshell::INTF_ActionMessagePort* i_amp) :
			m_ActionMessagePort(i_amp) 
		{
			TIME = 0;
			m_readQueue = new ciplibrary::CipReadQueue<ciplibrary::CipRead<cipmachine::LOCAL_QueueData, cipmachine::INTF_ReadNames::E_Reads, cipmachine::PROC_CipProcess >, ciplibrary::INTF_CipError<char > >(1);

			SimpleMachineProcess =
				new historystatesunit::machinecluster::PROC_SimpleMachineProcess(          
					m_ActionMessagePort);
			SimpleMachineProcess->initInteraction(SimpleMachineProcess);
			SimpleMachineProcess->startup();
		} // constructor

		CIPM_mHistorystateSUnit::~CIPM_mHistorystateSUnit(void)
		{
        
			delete SimpleMachineProcess;	
			delete m_readQueue;
		} // destructor

		/** event messages */
		/**
		* Triggers CIP Machine by input message doMachineStuff (channel Event_1).
		*/
		void CIPM_mHistorystateSUnit::C1_doMachineStuff (void)
		{
			 SimpleMachineProcess->C1_doMachineStuff();
		} // C1_doMachineStuff()
		
		/**
		* Triggers CIP Machine by input message nextWorkload (channel Event_1).
		*/
		void CIPM_mHistorystateSUnit::C1_nextWorkload (void)
		{
			 SimpleMachineProcess->C1_nextWorkload();
		} // C1_nextWorkload()
		
		/**
		* Triggers CIP Machine by input message powerFail (channel Event_1).
		*/
		void CIPM_mHistorystateSUnit::C1_powerFail (void)
		{
			 SimpleMachineProcess->C1_powerFail();
		} // C1_powerFail()
		
		/**
		* Triggers CIP Machine by input message powerOff (channel Event_1).
		*/
		void CIPM_mHistorystateSUnit::C1_powerOff (void)
		{
			 SimpleMachineProcess->C1_powerOff();
		} // C1_powerOff()
		
		/**
		* Triggers CIP Machine by input message powerOn (channel Event_1).
		*/
		void CIPM_mHistorystateSUnit::C1_powerOn (void)
		{
			 SimpleMachineProcess->C1_powerOn();
		} // C1_powerOn()
		
		/** extension functions */
		/** 
		* Triggers CIP Machine to increment time by one tick.
		*/
		void CIPM_mHistorystateSUnit::TICK_(void)
		{
			TIME += 1;
			m_timerQueue.TICK_();
		} // TICK_()

		/** 
		* Triggers CIP Machine to execute one pending internal activation.
		*  Search order: CHAIN_, TIMEUP_, READ_
		*/
		void CIPM_mHistorystateSUnit::STEP_(void)
		{
			if (m_chainQueue.hasCHAIN_())
			{
				m_chainQueue.CHAIN_();
			}
			else if (m_timerQueue.hasTIMEUP_())
			{
				m_timerQueue.TIMEUP_();
			}
			else if (m_autoQueue.hasAUTO_())
			{
				m_autoQueue.AUTO_();
			}
			else if (m_readQueue->hasREAD_())
			{
				m_readQueue->READ_();
			}
			else 
			{
				return;
			}
		} // STEP_()

		/** 
		* Triggers CIP Machine to execute one pending timeup activation.
		*/
		void CIPM_mHistorystateSUnit::TIMEUP_(void)
		{
			m_timerQueue.TIMEUP_();
		} // TIMEUP_()

		/** 
		* Triggers CIP Machine to execute one pending chain activation.
		*/
		void CIPM_mHistorystateSUnit::CHAIN_(void)
		{
			m_chainQueue.CHAIN_();
		} // CHAIN_()
  
		/** 
		* Trigger CIP Machine to execute one internally buffered message.
		*/
		void CIPM_mHistorystateSUnit::READ_(void)
		{
			if (m_readQueue->hasREAD_())
			{
				m_readQueue->READ_();
			}
			else 
			{
				m_autoQueue.AUTO_();
			}
		} // READ_()

		/** 
		* Trigger CIP Machine to execute one AUTO_
		*/
		void CIPM_mHistorystateSUnit::AUTO_(void)
		{
			m_autoQueue.AUTO_();
		} // AUTO_()

		/** 
		* Test if any local step activation is pending and return the result.
		* @return  if local step activation is pending.
		*/
		bool CIPM_mHistorystateSUnit::hasSTEP_(void)
		{
			return m_chainQueue.hasCHAIN_() || 
				m_timerQueue.hasTIMEUP_() || 
				m_autoQueue.hasAUTO_() || 
				m_readQueue->hasREAD_();
		} // hasSTEP_()
        
		/** 
		* Test if a chain activation is pending and return the result.
		* @return  if a chain activation is pending.
		*/
		bool CIPM_mHistorystateSUnit::hasCHAIN_(void)
		{
			return m_chainQueue.hasCHAIN_();
		} // hasCHAIN_()
        
		/** 
		* Test if a timeup activation is pending and return the result.
		* @return  if a timeup activation is pending.
		*/
		bool CIPM_mHistorystateSUnit::hasTIMEUP_(void)
		{
			return m_timerQueue.hasTIMEUP_();
		} // hasTIMEUP_()
        
		/** 
		* Test if a read activation is pending and return the result.
		* @return  if a read activation is pending.
		*/
		bool CIPM_mHistorystateSUnit::hasREAD_(void)
		{
			return m_readQueue->hasREAD_();
		} // hasREAD_()
        
		/** 
		* Test if an auto activation is pending and return the result.
		* @return  if a auto activation is pending.
		*/
		bool CIPM_mHistorystateSUnit::hasAUTO_(void)
		{
			return m_autoQueue.hasAUTO_();
		} // hasAUTO_()

	} // namespace cipmachine
} // namespace historystatesunit

/*********************************************************************
    End of cip machine for CIP MACHINE mHistorystateSUnit
*********************************************************************/
/* Actifsource ID=[77fe41ec-08ae-11e3-b902-17aaca85d2fd,1d05cec7-9ac1-11ef-9dfa-835f60e5a95d,73ed890e-9ac0-11ef-9dfa-835f60e5a95d,f0198f93-9ac0-11ef-9dfa-835f60e5a95d,1d05cec6-9ac1-11ef-9dfa-835f60e5a95d,1d05cec5-9ac1-11ef-9dfa-835f60e5a95d,94NP0aZEHFK1o2/39Y86WoaNb6I=] */
