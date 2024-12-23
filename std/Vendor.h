// Vendor.h: interface for the CVendor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VENDOR_H__162AF6C0_8A9D_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_VENDOR_H__162AF6C0_8A9D_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Npc.h"

#define VENDOR_BEGIN(npc_name) class npc_name : public CVendor	{	public:	npc_name(){};	virtual ~npc_name(){};	
#define VENDOR_END		};	


typedef struct {
	LONG	m_nCode;
	char	m_sName[40];		//名称
	string	m_basename;			//物件类
	int		m_nIndx;			//类内索引
	LONG	m_nAmount;			//数量
	LONG	m_nValue;			//价值
}DTGood;

typedef CList <DTGood *, DTGood *> DTGOODLIST;

class CVendor : public CNpc  
{
public:
	void carry_good(const char * good, LONG nAmount = 1, int index = 0);
	virtual int handle_action(char *comm, CChar *me, char *arg);
	int Do_Buy(CChar * me, LONG nObj);
	int Do_Sell(CChar * me, CContainer * obj);
	int Do_List(CChar * me, int page = 0);
	virtual int Do_Action(int nAction, CChar * me= NULL);
	virtual LONG Query(int nAttr);
	CVendor();
	virtual ~CVendor();

protected:	//商人，买卖物品。
	DTGood * GetGood(LONG nGood);
	DTGood * FindGood(string basename, int index = 0);
	void Add_Good(CContainer * good, LONG nAmount = 1);
	DTGOODLIST	m_GoodList;			//商品列表
	LONG m_nGoodCode;				//商品编码

	int		m_vendor_type;
	
};

#endif // !defined(AFX_VENDOR_H__162AF6C0_8A9D_11D4_98AB_0050BABC5212__INCLUDED_)
