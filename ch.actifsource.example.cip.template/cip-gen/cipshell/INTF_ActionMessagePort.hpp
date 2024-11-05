/*********************************************************************
	SYSTEM TemplateSystem
	IMPLEMENTATION Template_cpp
	output interface header file for CIP SHELL sTemplateUnit
	Filename: INTF_ActionMessagePort.hpp
	generated by CIP Tool(R)
	
	activated code options:
		C++ code
		use message interface
	            naming option: channel  prefix
	        all types in shell
	        enable mode inspection
	        'unsigned long' for delays
*********************************************************************/

#if !defined(__INTF_ActionMessagePort__)
    #define __INTF_ActionMessagePort__


namespace templateunit
{
	namespace cipshell
	{
        

		/** 
		* class INTF_ActionMessagePort
		* interface declaring output messages of cip machine
		*/
		class INTF_ActionMessagePort
		{
		public: 
            
			/** consructors / destructors */
			INTF_ActionMessagePort(void){}
			virtual ~INTF_ActionMessagePort(void){}
			
			/** Action Message Interface */
			/**
			* Sent by CIP Machine on output of message powerFail (channel ActionA).
			*/
			virtual void f_C2_powerFail(void) = 0;
                        
			/**
			* Sent by CIP Machine on output of message powerOff (channel ActionA).
			*/
			virtual void f_C2_powerOff(void) = 0;
                        
			/**
			* Sent by CIP Machine on output of message powerOn (channel ActionA).
			*/
			virtual void f_C2_powerOn(void) = 0;
                        

		private: 
            
			/** prohibitted default functions */
			INTF_ActionMessagePort(const INTF_ActionMessagePort&);
			INTF_ActionMessagePort& operator=(const INTF_ActionMessagePort&);

		}; // class INTF_ActionMessagePort

    } // namespace cipshell
} // namespace templateunit

#endif // __INTF_ActionMessagePort__

/*********************************************************************
    End of output interface header for CIP SHELL sTemplateUnit
*********************************************************************/
/* Actifsource ID=[e6d848aa-08df-11e3-b902-17aaca85d2fd,7270396a-9b54-11ef-800e-630ffd8f1eac,726fc458-9b54-11ef-800e-630ffd8f1eac,7270398d-9b54-11ef-800e-630ffd8f1eac,72703969-9b54-11ef-800e-630ffd8f1eac,72703968-9b54-11ef-800e-630ffd8f1eac,c0Q61ZmyPvor/WxpczpT6heVnxI=] */
