// Food.h: interface for the CFood class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOOD_H__F07D3541_7A8A_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_FOOD_H__F07D3541_7A8A_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

#define FOOD_BEGIN(item_name)	class item_name : public CFood	{	public:	item_name(){};	virtual ~item_name(){};
#define FOOD_END		};	

class CFood : public CItem  
{
public:
	virtual int do_use(CChar * me, CContainer * target);
	virtual int Can_Use();

	CFood();
	virtual ~CFood();

protected:
	virtual int finish_eat();
};

#endif // !defined(AFX_FOOD_H__F07D3541_7A8A_11D4_98AB_0050BABC5212__INCLUDED_)
