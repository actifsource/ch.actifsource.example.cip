/*********************************************************************
	SYSTEM TemplateSystem
	IMPLEMENTATION Template_cpp
	cip machine interface header file for CIP SHELL sTemplateUnit
	Filename: INTF_mTemplateUnit.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        enable mode inspection
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_mTemplateUnit__)
    #define __INTF_mTemplateUnit__

#include "INTF_CipMachine.hpp"

namespace templateunit
{
	namespace cipshell
	{
        
		/** 
		* class INTF_mTemplateUnit
		* interface declaring input messages for cip machine
		*/
		class INTF_mTemplateUnit : 
			public ciplibrary::INTF_CipMachine
		{
		public: 
            
			/** constructors / destructors */
			INTF_mTemplateUnit(void){}
			virtual ~INTF_mTemplateUnit(void){}

			/** event message interface */
			/**
			* Triggers CIP Machine by input message doMachineStuff (channel EventA).
			*/
			virtual void C1_doMachineStuff(void) = 0;
            
			/**
			* Triggers CIP Machine by input message nextWorkload (channel EventA).
			*/
			virtual void C1_nextWorkload(void) = 0;
            
			/**
			* Triggers CIP Machine by input message powerFail (channel EventA).
			*/
			virtual void C1_powerFail(void) = 0;
            
			/**
			* Triggers CIP Machine by input message powerOff (channel EventA).
			*/
			virtual void C1_powerOff(void) = 0;
            
			/**
			* Triggers CIP Machine by input message powerOn (channel EventA).
			*/
			virtual void C1_powerOn(void) = 0;
            
			/** 
			* global unit time
			*/
			unsigned long TIME;

		private: 
            
			/** prohibitted default functions */
			INTF_mTemplateUnit(const INTF_mTemplateUnit&);
			INTF_mTemplateUnit& operator=(const INTF_mTemplateUnit&);

		}; // class INTF_mTemplateUnit

	} // namespace cipshell
} // namespace templateunit

#endif // __INTF_mTemplateUnit__

/*********************************************************************
    End of cip machine interface header for CIP SHELL sTemplateUnit
*********************************************************************/
/* Actifsource ID=[6628a6cc-08f0-11e3-b902-17aaca85d2fd,7270396a-9b54-11ef-800e-630ffd8f1eac,726fc458-9b54-11ef-800e-630ffd8f1eac,7270398d-9b54-11ef-800e-630ffd8f1eac,72703969-9b54-11ef-800e-630ffd8f1eac,72703968-9b54-11ef-800e-630ffd8f1eac,+b9pYFgdJRALmy2hbLRArdUfS/g=] */