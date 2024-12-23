// IKey_Baoxian.h: interface for the CIKey_Baoxian class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IKEY_BAOXIAN_H__0B9652A4_9398_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_IKEY_BAOXIAN_H__0B9652A4_9398_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

//Ô¿³×

class CIKey : public CItem  
{
public:
	virtual void create(int flag = 0);
	CIKey();
	virtual ~CIKey();

};

#endif // !defined(AFX_IKEY_BAOXIAN_H__0B9652A4_9398_11D4_98AB_0050BABC5212__INCLUDED_)
