/*********************************************************************
	SYSTEM CIPLIBRARY
	cip auto queue header file 
	Filename: CipAutoQueue.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/

#if !defined(__CipAutoQueue__)
	#define __CipAutoQueue__

#include "CipList.hpp"
#include "CipAuto.hpp"

namespace ciplibrary
{
	
	/** 
	 * class CipAutoQueue
	 * linked list with auto elements as fifo queue
	 */
	
	template<class P >
	class CipAutoQueue
	{
	public: 
		
		/** consructors / destructors */
		CipAutoQueue(void);
		virtual ~CipAutoQueue(void){}
		
		/** insert the auto element at the end of the queue. */
		void setAuto(CipAuto<P >* i_auto);
		
		/** trigger the process with AUTO_ */
		void AUTO_(void);
		
		/** remove the auto element from the queue. */
		void clearAuto(CipAuto<P >* i_auto);
		
		/** return whether any auto element is in the queue */
		bool hasAUTO_(void) const;

	private: 
		
		/** prohibitted default functions */
		CipAutoQueue(const CipAutoQueue&);
		CipAutoQueue& operator=(const CipAutoQueue&);

		
		/** member variables */
		CipList<CipAuto<P > > m_list;

	}; // class CipAutoQueue

/*********************************************************************
*********************************************************************/

	
	/** consructors / destructors */
	template<class P >
	CipAutoQueue<P >::CipAutoQueue(void) : 
		m_list(&CipAuto<P >::getNext)
	{} // constructor()
	
	/** insert the auto element at the end of the queue. */
	template<class P >
	void CipAutoQueue<P >::setAuto(CipAuto<P >* i_auto)
	{
		if (!m_list.empty())
		{
			m_list.remove(i_auto);
		}
		m_list.push_back(i_auto);
	} // setAuto()
	
	/** trigger the process with AUTO_ */
	template<class P >
	void CipAutoQueue<P >::AUTO_(void)
	{
		if (m_list.empty())
		{
			return;
		}
		m_list.pop_front()->AUTO_();
	} // AUTO_()
	
	/** remove the auto element from the queue. */
	template<class P >
	void CipAutoQueue<P >::clearAuto(CipAuto<P >* i_auto)
	{
		if (m_list.empty())
		{
			return;
		}
		m_list.remove(i_auto);
	} // clearAuto()
	
	/** return whether any auto element is in the queue */
	template<class P >
	bool CipAutoQueue<P >::hasAUTO_(void) const
	{
		return !m_list.empty();
	} // hasAUTO_()

} // namespace ciplibrary

#endif // __CipAutoQueue__

/*********************************************************************
	End of cip auto queue header
*********************************************************************/
/* Actifsource ID=[aa04119d-08ab-11e3-b902-17aaca85d2fd,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,bN8i2yEsXSU1u2ky+btkTppidvU=] */
