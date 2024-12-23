// writen by HuaKua-Wang
// Email: huakui@china.com
#ifndef LIST_H
#define LIST_H

#include <assert.h>
#include "plex.h"

typedef struct __POSITION{}* POSITION;
typedef unsigned int UINT;
typedef unsigned char BYTE;
typedef UINT BOOL;

template<class TYPE, class ARG_TYPE>
class CList
{
protected:
  struct CNode
  {
    CNode * pNext;
    CNode * pPrev;
    TYPE data;
  };
public:
  //Construction
  CList(int nBlockSize = 10);

  //Attributes (head and tail)
  //count of elements
  int GetCount() const;
  BOOL IsEmpty() const;

  // peek at head or tail
  TYPE& GetHead();
  TYPE GetHead() const;
  TYPE& GetTail();
  TYPE GetTail() const;

  // iteration
  POSITION GetHeadPosition() const;
  POSITION GetTailPosition() const;
  TYPE& GetNext(POSITION& rPosition); // return *Position++
  TYPE GetNext(POSITION& rPosition) const; // return *Position++
  TYPE& GetPrev(POSITION& rPosition); // return *Position--
  TYPE GetPrev(POSITION& rPosition) const; // return *Position--

  // getting/modifying an element at a given position
  TYPE& GetAt(POSITION position);
  TYPE GetAt(POSITION position) const;
  void SetAt(POSITION pos, ARG_TYPE newElement);

  //
  POSITION AddHead(ARG_TYPE newElement);
  POSITION AddTail(ARG_TYPE newElement);

  // add another list of elements before head or after tail
  void AddHead(CList* pNewList);
  void AddTail(CList* pNewList);

  // get head or tail(and remove it) - don't call on empty list!
  TYPE RemoveHead();
  TYPE RemoveTail();

  void RemoveAt(POSITION position);
  void RemoveAll();

  // inserting before or after a given position
  POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
  POSITION InsertAfter(POSITION position, ARG_TYPE newElement);

  // helper functions (note: 0(n) speed)
  POSITION Find(ARG_TYPE searchValue, POSITION startAfter = 0) const;
  POSITION FindIndex(int nIndex) const;
  // get the 'nIndex'th element (may return 0)

 ~CList();
protected:
  CNode* m_pNodeHead;
  CNode* m_pNodeTail;
  int m_nCount;
  CNode* m_pNodeFree;
  struct CPlex* m_pBlocks;
  int m_nBlockSize;

  CNode* NewNode(CNode*, CNode*);
  void FreeNode(CNode*);
};

template<class TYPE, class ARG_TYPE>
int CList<TYPE, ARG_TYPE>::GetCount() const
	{ return m_nCount; }
template<class TYPE, class ARG_TYPE>
BOOL CList<TYPE, ARG_TYPE>::IsEmpty() const
	{ return m_nCount == 0; }
template<class TYPE, class ARG_TYPE>
TYPE& CList<TYPE, ARG_TYPE>::GetHead()
	{ assert(m_pNodeHead != 0);
		return m_pNodeHead->data; }
template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::GetHead() const
	{ assert(m_pNodeHead != 0);
		return m_pNodeHead->data; }
template<class TYPE, class ARG_TYPE>
TYPE& CList<TYPE, ARG_TYPE>::GetTail()
	{ assert(m_pNodeTail != 0);
		return m_pNodeTail->data; }
template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::GetTail() const
	{ assert(m_pNodeTail != 0);
		return m_pNodeTail->data; }
template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::GetHeadPosition() const
	{ return (POSITION) m_pNodeHead; }
template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::GetTailPosition() const
	{ return (POSITION) m_pNodeTail; }
