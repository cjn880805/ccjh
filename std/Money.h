// Money.h: interface for the CMoney class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONEY_H__822A3741_6889_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_MONEY_H__822A3741_6889_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

//Money是自动合并的物件。即，在一个物件身上，不会同时存在两个它的实例。
//在Room里除外。
class CMoney : public CItem  
{
public:
	virtual int query_autoload() { return 1; };
	static char * Money_Str(LONG amount);
	static int Player_Pay(CChar * me, LONG nValue);
	static int Pay_Player(CChar * me, LONG nValue);
	virtual LONG Query(int nAttr);
	virtual int move(CContainer * pMe);
	CMoney();
	virtual ~CMoney();

};

#endif // !defined(AFX_MONEY_H__822A3741_6889_11D4_98AB_0050BABC5212__INCLUDED_)
