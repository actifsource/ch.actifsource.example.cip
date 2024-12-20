/*********************************************************************
	SYSTEM TemplateSystem
	IMPLEMENTATION Template_cpp
	cip process MachineProcess file for PROCESS MachineProcess
	Filename: PROC_MachineProcess.cpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        enable mode inspection
	        'unsigned long' for delays
*********************************************************************/

#include "PROC_MachineProcess.hpp"

namespace templateunit
{

	namespace machinecluster
	{
        
		/** constructors / destructors */
	        PROC_MachineProcess::PROC_MachineProcess(
			templateunit::cipshell::INTF_ActionMessagePort* i_amp) :     
				INTF_MachineProcess(),
				m_ActionMessagePort(i_amp),
				SELF(*this),
				MachineProcess(this) 
		{}// constructor		
		
		/** initialize the pointers to interaction processes */
		void PROC_MachineProcess::initInteraction(
			void* i_MachineProcess)
		{
			STATUS = static_cast<INTF_MachineProcess* >(i_MachineProcess);
		} // initInteraction()
		
		/** startup the entry function from the process */
		void PROC_MachineProcess::startup(void)
		{
			triggerStateAction(EntryAction, _no_state_);
		} // startup
		
		
		/** INPORT InportA */
		/**
		* Trigger the process with message C1_doMachineStuff
		*/
		void PROC_MachineProcess::C1_doMachineStuff(void)
		{	
			switch(STATE)
			{
				case Idle:	
					/* [[de2368db-9b56-11ef-800e-630ffd8f1eac,Transition]] */
					printf("       TRANSITION '1 doMachineStuff' MachineProcess.normalA: STATE Idle -> Workload_1  [de2368db-9b56-11ef-800e-630ffd8f1eac]\n");
					STATE = Workload_1;
					/* Entry functions */
					triggerStateAction(EntryAction, PowerOn);
				break;
			default:
				break;
			}
		} // C1_doMachineStuff()

		/**
		* Trigger the process with message C1_nextWorkload
		*/
		void PROC_MachineProcess::C1_nextWorkload(void)
		{	
			switch(STATE)
			{
				case Workload_1:	
					/* [[308f9c31-9b58-11ef-800e-630ffd8f1eac,Transition]] */
					printf("       TRANSITION '5 nextWorkload' MachineProcess.normalA: STATE Workload_1 -> Workload_2  [308f9c31-9b58-11ef-800e-630ffd8f1eac]\n");
					STATE = Workload_2;
					/* Entry functions */
					triggerStateAction(EntryAction, ActiveMode);
				break;
				case Workload_2:	
					/* [[4d6a1590-9b58-11ef-800e-630ffd8f1eac,Transition]] */
					printf("       TRANSITION '6 nextWorkload' MachineProcess.normalA: STATE Workload_2 -> Workload_3  [4d6a1590-9b58-11ef-800e-630ffd8f1eac]\n");
					STATE = Workload_3;
					/* Entry functions */
					triggerStateAction(EntryAction, ActiveMode);
				break;
				case Workload_3:	
					/* [[4ee2ac43-9b58-11ef-800e-630ffd8f1eac,Transition]] */
					printf("       TRANSITION '7 nextWorkload' MachineProcess.normalA: STATE Workload_3 -> Workload_1  [4ee2ac43-9b58-11ef-800e-630ffd8f1eac]\n");
					STATE = Workload_1;
					/* Entry functions */
					triggerStateAction(EntryAction, ActiveMode);
				break;
			default:
				break;
			}
		} // C1_nextWorkload()

		/**
		* Trigger the process with message C1_powerFail
		*/
		void PROC_MachineProcess::C1_powerFail(void)
		{	
			switch(STATE)
			{
				case PowerOn:	
					/* [[4a863a9b-9b59-11ef-800e-630ffd8f1eac,Transition]] */
					/* Exit functions */
					STATE = TEMP_STATE;
					triggerStateAction(ExitAction, _no_state_);
					printf("       TRANSITION '102 powerFail' MachineProcess.normalA: STATE PowerOn -> PowerOff  [4a863a9b-9b59-11ef-800e-630ffd8f1eac]\n");
					STATE = PowerOff;
						m_ActionMessagePort->f_C2_powerFail();                                                        
				break;
				case ActiveMode:
					STATE = PowerOn;
					C1_powerFail();
				break;
				case Idle:
					STATE = PowerOn;
					TEMP_STATE = Idle;
					C1_powerFail();
				break;
				case Workload_1:
					STATE = ActiveMode;
					TEMP_STATE = Workload_1;
					C1_powerFail();
				break;
				case Workload_2:
					STATE = ActiveMode;
					TEMP_STATE = Workload_2;
					C1_powerFail();
				break;
				case Workload_3:
					STATE = ActiveMode;
					TEMP_STATE = Workload_3;
					C1_powerFail();
				break;
			default:
				break;
			}
		} // C1_powerFail()

