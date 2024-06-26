/*********************************************************************
	SYSTEM CIPLIBRARY
	error handler interface header file 
	Filename: INTF_ErrorHandler.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/

#if !defined(__INTF_ErrorHandler__)
	#define __INTF_ErrorHandler__

#include "INTF_CipError.hpp"

namespace ciplibrary
{
	
	/** 
	 * class INTF_ErrorHandler
	 * interface to error handler
	 */
	
	template<class C >
	class INTF_ErrorHandler
	{
	public: 
		
		/** consructors / destructors */
		INTF_ErrorHandler(void){}
		virtual ~INTF_ErrorHandler(void){}

		
		/** Error handling functions */
		virtual void handle_ContextError(INTF_CipError<C >* i_error){}
		virtual void handle_BufferWarning(INTF_CipError<C >* i_error){}
		virtual void handle_BufferError(INTF_CipError<C >* i_error){}
		virtual void handle_PulseSelectionError(INTF_CipError<C >* i_error){}
		virtual void handle_MessageSelectionError(INTF_CipError<C >* i_error){}

	private: 
		
		/** prohibitted default functions */
		INTF_ErrorHandler(const INTF_ErrorHandler&);
		INTF_ErrorHandler& operator=(const INTF_ErrorHandler&);

	}; // class INTF_ErrorHandler

} // namespace ciplibrary

#endif // __INTF_ErrorHandler__

/*********************************************************************
	End of error handler interface header
*********************************************************************/
/* Actifsource ID=[a2a0ac5b-08ad-11e3-b902-17aaca85d2fd,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,yYMtXoP/i2hRZkxM7XyD2uWlKqc=] */
