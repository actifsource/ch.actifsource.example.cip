/*********************************************************************
	SYSTEM CIPLIBRARY
	cip auto header file 
	Filename: CipAuto.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/

#if !defined(__CipAuto__)
	#define __CipAuto__


namespace ciplibrary
{
	
	/** 
	 * class CipAuto
	 * auto element for auto queue
	 */
	
	template<class P >
	class CipAuto
	{
	public: 
		
		/** consructors / destructors */
		explicit CipAuto(P* i_process);
		CipAuto(void){}
		virtual ~CipAuto(void){}
		
		/** trigger the process with AUTO_ */
		void AUTO_(void);
		
		/** get the next CipAuto element in the queue. */
		CipAuto*& getNext(void) { return m_next; }


	private: 
		
		/** prohibitted default functions */
		CipAuto& operator=(const CipAuto&);

		
		/** member variables */
		P* m_process;
		CipAuto* m_next;

	}; // class CipAuto

/*********************************************************************
*********************************************************************/

	
	/** consructors / destructors */
	template<class P >
	CipAuto<P >::CipAuto(P* i_process) : 
		m_process(i_process), 
		m_next(0)
	{} // constructor()
	
	/** trigger the process with AUTO_ */
	template<class P >
	void CipAuto<P >::AUTO_(void)
	{
		m_process->AUTO_();
	} // AUTO_()

} // namespace ciplibrary

#endif // __CipAuto__

/*********************************************************************
	End of cip auto header
*********************************************************************/
/* Actifsource ID=[b11236a6-08aa-11e3-b902-17aaca85d2fd,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,KeYMR8pd1Hp89XoP93zS6ZdzSIM=] */