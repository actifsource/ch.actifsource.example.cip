/*********************************************************************
	SYSTEM CIPLIBRARY
	cip timer header file 
	Filename: CipAuto.hpp
	generated by CIP Tool(R)
	activated code options:
		C++ code
*********************************************************************/
#pragma once

namespace ciplibrary
{
	
/** 
 * class CipAuto
 */
class CipAuto
{
public: 
  
  void setAuto()
  {
    m_auto_pending = true;
  }
  
  bool hasAUTO_()
  {
    return m_auto_pending;    
  }
  
  void clearAUTO_()
  {
    m_auto_pending = false;
  }
  
private:
  
  bool m_auto_pending { false };
  
};  
  
} // namespace ciplibrary

/* Actifsource ID=[26d1c475-db03-11ee-84fb-cb96c06bbf07,a6d1b8c9-cedd-11de-80c2-87ac3b08f930,ZFv4fgm6kRHhSt2SP3RhoeqYjqo=] */
