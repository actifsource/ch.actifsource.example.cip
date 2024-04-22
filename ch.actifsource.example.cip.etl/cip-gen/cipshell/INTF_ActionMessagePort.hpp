/*********************************************************************
	SYSTEM LampSystem_ETL
	IMPLEMENTATION LampImpl_c
	output interface header file for CIP SHELL sLampUnit
	Filename: INTF_ActionMessagePort.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        'unsigned long' for delays
*********************************************************************/
#pragma once


namespace lampunit::cipshell
{
        

    /** 
    * class INTF_ActionMessagePort
    * interface declaring output messages of cip machine
    */
    class INTF_ActionMessagePort
    {
      public: 
            
        /** consructors / destructors */
        INTF_ActionMessagePort(){}
        virtual ~INTF_ActionMessagePort(){}
			
        /** Action Message Interface */
        /**
        * Sent by CIP Machine on output of message Bright (channel LampActions).
        */
        virtual void f_C2_Bright() = 0;
                        
        /**
        * Sent by CIP Machine on output of message Dark (channel LampActions).
        */
        virtual void f_C2_Dark() = 0;
                        

     private: 
            
       /** prohibitted default functions */
       INTF_ActionMessagePort(const INTF_ActionMessagePort&);
       INTF_ActionMessagePort& operator=(const INTF_ActionMessagePort&);
    
    }; // class INTF_ActionMessagePort

} // namespace lampunit::cipshell

/* Actifsource ID=[cfa60a15-cf03-11ee-91c0-c5a9ed07c9d7,d37d50e5-fb29-11ee-88af-c1ff99c74ce0,d37d50a8-fb29-11ee-88af-c1ff99c74ce0,e83fa4af-fb29-11ee-88af-c1ff99c74ce0,d37d50e4-fb29-11ee-88af-c1ff99c74ce0,d37d50e3-fb29-11ee-88af-c1ff99c74ce0,Hash] */