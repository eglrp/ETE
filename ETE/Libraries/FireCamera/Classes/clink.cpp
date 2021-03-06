////////////////////////////////////////////////////////////////////////////////
// Module for cplusplus link utility.
// intek, C. Kuehnel, 5.12.2002
////////////////////////////////////////////////////////////////////////////////

#include <clink.h>

#ifndef NULL
 #define NULL    ((void*)0)
#endif

////////////////////////////////////////////////////////////////////////////////
// Routines for CLink - Constructor.
////////////////////////////////////////////////////////////////////////////////

CLink::CLink()
{
  m_pNext=m_pPrev=this;
}

////////////////////////////////////////////////////////////////////////////////
// Destructor.

CLink::~CLink()
{
}

////////////////////////////////////////////////////////////////////////////////
// Init element.

void CLink::Init()
{
  m_pNext=m_pPrev=this;
}

////////////////////////////////////////////////////////////////////////////////
// Get first element of a base (this is our base).

CLink* CLink::First()
{
  if(m_pNext==this)
   return (CLink*)NULL;

  return m_pNext;
}

////////////////////////////////////////////////////////////////////////////////
// Get last element of a base (this is our base).

CLink* CLink::Last()
{
  if(m_pPrev==this)
   return (CLink*)NULL;

  return m_pPrev;
}

////////////////////////////////////////////////////////////////////////////////
// Get next element of a base (this is our base).

CLink* CLink::Next(CLink *pActual)
{
  if(!pActual)
   return First();

  if(pActual->m_pNext==this)
   return (CLink*)NULL;

  return pActual->m_pNext;
}

////////////////////////////////////////////////////////////////////////////////
// Get previous element of a base (this is our base).

CLink* CLink::Prev(CLink *pActual)
{
  if(!pActual)
   return Last();

  if(pActual->m_pPrev==this)
   return (CLink*)NULL;

  return pActual->m_pPrev;
}

////////////////////////////////////////////////////////////////////////////////
// Get first element of a base and unlink if valid.

CLink* CLink::FirstAndUnlink()
{
  CLink *pObj;

  if((pObj=m_pNext)==this)
   return (CLink*)NULL;

  pObj->Unlink();

  return pObj;
}

////////////////////////////////////////////////////////////////////////////////
// Link this after specified object.

void CLink::LinkAfter(CLink *pPrev)
{
  m_pNext=pPrev->m_pNext;
  m_pPrev=pPrev;
  m_pPrev->m_pNext=m_pNext->m_pPrev=this;
}

////////////////////////////////////////////////////////////////////////////////
// Link this before specified object.

void CLink::LinkBefore(CLink *pNext)
{
  m_pPrev=pNext->m_pPrev;
  m_pNext=pNext;
  m_pNext->m_pPrev=m_pPrev->m_pNext=this;
}

////////////////////////////////////////////////////////////////////////////////
// Unlink.

void CLink::Unlink()
{
  m_pPrev->m_pNext=m_pNext;
  m_pNext->m_pPrev=m_pPrev;
  m_pNext=m_pPrev=this;
}

