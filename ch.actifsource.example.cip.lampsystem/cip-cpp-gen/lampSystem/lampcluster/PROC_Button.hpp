/*********************************************************************
	SYSTEM LampSystem
	IMPLEMENTATION LampImpl_cpp
	cip process Button header file for PROCESS Button
	Filename: PROC_Button.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        call context error function
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__PROC_Button__)
    #define __PROC_Button__

#include "INTF_Button.hpp"
#include "INTF_ActionMessagePort.hpp"
#include "CIPS_sLampUnit.hpp"
#include "INTF_Constant.hpp"
#include "INTF_CipError.hpp"
#include "INTF_ButtonNames.hpp"
#include "INTF_ButtonStrings.hpp"
#include "INTF_CommonNames.hpp"
#include "INTF_CommonStrings.hpp"
#include "INTF_Lamp.hpp"

namespace lampunit
{

	namespace lampcluster
	{
	
		/** 
		* class PROC_Button
		* process Button class
		*/
		class PROC_Button : 
			public INTF_Button, 
			public INTF_ButtonNames, 
			public lampunit::cipshell::INTF_Constant
		{
		public: 
            
		/** constructors / destructors */
		PROC_Button(
			const char * i_processString,
			lampunit::cipshell::INTF_ActionMessagePort* i_amp,
			ciplibrary::INTF_CipError<char >* i_ciperror);
            
		virtual ~PROC_Button(void){}
  
		/** initialize the pointers to interaction processes */
		void initInteraction(
			void* i_Button,
			void* i_Lamp);

		/** INPORT EVENT_PORT */
		/** 
		* Trigger the process with message C1_Push
		* @calls  ERR_CipError  if the message has not been processed
		*/
		void C1_Push(void);
            
		/** 
		* Trigger the process with message C1_Release
		* @calls  ERR_CipError  if the message has not been processed
		*/
		void C1_Release(void);
            
		

	private: 

		/** prohibitted default functions */
		PROC_Button(const PROC_Button&);
		PROC_Button& operator=(const PROC_Button&);

		/** process member data */
		lampunit::cipshell::INTF_ActionMessagePort* m_ActionMessagePort; // action hadler for cip machine
		ciplibrary::INTF_CipError<char >* m_ciperror;
		PROC_Button& SELF; // own process instance cip macro for operations
		PROC_Button* Button; // own instance cip macro for inspections
		INTF_Button* STATUS; // status vector cip macro
		INTF_Lamp* Lamp; // process vector for pulse cast and inspections
		}; // class PROC_Button

	} // namespace lampcluster
} // namespace lampunit

#endif // __PROC_Button__

/*********************************************************************
    End of cip process Button header for PROCESS Button
*********************************************************************/
/* Actifsource ID=[45d0d2b1-099f-11e3-b902-17aaca85d2fd,242979e4-b786-11ea-9e22-1112d6355503,7848c6d5-b785-11ea-9e22-1112d6355503,06ed7fd9-b786-11ea-9e22-1112d6355503,242979e3-b786-11ea-9e22-1112d6355503,242979e2-b786-11ea-9e22-1112d6355503,7848c70f-b785-11ea-9e22-1112d6355503,7848c6e8-b785-11ea-9e22-1112d6355503,DOs+4NZwE22QIZPn+eohsteS/MM=] */
