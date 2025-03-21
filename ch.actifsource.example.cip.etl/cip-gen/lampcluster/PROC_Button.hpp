/*********************************************************************
	SYSTEM LampSystem_ETL based on etl statemachines
	IMPLEMENTATION LampImpl_c
	cip process Button header file for PROCESS Button
	Filename: PROC_Button.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/
#pragma once


#include "../cipshell/INTF_ActionMessagePort.hpp"
#include "../cipshell/CIPS_sLampUnit.hpp"
#include "../cipmachine/mLampUnit_Inputs.hpp" 
#include "../cipmachine/mLampUnit_Outputs.hpp"

// include etl libraries
#include "etl/message_packet.h"
#include "etl/hfsm.h"
#include "etl/queue.h"
#include "etl/delegate.h"
#include "etl/array.h"  
#include "etl/variant.h"

namespace lampunit::lampclustercluster
{
	
    /** 
    * class PROC_Button
    */
    class PROC_Button : public etl::hfsm
    {
    public:  

      using OutputCb = etl::delegate<void(etl::imessage& output)>;
      using OutpulsePacket = etl::message_packet<
              lampunit::cipmachine::mLampUnit_Outputs::Button_off_Pulse,
              lampunit::cipmachine::mLampUnit_Outputs::Button_on_Pulse>;
      
      /** Button states identifiers. **/
      struct StateId
      {
        /** Enumeration of all state identifiers */
        enum Type
        {
          released, // Init state
          pushed, 
          
          Number_Of_States,
          Undef
        };
      };
    
      // constructor
      explicit PROC_Button
      (
        etl::message_router_id_t routerid,
        lampunit::cipshell::INTF_ActionMessagePort& amp
      );

      // delete the copy members
      PROC_Button(const PROC_Button&) = delete;
      PROC_Button& operator=(const PROC_Button&) = delete;

      void Startup();
            
      void SetupOutput(OutputCb callback);
      void publishOutpulses();
      

 
    protected:

    private:   

      // Subclass for state  pushed
      class pushed: public etl::fsm_state
        <
          PROC_Button,
          pushed,
          StateId::pushed,
          lampunit::cipmachine::mLampUnit_Inputs::Button_Release_Message
        >
      {  
        public:
          etl::fsm_state_id_t on_event_unknown(const etl::imessage& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Button_Release_Message& msg);
      };

      // Subclass for state  released
      class released: public etl::fsm_state
        <
          PROC_Button,
          released,
          StateId::released,
          lampunit::cipmachine::mLampUnit_Inputs::Button_Push_Message
        >
      {  
        public:
          etl::fsm_state_id_t on_event_unknown(const etl::imessage& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Button_Push_Message& msg);
      };

      

      /** state classes */    
      pushed pushed{};  
      released released{};  
      
      /** Output callback */
      OutputCb m_outputCb {};
      
      PROC_Button& SELF;
      PROC_Button& STATUS;
      lampunit::cipshell::INTF_ActionMessagePort& m_amp;

      etl::queue<OutpulsePacket, 5> m_outpulseQueue;
      etl::optional<OutpulsePacket> m_outpulseStorage;
      
      /** last state */
      etl::fsm_state_id_t m_actualState {};

   };  
} // namespace lampunit::lampclustercluster

/* Actifsource ID=[cfa78def-cf03-11ee-91c0-c5a9ed07c9d7,d37d50e5-fb29-11ee-88af-c1ff99c74ce0,d37d50a8-fb29-11ee-88af-c1ff99c74ce0,e83fa4af-fb29-11ee-88af-c1ff99c74ce0,d37d50e4-fb29-11ee-88af-c1ff99c74ce0,d37d50e3-fb29-11ee-88af-c1ff99c74ce0,d37d50e2-fb29-11ee-88af-c1ff99c74ce0,d37d50bb-fb29-11ee-88af-c1ff99c74ce0,dRPQHIO8iB9hvPlXMY2c+g41Ays=] */
