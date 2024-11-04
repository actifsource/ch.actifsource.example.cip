/*********************************************************************
	SYSTEM CIPLIBRARY
	cip read queue header file 
	Filename: CipReadQueue.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/

#if !defined(__CipReadQueue__)
	#define __CipReadQueue__

#include "RingBuffer.hpp"
#include "CipRead.hpp"

namespace ciplibrary
{
	
	/** 
	 * class CipReadQueue
	 * ring buffer as fifo queue with predefined size, holding CipRead elements.
	 * @template R   type of queue elements (CipRead).
	 * @template E   type of cip error (INTF_CipError).
	 */
	template<class R, class E >
	class CipReadQueue
	{
	public: 
		
		/** consructors / destructors */
		
		/** 
		 * Consructor
		 * The number of elements in the queue is statically defined in the CIP specification
		 * @param i_size number of queue elements
		 * @param i_error needed for buffer warning notification.
		 */
		explicit CipReadQueue(const unsigned int i_size = 1, E* i_error = 0);


		virtual ~CipReadQueue(void){ delete m_buffer; }

		
		/** trigger the process with READ_ */
		void READ_(void);
		
		/** member access functions */
		/** return the next free read element or null. */
		R* getNext(void);
		
		/** pop and return the oldest read element in the queue. */
		R* getHead(void);
		
		/** return whether any read element is in the queue */
		bool hasREAD_(void) const;

	private: 
		
		/** prohibitted default functions */
		CipReadQueue(const CipReadQueue&);
		CipReadQueue& operator=(const CipReadQueue&);

		
		/** member variables */
		RingBuffer<R, E >* m_buffer;

	}; // class CipReadQueue

/*********************************************************************
*********************************************************************/


	template<class R, class E >
	CipReadQueue<R, E >::CipReadQueue(const unsigned int i_size, E* i_error)  : 
		m_buffer(new RingBuffer<R, E >(i_size, i_error))
	{}

	
	/** trigger the process with READ_ */
	template<class R, class E >
	void CipReadQueue<R, E >::READ_(void)
	{
		if (m_buffer->empty())
		{
			return;
		}
		m_buffer->getHead()->READ_();
	} // READ_()
	
	/** member access functions */
	/** return the next free read element or null. */
	template<class R, class E >
	R* CipReadQueue<R, E >::getNext(void)
	{
		return m_buffer->getNext();
	} // getNext()
	
	/** pop and return the oldest read element in the queue. */
	template<class R, class E >
	R* CipReadQueue<R, E >::getHead(void)
	{
		return m_buffer->popHead();
	} // getHead()
	
	/** return whether any read element is in the queue */
	template<class R, class E >
	bool CipReadQueue<R, E >::hasREAD_(void) const
	{
		return !m_buffer->empty();
	} // hasREAD_()

} // namespace ciplibrary

#endif // __CipReadQueue__

/*********************************************************************
	End of cip read queue header
*********************************************************************/
/* Actifsource ID=[9deba546-08ac-11e3-b902-17aaca85d2fd,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,6UVgX9S02o9R1hCNiZFPSOX/8WM=] */