/*********************************************************************
	SYSTEM HistorystateSystem
	IMPLEMENTATION Historystate_cpp
	abstract cip process header file for CIP MACHINE mHistorystateSUnit
	Filename: PROC_CipProcess.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__PROC_CipProcess__)
    #define __PROC_CipProcess__

#include "CIPS_sHistorystateSUnit.hpp"

namespace historystatesunit
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
			PROC_CipProcess(void){}
			virtual ~PROC_CipProcess(void){}
            
			/** extension input functions */
			virtual void TIMEUP_(void){}
			virtual void CHAIN_(void){}
			virtual void AUTO_(void){}
			virtual void READ_(void){}

		protected: 
            

		private: 
            
			/** prohibitted default functions */
			PROC_CipProcess(const PROC_CipProcess&);
			PROC_CipProcess& operator=(const PROC_CipProcess&);

		}; // class PROC_CipProcess

	} // namespace cipmachine
} // namespace historystatesunit

#endif // __PROC_CipProcess__

/*********************************************************************
    End of abstract cip process header for CIP MACHINE mHistorystateSUnit
*********************************************************************/
/* Actifsource ID=[5568d3bf-0beb-11e3-b115-a3f7f19b76fe,1d05cec7-9ac1-11ef-9dfa-835f60e5a95d,73ed890e-9ac0-11ef-9dfa-835f60e5a95d,f0198f93-9ac0-11ef-9dfa-835f60e5a95d,1d05cec6-9ac1-11ef-9dfa-835f60e5a95d,1d05cec5-9ac1-11ef-9dfa-835f60e5a95d,yyGSTVh6/08PDzM6USJzlTVJiyQ=] */