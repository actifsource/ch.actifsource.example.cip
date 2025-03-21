/*********************************************************************
	SYSTEM TemplateSystem
	IMPLEMENTATION Template_cpp
	cip process MachineProcess names interface header file for PROCESS MachineProcess
	Filename: INTF_MachineProcessNames.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        enable mode inspection
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_MachineProcessNames__)
    #define __INTF_MachineProcessNames__

namespace templateunit
{

	namespace machinecluster
	{
        
		/** 
		* class INTF_MachineProcessNames
		* enumerations for process MachineProcess
		*/
		class INTF_MachineProcessNames
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
				PowerOn_HistoryState = 0
			};
			
			enum E_Mode
			{
				_no_mode_ = 0, 
				normalA = 1 
			};   

			enum E_Input
			{
				_no_input_ = 0, 
				C1_doMachineStuff = 1,
				C1_nextWorkload = 2,
				C1_powerFail = 3,
				C1_powerOff = 4,
				C1_powerOn = 5,
				ip_InpulseA = 6
			};

			enum E_Outpulse
			{
				_no_outpulse_ = 0,
				op_OutpulseA = 1
			};
     
			enum E_StateAction
			{
				_no_stateAction_ = 0,
				EntryAction = 1,
				ExitAction = 2,
				EntryHistoryAction = 3
			};
			
			/** constructors / destructors */
			INTF_MachineProcessNames(void){}
			virtual ~INTF_MachineProcessNames(void){}

		private: 
            
			/** prohibitted default functions */
			INTF_MachineProcessNames(const INTF_MachineProcessNames&);
			INTF_MachineProcessNames& operator=(const INTF_MachineProcessNames&);

		}; // class INTF_MachineProcessNames

	} // namespace machinecluster
} // namespace templateunit

#endif // __INTF_MachineProcessNames__

/*********************************************************************
    End of cip process MachineProcess names interface header for PROCESS MachineProcess
*********************************************************************/
/* Actifsource ID=[fdad66a9-0975-11e3-b902-17aaca85d2fd,7270396a-9b54-11ef-800e-630ffd8f1eac,726fc458-9b54-11ef-800e-630ffd8f1eac,7270398d-9b54-11ef-800e-630ffd8f1eac,72703969-9b54-11ef-800e-630ffd8f1eac,72703968-9b54-11ef-800e-630ffd8f1eac,72701230-9b54-11ef-800e-630ffd8f1eac,727011f8-9b54-11ef-800e-630ffd8f1eac,ZZN2yr6Maw1+gyefxIxF0FXTuag=] */
