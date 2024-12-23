// Vendor.cpp: implementation of the CVendor class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#ifdef _NTOS_
#include "Money.h"
#else
#include "../std/Money.h"
#endif


#include "Vendor.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//标准类：商人
CVendor::CVendor()
{
	m_nGoodCode = 1;
	m_vendor_type = 0;
}

CVendor::~CVendor()
{
	DTGood * good;
	POSITION p;

	p = m_GoodList.GetHeadPosition();
	while(p)
	{
		good = m_GoodList.GetNext(p);
		delete good;
	}

	m_GoodList.RemoveAll();
}

LONG CVendor::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_VENDOR:
		return 1;
	}
	return CNpc::Query(nAttr);
}

int CVendor::Do_Action(int nAction, CChar * me)
{
	if(nAction == DO_LIST)
		return Do_List(me);

	return CNpc::Do_Action(nAction, me);
}

//显示商品清单 一页10个商品 页号从0开始
int CVendor::Do_List(CChar *me, int page)
{	
	char version[40];
	
	strncpy(version, me->querystr_temp("client/version"), 40);

	if( EQUALSTR(version, "文字1.90")
		|| EQUALSTR(version, "文字2.0") 
		|| EQUALSTR(version, "图形2.02") 
		|| version[0] == 'T'
		|| version[0] == 'W' )	
	{
		DTGood * good;
		POSITION p;
		int i = 0, nBegin = page * 10, nEnd = page * 10 + 10;
		CMapping m, line;

		p = m_GoodList.GetHeadPosition();
		int total = m_GoodList.GetCount() / 10;
		while(p)
		{
			good = m_GoodList.GetNext(p);
			if(i >= nBegin)
			{
				char cmd[20];

				line.set("good", snprintf(cmd, 20, "%ld", good->m_nCode));
				line.set("name", good->m_sName);
				line.set("value", snprintf(cmd, 20, "%ld", good->m_nValue * 6 / 5));
//				line.set("icon", snprintf(cmd, 20, "%ld", good->m_nIcon));
				line.set("amount", snprintf(cmd, 20, "%ld", good->m_nAmount));
//				line.set("long", good->m_long);

				sprintf(cmd, "%03d", i);
				m.set(cmd, line);
			}
			i++;
			if(i >= nEnd) break;
		}

		//page and total -> total * 10 + page 
		//the second param for vendor_type
		me->SendTable("vendor", &m, total * 10 + page, m_vendor_type);
		return 1;
	}
	else
	{
		DTGood * good;
		POSITION p;
		char sGood[80];
		char cmd[512];
		int i = 0, nBegin = page * 6, nEnd = page * 6 + 6;

		snprintf(cmd, 512, "&C=%d&P=%d&B=%d&", VENDOR_LIST, page, nBegin);
		p = m_GoodList.GetHeadPosition();
		while(p)
		{
			good = m_GoodList.GetNext(p);
			if(i >= nBegin)
			{
				snprintf(sGood, 80, "g%d=%ld&n%d=%s&b%d=%s&a%d=%ld&", 
					i, good->m_nCode, 
					i, good->m_sName,
					i, CMoney::Money_Str(good->m_nValue * 6 / 5),
					i, good->m_nAmount);
				strcat(cmd, sGood);
			}
			i++;
			if(i >= nEnd) break;
		}

		me->SendCommand(cmd, 1);
		return 1;
	}
}

