/*********************************************************************
	SYSTEM LampSystem_ETL based on etl statemachines
	IMPLEMENTATION LampImpl_c
	cip process Lamp header file for PROCESS Lamp
	Filename: PROC_Lamp.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/
#pragma once

#include "CipTimer.hpp"

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
    * class PROC_Lamp
    */
    class PROC_Lamp : public etl::hfsm
    {
    public:  

      using OutputCb = etl::delegate<void(etl::imessage& output)>;
      
      /** Lamp states identifiers. **/
      struct StateId
      {
        /** Enumeration of all state identifiers */
        enum Type
        {
          off_, // Init state
          delayed, 
          on_, 
          
          Number_Of_States,
          Undef
        };
      };
    
      // constructor
      explicit PROC_Lamp
      (
        etl::message_router_id_t routerid,
        lampunit::cipshell::INTF_ActionMessagePort& amp
      );

      // delete the copy members
      PROC_Lamp(const PROC_Lamp&) = delete;
      PROC_Lamp& operator=(const PROC_Lamp&) = delete;

      void Startup();
            
      void SetupOutput(OutputCb callback);
      void publishOutpulses();
      
      ciplibrary::CipTimer& getTimer();

 
    protected:

    private:   

      // Subclass for state  off_
      class off_: public etl::fsm_state
        <
          PROC_Lamp,
          off_,
          StateId::off_,
          lampunit::cipmachine::mLampUnit_Inputs::Lamp_on_Pulse
        >
      {  
        public:
          etl::fsm_state_id_t on_event_unknown(const etl::imessage& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Lamp_on_Pulse& msg);
      };

      // Subclass for state  on_
      class on_: public etl::fsm_state
        <
          PROC_Lamp,
          on_,
          StateId::on_,
          lampunit::cipmachine::mLampUnit_Inputs::Lamp_off_Pulse
        >
      {  
        public:
          etl::fsm_state_id_t on_event_unknown(const etl::imessage& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Lamp_off_Pulse& msg);
      };

      // Subclass for state  delayed
      class delayed: public etl::fsm_state
        <
          PROC_Lamp,
          delayed,
          StateId::delayed,
          lampunit::cipmachine::mLampUnit_Inputs::Lamp_on_Pulse,
          lampunit::cipmachine::mLampUnit_Inputs::Timeup_event
        >
      {  
        public:
          etl::fsm_state_id_t on_event_unknown(const etl::imessage& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Lamp_on_Pulse& msg);
          etl::fsm_state_id_t on_event(const lampunit::cipmachine::mLampUnit_Inputs::Timeup_event& msg);
      };

      /** timer functions */
      void setTimer(unsigned long delay);
      void stopTimer();
      

      /** state classes */    
      off_ off_{};  
      on_ on_{};  
      delayed delayed{};  
      
      /** Output callback */
      OutputCb m_outputCb {};
      
      PROC_Lamp& SELF;
      PROC_Lamp& STATUS;
      lampunit::cipshell::INTF_ActionMessagePort& m_amp;

      ciplibrary::CipTimer m_timer {};
      
      /** last state */
      etl::fsm_state_id_t m_actualState {};

   };  
} // namespace lampunit::lampclustercluster

/* Actifsource ID=[cfa78def-cf03-11ee-91c0-c5a9ed07c9d7,d37d50e5-fb29-11ee-88af-c1ff99c74ce0,d37d50a8-fb29-11ee-88af-c1ff99c74ce0,e83fa4af-fb29-11ee-88af-c1ff99c74ce0,d37d50e4-fb29-11ee-88af-c1ff99c74ce0,d37d50e3-fb29-11ee-88af-c1ff99c74ce0,d37d50e2-fb29-11ee-88af-c1ff99c74ce0,d37d50d8-fb29-11ee-88af-c1ff99c74ce0,uHGk/4mW6z3xHWbsUj7c7XEmNDA=] */
