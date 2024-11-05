/*********************************************************************
	SYSTEM TemplateSystem
	IMPLEMENTATION Template_cpp
	cip process ProcessFinalA names interface header file for PROCESS ProcessFinalA
	Filename: INTF_ProcessFinalANames.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        enable mode inspection
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_ProcessFinalANames__)
    #define __INTF_ProcessFinalANames__

namespace templateunit
{

	namespace clustera
	{
        
		/** 
		* class INTF_ProcessFinalANames
		* enumerations for process ProcessFinalA
		*/
		class INTF_ProcessFinalANames
		{
		public: 

			enum E_State
			{
				_no_state_ = 0,
				StateA_1 = 1,
				StateA_2 = 2,
				SuperStateA_1 = 3,
				SuperStateA_2 = 4
			};

			enum E_Mode
			{
				_no_mode_ = 0, 
				normalA = 1 
			};   

			enum E_Input
			{
				_no_input_ = 0, 
				ip_InpulseA = 1
			};

			enum E_Outpulse
			{
				_no_outpulse_ = 0,
				op_OutpulseA = 1
			};
     
			/** constructors / destructors */
			INTF_ProcessFinalANames(void){}
			virtual ~INTF_ProcessFinalANames(void){}

		private: 
            
			/** prohibitted default functions */
			INTF_ProcessFinalANames(const INTF_ProcessFinalANames&);
			INTF_ProcessFinalANames& operator=(const INTF_ProcessFinalANames&);

		}; // class INTF_ProcessFinalANames

	} // namespace clustera
} // namespace templateunit

#endif // __INTF_ProcessFinalANames__

/*********************************************************************
    End of cip process ProcessFinalA names interface header for PROCESS ProcessFinalA
*********************************************************************/
/* Actifsource ID=[fdad66a9-0975-11e3-b902-17aaca85d2fd,7270396a-9b54-11ef-800e-630ffd8f1eac,726fc458-9b54-11ef-800e-630ffd8f1eac,7270398d-9b54-11ef-800e-630ffd8f1eac,72703969-9b54-11ef-800e-630ffd8f1eac,72703968-9b54-11ef-800e-630ffd8f1eac,72701230-9b54-11ef-800e-630ffd8f1eac,7270120b-9b54-11ef-800e-630ffd8f1eac,Mt5a5JPBiAQMw+7Q0x7weyurIqY=] */
