/*********************************************************************
	SYSTEM LampSystem_ETL
	IMPLEMENTATION LampImpl_c
	shell header file for CIP SHELL sLampUnit
	Filename: CIPS_sLampUnit.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/
#pragma once


// include etl libraries
#include "etl/message_packet.h"
#include "etl/hfsm.h"
#include "etl/queue.h"
#include "etl/delegate.h"
#include "etl/array.h"  
#include "etl/variant.h"

namespace lampunit::cipmachine
{	

class mLampUnit_Outputs
{

public:
  struct sLampUnit_OutPulseId
  {
    enum
    {
      BUTTON_OFF_PULSE,
      BUTTON_ON_PULSE,
    };
  };
  
  /*****************************
  * Outputs process 'LampCluster.Button'  
  *****************************/
  class Button_off_Pulse: public etl::message<sLampUnit_OutPulseId::BUTTON_OFF_PULSE>
  {
  };

  class Button_on_Pulse: public etl::message<sLampUnit_OutPulseId::BUTTON_ON_PULSE>
  {
  };

  /*****************************
  * Outputs process 'LampCluster.Lamp'  
  *****************************/
 
};

} // namespace lampunit::cipmachine

/* Actifsource ID=[cfa7b50e-cf03-11ee-91c0-c5a9ed07c9d7,d37d50e5-fb29-11ee-88af-c1ff99c74ce0,d37d50a8-fb29-11ee-88af-c1ff99c74ce0,e83fa4af-fb29-11ee-88af-c1ff99c74ce0,d37d50e4-fb29-11ee-88af-c1ff99c74ce0,d37d50e3-fb29-11ee-88af-c1ff99c74ce0,Hash] */