template<class TYPE, class ARG_TYPE>
TYPE& CList<TYPE, ARG_TYPE>::GetNext(POSITION& rPosition) // return *Position++
	{ CNode* pNode = (CNode*) rPosition;
		rPosition = (POSITION) pNode->pNext;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::GetNext(POSITION& rPosition) const // return *Position++
	{ CNode* pNode = (CNode*) rPosition;
		rPosition = (POSITION) pNode->pNext;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
TYPE& CList<TYPE, ARG_TYPE>::GetPrev(POSITION& rPosition) // return *Position--
	{ CNode* pNode = (CNode*) rPosition;
		rPosition = (POSITION) pNode->pPrev;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::GetPrev(POSITION& rPosition) const // return *Position--
	{ CNode* pNode = (CNode*) rPosition;
		rPosition = (POSITION) pNode->pPrev;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
TYPE& CList<TYPE, ARG_TYPE>::GetAt(POSITION position)
	{ CNode* pNode = (CNode*) position;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::GetAt(POSITION position) const
	{ CNode* pNode = (CNode*) position;
		return pNode->data; }
template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::SetAt(POSITION pos, ARG_TYPE newElement)
	{ CNode* pNode = (CNode*) pos;
		pNode->data = newElement; }

template<class TYPE, class ARG_TYPE>
CList<TYPE, ARG_TYPE>::CList(int nBlockSize)
{
  assert(nBlockSize > 0);
  m_nCount = 0;
  m_pNodeHead = m_pNodeTail = m_pNodeFree = 0;
  m_pBlocks = 0;
  m_nBlockSize = nBlockSize;
}

template<class TYPE, class ARG_TYPE>
CList<TYPE, ARG_TYPE>::~CList()
{
  RemoveAll();
  assert(m_nCount == 0);
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::AddHead(ARG_TYPE newElement)
{
  assert(this != 0);
  CNode* pNewNode = NewNode(0, m_pNodeHead);
  pNewNode->data = newElement;
  if (m_pNodeHead != 0)
    m_pNodeHead->pPrev = pNewNode;
  else
    m_pNodeTail = pNewNode;
  m_pNodeHead = pNewNode;
  return (POSITION) pNewNode;
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::AddTail(ARG_TYPE newElement)
{
  assert(this != 0);
  CNode* pNewNode = NewNode(m_pNodeTail, 0);
  pNewNode->data = newElement;
  if (m_pNodeTail != 0)
    m_pNodeTail->pNext = pNewNode;
  else
    m_pNodeHead = pNewNode;
  m_pNodeTail = pNewNode;
  return (POSITION) pNewNode;
}

template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::AddHead(CList* pNewList)
{
	assert(this != 0);
	assert(pNewList != 0);

	// add a list of same elements to head (maintain order)
	POSITION pos = pNewList->GetTailPosition();
	while (pos != 0)
		AddHead(pNewList->GetPrev(pos));
}

template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::AddTail(CList* pNewList)
{
	assert(this != 0);
	assert(pNewList != 0);
		
	// add a list of same elements
	POSITION pos = pNewList->GetHeadPosition();
	while (pos != 0)
		AddTail(pNewList->GetNext(pos));
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::InsertBefore(POSITION position, ARG_TYPE newElement)
{
	assert(this != 0);
	if (position == 0)
		return AddHead(newElement); // insert before nothing -> head of the list

	// Insert it before position
	CNode* pOldNode = (CNode*) position;
	CNode* pNewNode = NewNode(pOldNode->pPrev, pOldNode);
	pNewNode->data = newElement;

	if (pOldNode->pPrev != 0)
	{
		pOldNode->pPrev->pNext = pNewNode;
	}
	else
	{
		assert(pOldNode == m_pNodeHead);
		m_pNodeHead = pNewNode;
	}
	pOldNode->pPrev = pNewNode;
	return (POSITION) pNewNode;
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::InsertAfter(POSITION position, ARG_TYPE newElement)
{
	assert(this != 0);

	if (position == 0)
		return AddTail(newElement); // insert after nothing -> tail of the list

	// Insert it before position
	CNode* pOldNode = (CNode*) position;
	CNode* pNewNode = NewNode(pOldNode, pOldNode->pNext);
	pNewNode->data = newElement;

	if (pOldNode->pNext != 0)
	{
		pOldNode->pNext->pPrev = pNewNode;
	}
	else
	{
		assert(pOldNode == m_pNodeTail);
		m_pNodeTail = pNewNode;
	}
	pOldNode->pNext = pNewNode;
	return (POSITION) pNewNode;
}

template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::RemoveHead()
{
	assert(this != 0);
	assert(m_pNodeHead != 0);  // don't call on empty list !!!

	CNode* pOldNode = m_pNodeHead;
	TYPE returnValue = pOldNode->data;

	m_pNodeHead = pOldNode->pNext;
	if (m_pNodeHead != 0)
		m_pNodeHead->pPrev = 0;
	else
		m_pNodeTail = 0;
	FreeNode(pOldNode);
	return returnValue;
}

template<class TYPE, class ARG_TYPE>
TYPE CList<TYPE, ARG_TYPE>::RemoveTail()
{
	assert(this != 0);
	assert(m_pNodeTail != 0);  // don't call on empty list !!!

	CNode* pOldNode = m_pNodeTail;
	TYPE returnValue = pOldNode->data;

	m_pNodeTail = pOldNode->pPrev;
	if (m_pNodeTail != 0)
		m_pNodeTail->pNext = 0;
	else
		m_pNodeHead = 0;
	FreeNode(pOldNode);
	return returnValue;
}

template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::RemoveAt(POSITION position)
{
	assert(this != 0);

	CNode* pOldNode = (CNode*) position;

	// remove pOldNode from list
	if (pOldNode == m_pNodeHead)
	{
		m_pNodeHead = pOldNode->pNext;
	}
	else
	{
		pOldNode->pPrev->pNext = pOldNode->pNext;
	}
	if (pOldNode == m_pNodeTail)
	{
		m_pNodeTail = pOldNode->pPrev;
	}
	else
	{
		pOldNode->pNext->pPrev = pOldNode->pPrev;
	}
	FreeNode(pOldNode);
}

template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::RemoveAll()
{
	assert(this != 0);

	m_nCount = 0;
	m_pNodeHead = m_pNodeTail = m_pNodeFree = 0;
	m_pBlocks->FreeDataChain();
	m_pBlocks = 0;
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::FindIndex(int nIndex) const
{
	assert(this != 0);

	if (nIndex >= m_nCount || nIndex < 0)
		return 0;  // went too far

	CNode* pNode = m_pNodeHead;
	while (nIndex--)
	{
		pNode = pNode->pNext;
	}
	return (POSITION) pNode;
}

template<class TYPE, class ARG_TYPE>
POSITION CList<TYPE, ARG_TYPE>::Find(ARG_TYPE searchValue, POSITION startAfter) const
{
	assert(this != 0);

	CNode* pNode = m_pNodeHead;
	while(pNode)
	{
		if(pNode->data == searchValue)
			break;
			
		pNode = pNode->pNext;
	}
	return (POSITION) pNode;
}

template<class TYPE, class ARG_TYPE>
typename CList<TYPE, ARG_TYPE>::CNode*
CList<TYPE, ARG_TYPE>::NewNode(CList::CNode* pPrev, CList::CNode* pNext)
{
	if (m_pNodeFree == 0)
	{
		// add another block
		CPlex* pNewBlock = CPlex::Create(m_pBlocks, m_nBlockSize,
				 sizeof(CNode));

		// chain them into free list
		CNode* pNode = (CNode*) pNewBlock->data();
		// free in reverse order to make it easier to debug
		pNode += m_nBlockSize - 1;
		for (int i = m_nBlockSize-1; i >= 0; i--, pNode--)
		{
			pNode->pNext = m_pNodeFree;
			m_pNodeFree = pNode;
		}
	}
	assert(m_pNodeFree != 0);  // we must have something

	CList::CNode* pNode = m_pNodeFree;
	m_pNodeFree = m_pNodeFree->pNext;
	pNode->pPrev = pPrev;
	pNode->pNext = pNext;
	m_nCount++;
	assert(m_nCount > 0);  // make sure we don't overflow
	
	pNode->data = 0;

	return pNode;
}

template<class TYPE, class ARG_TYPE>
void CList<TYPE, ARG_TYPE>::FreeNode(CList::CNode* pNode)
{
	pNode->pNext = m_pNodeFree;
	m_pNodeFree = pNode;
	m_nCount--;
	assert(m_nCount >= 0);  // make sure we don't underflow

	// if no more elements, cleanup completely
	if (m_nCount == 0)
		RemoveAll();
}

#endif