		/**
		* Trigger the process with message C1_powerOff
		*/
		void PROC_MachineProcess::C1_powerOff(void)
		{	
			switch(STATE)
			{
				case Idle:	
					/* [[02afcc0a-9b57-11ef-800e-630ffd8f1eac,Transition]] */
					printf("       TRANSITION '4 powerOff' MachineProcess.normalA: STATE Idle -> PowerOff  [02afcc0a-9b57-11ef-800e-630ffd8f1eac]\n");
					STATE = PowerOff;
						m_ActionMessagePort->f_C2_powerOff();                                                        
				break;
			default:
				break;
			}
		} // C1_powerOff()

		/**
		* Trigger the process with message C1_powerOn
		*/
		void PROC_MachineProcess::C1_powerOn(void)
		{	
			switch(STATE)
			{
				case PowerOff:	
					if (1)    // CONDITION ConditionOperationB
					{
						/* [[e2400bfa-9b58-11ef-800e-630ffd8f1eac,Transition]] */
						printf("       TRANSITION '101 powerOn' MachineProcess.normalA: STATE PowerOff -> PowerOn_HistoryState  [e2400bfa-9b58-11ef-800e-630ffd8f1eac]\n");
						STATE = HISTORY_STATE[PowerOn_HistoryState];
						/* Entry functions */
						triggerStateAction(EntryHistoryAction, _no_state_);
					}
					else // CONDITION ELSE_
					{
						/* [[eebbea56-9b56-11ef-800e-630ffd8f1eac,Transition]] */
						printf("       TRANSITION '2 powerOn' MachineProcess.normalA: STATE PowerOff -> Idle  [eebbea56-9b56-11ef-800e-630ffd8f1eac]\n");
						STATE = Idle;
							m_ActionMessagePort->f_C2_powerOn();                                                        
						/* Entry functions */
						triggerStateAction(EntryAction, _no_state_);
					}
				break;
			default:
				break;
			}
		} // C1_powerOn()

	 	/** 
		 * Trigger the process with inpulse InpulseA.
		 */
		void PROC_MachineProcess::BHV_InpulseA(void)
		{ 
			return;
		} // BHV_InpulseA()
	
		/**
		 * Trigger the process with state functions.
		 */
		void PROC_MachineProcess::triggerStateAction(INTF_MachineProcessNames::E_StateAction stateAction, INTF_MachineProcessNames::E_State baseState)
		{
			switch(stateAction)
			{
			case EntryAction:
			case EntryHistoryAction:
				switch(STATE)
				{
					case ActiveMode:
						if (baseState != PowerOn)
						{
							STATE = PowerOn;
							triggerStateAction(stateAction, baseState);
							STATE = ActiveMode;
						}
						if (1)    // CONDITION ConditionOperationB
						{
							/* [[0a6b8e11-9b59-11ef-800e-630ffd8f1eac,EntryTransition]] */
							printf("       TRANSITION '103 ENTRY_' MachineProcess.normalA: STATE ActiveMode   [0a6b8e11-9b59-11ef-800e-630ffd8f1eac]\n");
						}
						else // CONDITION ELSE_
						{
							/* [[02433cca-9b59-11ef-800e-630ffd8f1eac,EntryTransition]] */
							printf("       TRANSITION '8 ENTRY_' MachineProcess.normalA: STATE ActiveMode   [02433cca-9b59-11ef-800e-630ffd8f1eac]\n");
						}
					break;
					case PowerOn:
						break;
					case Workload_1:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_1;
						}
						break;
					case Workload_2:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_2;
						}
						break;
					case Workload_3:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_3;
						}
						break;
				default:
					return;
				}
			break;
			case ExitAction:
				switch(STATE)
				{
					case PowerOn:
						HISTORY_STATE[PowerOn_HistoryState] = TEMP_STATE;
					break;
					case Idle:
						if (baseState != PowerOn)
						{
							STATE = PowerOn;
							triggerStateAction(stateAction, baseState);
							STATE = Idle;
						}
						break;
					case ActiveMode:
						if (baseState != PowerOn)
						{
							STATE = PowerOn;
							triggerStateAction(stateAction, baseState);
							STATE = ActiveMode;
						}
						break;
					case Workload_1:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_1;
						}
						break;
					case Workload_2:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_2;
						}
						break;
					case Workload_3:
						if (baseState != ActiveMode)
						{
							STATE = ActiveMode;
							triggerStateAction(stateAction, baseState);
							STATE = Workload_3;
						}
						break;
				default:
					return;
				}
			break;
			default:
				break;
			}
		} // triggerStateAction()
		
	} // namespace machinecluster
} // namespace templateunit
/*********************************************************************
    End of cip process MachineProcess for PROCESS MachineProcess
*********************************************************************/
/* Actifsource ID=[1efc54ce-099f-11e3-b902-17aaca85d2fd,7270396a-9b54-11ef-800e-630ffd8f1eac,726fc458-9b54-11ef-800e-630ffd8f1eac,7270398d-9b54-11ef-800e-630ffd8f1eac,72703969-9b54-11ef-800e-630ffd8f1eac,72703968-9b54-11ef-800e-630ffd8f1eac,72701230-9b54-11ef-800e-630ffd8f1eac,727011f8-9b54-11ef-800e-630ffd8f1eac,43RauJyCQ0oYCTH5y4BkURsUqkU=] */
