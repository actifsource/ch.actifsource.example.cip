/*********************************************************************
	SYSTEM CIPLIBRARY
	gobal cip machine interface header file 
	Filename: INTF_CipMachine.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/
#pragma once

namespace ciplibrary
{
	
    /** 
    * class INTF_CipMachine
    * interface declaring common input messages for cip machine
    */
    class INTF_CipMachine
    {
      public: 
		
        /** consructors / destructors */
	virtual ~INTF_CipMachine(void){}

        /** extension interface */
		
        /** 
        * Triggers CIP Machine to increment time by one tick.
        */
        virtual void TICK_() = 0;
		
        /** 
        * Triggers CIP Machine to execute one pending internal activation.
        *  Search order: CHAIN_, TIMEUP_, READ_
        * @calls  ERR_CipError  --  for READ_ activation only
        */
        virtual void STEP_() = 0;
		
        /** 
        * Triggers CIP Machine to execute one pending timeup activation.
        */
        virtual void TIMEUP_() = 0;
		
        /** 
        * Triggers CIP Machine to execute one pending chain activation.
        */
        virtual void CHAIN_() = 0;
		
        /** 
        * Trigger CIP Machine to execute one internally buffered message.
        * @calls  ERR_CipError
        */
        virtual void READ_() = 0;
		
        /** 
        * Trigger CIP Machine to execute one AUTO_
        */
        virtual void AUTO_() = 0;

        /** 
        * Test if any local step activation is pending and return the result.
        * @return  if local step activation is pending.
        */
        virtual bool hasSTEP_() = 0;
		
        /** 
        * Test if a chain activation is pending and return the result.
        * @return  if a chain activation is pending.
        */
        virtual bool hasCHAIN_() = 0;
		
        /** 
        * Test if a timeup activation is pending and return the result.
        * @return  if a timeup activation is pending.
        */
        virtual bool hasTIMEUP_() = 0;
		
        /** 
        * Test if a read activation is pending and return the result.
        * @return  if a read activation is pending.
        */
        virtual bool hasREAD_() = 0;
		
        /** 
        * Test if an auto activation is pending and return the result.
        * @return  if a auto activation is pending.
        */
        virtual bool hasAUTO_() = 0;

	}; // class INTF_CipMachine

} // namespace ciplibrary

/* Actifsource ID=[cfa62ed3-cf03-11ee-91c0-c5a9ed07c9d7,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,Hash] */
