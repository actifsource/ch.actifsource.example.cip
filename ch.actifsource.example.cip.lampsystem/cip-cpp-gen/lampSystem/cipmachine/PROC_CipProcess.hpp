/*********************************************************************
	SYSTEM LampSystem
	IMPLEMENTATION LampImpl_cpp
	abstract cip process header file for CIP MACHINE mLampUnit
	Filename: PROC_CipProcess.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        call context error function
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__PROC_CipProcess__)
    #define __PROC_CipProcess__

#include "CIPS_sLampUnit.hpp"
#include <iostream>

namespace lampunit
{
	namespace cipmachine
	{
        
		/** 
		* class PROC_CipProcess
		* common superclass for CIP Processes
		*/
		class PROC_CipProcess
		{
		public: 
            
			/** consructors / destructors */
			explicit PROC_CipProcess(const char *i_processString);
			PROC_CipProcess(void){}
			virtual ~PROC_CipProcess(void){}
            
			/** extension input functions */
			virtual void TIMEUP_(void){}
			virtual void CHAIN_(void){}
			virtual void AUTO_(void){}
			virtual void READ_(void){}

		protected: 
            
			/** Trace functions */
			virtual void resetStrings(void);
			char m_processString[18];
			char *m_modeString;
			char *m_stateString;
			char *m_inputString;
			char *m_outpulseString;

		private: 
            
			/** prohibitted default functions */
			PROC_CipProcess(const PROC_CipProcess&);
			PROC_CipProcess& operator=(const PROC_CipProcess&);

		}; // class PROC_CipProcess

	} // namespace cipmachine
} // namespace lampunit

#endif // __PROC_CipProcess__

/*********************************************************************
    End of abstract cip process header for CIP MACHINE mLampUnit
*********************************************************************/
/* Actifsource ID=[5568d3bf-0beb-11e3-b115-a3f7f19b76fe,242979e4-b786-11ea-9e22-1112d6355503,7848c6d5-b785-11ea-9e22-1112d6355503,06ed7fd9-b786-11ea-9e22-1112d6355503,242979e3-b786-11ea-9e22-1112d6355503,242979e2-b786-11ea-9e22-1112d6355503,IfXV5z/a5U5ENpj6rFd2+Hm6LWc=] */
