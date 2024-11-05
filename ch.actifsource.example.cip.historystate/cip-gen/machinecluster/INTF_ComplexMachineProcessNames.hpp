/*********************************************************************
	SYSTEM HistorystateSystem
	IMPLEMENTATION Historystate_cpp
	cip process ComplexMachineProcess names interface header file for PROCESS ComplexMachineProcess
	Filename: INTF_ComplexMachineProcessNames.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_ComplexMachineProcessNames__)
    #define __INTF_ComplexMachineProcessNames__

namespace historystatesunit
{

	namespace machinecluster
	{
        
		/** 
		* class INTF_ComplexMachineProcessNames
		* enumerations for process ComplexMachineProcess
		*/
		class INTF_ComplexMachineProcessNames
		{
		public: 

			enum E_State
			{
				_no_state_ = 0,
				ActiveMode = 1,
				Idle = 2,
				PowerOff = 3,
				PowerOn = 4,
				Workload_1 = 5,
				Workload_2 = 6,
				Workload_3 = 7
			};

			enum E_HistoryState
			{
				ActiveMode_HistoryState = 0,
				PowerOn_HistoryState = 1
			};
			

			enum E_Input
			{
				_no_input_ = 0, 
				C2_doMachineStuff = 1,
				C2_nextWorkload = 2,
				C2_powerFail = 3,
				C2_powerOff = 4,
				C2_powerOn = 5
			};

			enum E_Outpulse
			{
				_no_outpulse_ = 0
			};
     
			enum E_StateAction
			{
				_no_stateAction_ = 0,
				EntryAction = 1,
				ExitAction = 2,
				EntryHistoryAction = 3
			};
			
			/** constructors / destructors */
			INTF_ComplexMachineProcessNames(void){}
			virtual ~INTF_ComplexMachineProcessNames(void){}

		private: 
            
			/** prohibitted default functions */
			INTF_ComplexMachineProcessNames(const INTF_ComplexMachineProcessNames&);
			INTF_ComplexMachineProcessNames& operator=(const INTF_ComplexMachineProcessNames&);

		}; // class INTF_ComplexMachineProcessNames

	} // namespace machinecluster
} // namespace historystatesunit

#endif // __INTF_ComplexMachineProcessNames__

/*********************************************************************
    End of cip process ComplexMachineProcess names interface header for PROCESS ComplexMachineProcess
*********************************************************************/
/* Actifsource ID=[fdad66a9-0975-11e3-b902-17aaca85d2fd,1d05cec7-9ac1-11ef-9dfa-835f60e5a95d,73ed890e-9ac0-11ef-9dfa-835f60e5a95d,f0198f93-9ac0-11ef-9dfa-835f60e5a95d,1d05cec6-9ac1-11ef-9dfa-835f60e5a95d,1d05cec5-9ac1-11ef-9dfa-835f60e5a95d,3eff29c8-9ac1-11ef-9dfa-835f60e5a95d,0dca5d23-9ac7-11ef-9dfa-835f60e5a95d,y3esWlgqD9rA01f7VGFs+VQK5sk=] */