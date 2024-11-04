/*********************************************************************
	SYSTEM CIPLIBRARY
	cip error interface header file 
	Filename: INTF_CipError.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/

#pragma once

namespace ciplibrary
{
	
  /** 
  * class INTF_CipError
  * interface to cip error 
  */
  class INTF_ErrorHandler
  {
    public: 
		
      /** constructors / destructors */
      INTF_ErrorHandler(void){}
      virtual ~INTF_ErrorHandler(void){}

      /** Error call functions */
      virtual void handle_ContextError(int processId, int mode, int state, int message){};
      virtual void handle_OutpulseBufferError(int processId, int mode, int state, int message){};
      virtual void handle_OutmsgBufferError(int processId, int mode, int state, int message){};
		
    private: 
		
      /** prohibitted default functions */
      INTF_ErrorHandler(const INTF_ErrorHandler&);
      INTF_ErrorHandler& operator=(const INTF_ErrorHandler&);

  }; // class INTF_ErrorHandler

} // namespace ciplibrary


/*********************************************************************
	End of cip error interface header
*********************************************************************/
/* Actifsource ID=[4ae45ddd-ea99-11ee-a38e-eb0e43099461,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,Hash] */
