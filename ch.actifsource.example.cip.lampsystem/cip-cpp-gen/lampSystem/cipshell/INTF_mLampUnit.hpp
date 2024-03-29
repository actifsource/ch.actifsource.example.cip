/*********************************************************************
	SYSTEM LampSystem
	IMPLEMENTATION LampImpl_cpp
	cip machine interface header file for CIP SHELL sLampUnit
	Filename: INTF_mLampUnit.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        call context error function
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_mLampUnit__)
    #define __INTF_mLampUnit__

#include "CREC_recType.hpp"
#include "INTF_usertypes.hpp"
#include "INTF_CipMachine.hpp"

namespace lampunit
{
	namespace cipshell
	{
        
		/** 
		* class INTF_mLampUnit
		* interface declaring input messages for cip machine
		*/
		class INTF_mLampUnit : 
			public ciplibrary::INTF_CipMachine
		{
		public: 
            
			/** constructors / destructors */
			INTF_mLampUnit(void){}
			virtual ~INTF_mLampUnit(void){}

			/** event message interface */
			/**
			* Triggers CIP Machine by input message Push (channel ButtonEvents).
			* @calls  ERR_CipError
			*/
			virtual void C1_Push(void) = 0;
            
			/**
			* Triggers CIP Machine by input message Release (channel ButtonEvents).
			* @calls  ERR_CipError
			*/
			virtual void C1_Release(void) = 0;
            
			/** 
			* global unit time
			*/
			unsigned long TIME;

		private: 
            
			/** prohibitted default functions */
			INTF_mLampUnit(const INTF_mLampUnit&);
			INTF_mLampUnit& operator=(const INTF_mLampUnit&);

		}; // class INTF_mLampUnit

	} // namespace cipshell
} // namespace lampunit

#endif // __INTF_mLampUnit__

/*********************************************************************
    End of cip machine interface header for CIP SHELL sLampUnit
*********************************************************************/
/* Actifsource ID=[6628a6cc-08f0-11e3-b902-17aaca85d2fd,242979e4-b786-11ea-9e22-1112d6355503,7848c6d5-b785-11ea-9e22-1112d6355503,06ed7fd9-b786-11ea-9e22-1112d6355503,242979e3-b786-11ea-9e22-1112d6355503,242979e2-b786-11ea-9e22-1112d6355503,wMdH5I2uP4RLCrQ0PeeFJ/aHs7I=] */
