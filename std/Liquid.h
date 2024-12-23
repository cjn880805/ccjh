// Liquid.h: interface for the CLiquid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIQUID_H__7E70E360_BD39_11D4_98AC_0050BABC5212__INCLUDED_)
#define AFX_LIQUID_H__7E70E360_BD39_11D4_98AC_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

#define LIQUID_BEGIN(item_name)	class item_name : public CLiquid	{	public:	item_name(){};	virtual ~item_name(){};
#define LIQUID_END		};	


class CLiquid : public CItem  
{
public:
	char * extra_long();
	int do_fill(CChar * me);

	virtual int handle_action(char *comm, CChar *me, char * arg);
	virtual int do_use(CChar * me, CContainer * target);
	virtual int Can_Use();

	CLiquid();
	virtual ~CLiquid();

};

#endif // !defined(AFX_LIQUID_H__7E70E360_BD39_11D4_98AC_0050BABC5212__INCLUDED_)