//卖物品
int CVendor::Do_Sell(CChar * me, CContainer *obj)
{
	char msg[255];

	if(! obj) return 0;

	if(obj->query("no_sell"))
		return notify_fail("这样东西不能卖。");
	
	if (obj->Query(IS_MONEY))
	{
		tell_object(me, "你想卖「钱」？？");
		return 1;
	}

	if( obj->Query(CChar::IS_ITEM) && obj->Query_Amount() > 1)
	{
		obj = ((CItem *)obj)->Split(1);			
	}

	CMapping * m = obj->query_entire_dbase();
	if(! m->undefinedp("no_drop"))
		return notify_fail("这样东西不能卖。");
	
	if(! m->undefinedp("owner"))
		return notify_fail("这样东西不能卖。");
	
	//if (is_vendor_good(arg) != "") 
	//	return notify_fail("卖给你好不好？\n");

	if (obj->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。");
	
    LONG value = obj->query("value");
	if (value < 10)
		return notify_fail("%s一文不值！", obj->name());
	
	message_vision(snprintf(msg, 255, "$N卖掉了数量1的%s给$n。", obj->name()), me, this);
		
	CMoney::Pay_Player(me, value * 70 / 100);
//	if (value < 50)
		DESTRUCT_OB(obj, "CVendor::Do_Sell");
//	else
//	{
//		Add_Good(obj);
//	}
		
	return 1;
}

//买物品
int CVendor::Do_Buy(CChar *me, LONG nGood)
{	
	CContainer * obj;
	DTGood * good;
	char msg[255];
	int val_factor = 12;
	LONG money;
	int task = 0;
	
	if (! nGood) return 0;
	if(! (good = GetGood(nGood)) ) return 0;

	//增加对任务的判断
	if(good->m_basename == me->querystr("trade/obj")
		&& good->m_nIndx == me->query("trade/idx")
		&& ! me->query("trade/done") )
	{		
		money = me->query("trade/val");
		task = 1;
	}
	else 
		money = good->m_nValue *  val_factor / 10;

	if(! CMoney::Player_Pay(me, money) )
	{
		tell_object(me, "穷光蛋，一边呆着去！");
		return 1;
	}
	
	if(! (obj = load_item(good->m_basename.c_str())) ) return 0;
	if(good->m_nIndx) obj->create(good->m_nIndx);

	//此物品已卖光
	good->m_nAmount -- ;
	if(good->m_nAmount <= 0)
	{
		POSITION p;
		if( (p = m_GoodList.Find(good)) )
		{
			m_GoodList.RemoveAt(p);
			delete good;
		}
	}

	if(task)
	{
		message_vision(snprintf(msg, 255, "$HIC$N冲$n点头笑道：原是萧大人的货，这次可以优惠的卖给你，只收%ld金币。$COM", money), this, me);
		me->set("trade/done", 1);
	}

	message_vision(snprintf(msg, 255, "$N从$n那里买下了数量1的%s。", obj->name()), me, this );
	if( !obj->move(me))
	{
		obj->move(me->environment());
		tell_object(me, snprintf(msg, 255, "由于你负重不起，%s掉到了地上。", obj->name()));
	}	

	return 1;
}

//增加一个商品
void CVendor::Add_Good(CContainer * item, LONG nAmount)
{
	DTGood * good;
	LONG index;
	string basename;

	basename = item->querystr("base_name");
	index = item->query("index");
	if( ! (good = FindGood(basename, index)) )
	{
		good = new DTGood;
		m_GoodList.AddTail(good);
		strncpy(good->m_sName, item->name(), 40)[39] = 0;
		good->m_basename = basename;
		good->m_nIndx = index;
		good->m_nAmount = 0;
		good->m_nValue = item->query("value");
		good->m_nCode = m_nGoodCode ++;
	}
		
	good->m_nAmount+= nAmount;
	DESTRUCT_OB(item, "CVendor::Add_Good");
}

DTGood * CVendor::FindGood(string basename, int index)
{
	POSITION p;
	DTGood * good;

	p = m_GoodList.GetHeadPosition();
	while(p)
	{
		good = m_GoodList.GetNext(p);
		if(good->m_basename == basename && good->m_nIndx == index)
			return good;
	}
	
	return 0;
}

DTGood * CVendor::GetGood(LONG nGood)
{
	POSITION p;
	DTGood * good;

	p = m_GoodList.GetHeadPosition();
	while(p)
	{
		good = m_GoodList.GetNext(p);
		if(good->m_nCode == nGood)
			return good;
	}

	return 0;
}

//出售商品
void CVendor::carry_good(const char * good, LONG nAmount, int nIndex)
{
	CContainer * item = load_item(good);

	if(nIndex) item->create(nIndex);
	Add_Good(item, nAmount);
}

int CVendor::handle_action(char *comm, CChar *me, char *arg)
{
	char szGood[80], szPage[50];

	if(is_fighting()) return 0;
	strncpy(szGood, arg, 80);
	analyse_string(szGood, szPage, 50);

	if(strcmp(comm, "list") == 0)
	{
		return Do_List(me, atol(szGood));		//商品清单
	}
	else if(strcmp(comm, "buy") == 0)
	{
		if(Do_Buy(me, atol(szGood)))
		{
			snprintf(szGood, 80, "list %ld %s", object_id(), szPage);
			me->command(szGood);
			return 1;
		}
	}
	else if(strcmp(comm, "sell") == 0)
	{
		LONG nGood;
		CContainer * obj;

		nGood = atol(arg);
		obj = me->Present(nGood);
		if(Do_Sell(me, obj))
		{
			snprintf(szGood, 80, "list %ld %s", object_id(), szPage);
			me->command(szGood);
//			me->SendOff();
			return 1;
		}
	}
			
	return 0;
}
