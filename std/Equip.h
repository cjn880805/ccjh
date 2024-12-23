// Equip.h: interface for the CEquip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EQUIP_H__1B1EAB40_67C5_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_EQUIP_H__1B1EAB40_67C5_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

#define EQUIP_BEGIN(item_name)	class item_name : public CEquip	{	public:	item_name(){};	virtual ~item_name(){};
#define EQUIP_END		};	

//可装备之物品

class CEquip : public CItem  
{
public:
	virtual int Do_Action(int nAct, CChar * me = NULL);
	virtual LONG Query(int nAttr);
	virtual int Can_Equip(CChar * me);
	CEquip();
	virtual ~CEquip();
	
protected:
	int Do_UnWield();
	int Do_Wield();
};


#endif // !defined(AFX_EQUIP_H__1B1EAB40_67C5_11D4_98AB_0050BABC5212__INCLUDED_)
