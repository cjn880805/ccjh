// Money.cpp: implementation of the CMoney class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "../server/Char.h"
#include "Money.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMoney::CMoney()
{
}

CMoney::~CMoney()
{

}

//重载Move，到非Room中可自动合并
int CMoney::move(CContainer *pMe)
{
	DTItemList search;
	CContainer * env, * t;
	POSITION p;
	LONG	total;
	const char * id;
	
	if(! CItem::move(pMe)) return 0;	//未移动成功。

	if((env = environment()))
	{
		if(env->Query(IS_ROOM)) return 1;

		CopyList(&search, env->Get_ItemList());
		id = querystr("base_name");
		total = Query_Amount();
		p = search.GetHeadPosition();
		while(p)
		{
			t = search.GetNext(p);
			if( t == this ) continue;
			if( ! t->Query(IS_ITEM) ) continue;
			if( EQUALSTR(t->querystr("base_name"), id) ) {
				total += ((CItem *)t)->Query_Amount();
				DESTRUCT_OB(t, "CMoney::move");
		    }
		 }
	     set_amount(total);
	}

	return 1;
}

LONG CMoney::Query(int nAttr)
{
	if(nAttr == IS_MONEY)
		return 1;
		
	return CItem::Query(nAttr);

}

/*
//给玩家金钱
int CMoney::Pay_Player(CChar *me, LONG amount)
{
	CItem * ob = NULL;
	CContainer * env = me->environment();
		
	if (amount < 1) amount = 1;
    if (amount / 10000)
	{
        ob = (CItem *)load_item(Money_Gold);
        ob->set_amount(amount / 10000);
		if(! ob->move(me)) ob->move(env);
        amount %= 10000;
    }
    
	if (amount / 100)
	{
        ob = (CItem *)load_item(Money_Silver);
        ob->set_amount(amount / 100);
        if(! ob->move(me)) ob->move(env);
        amount %= 100;
	}
    
	if (amount)
	{
        ob = (CItem *)load_item(Money_Coin);
        ob->set_amount(amount);
        if(! ob->move(me)) ob->move(env);
    }

	return 1;
}
*/
int CMoney::Pay_Player(CChar *me, LONG amount)
{
	CContainer * gold;

	if( amount < 1) return 0;
	
	if( !(gold = load_item("coin"))) return 0;
	gold->set_amount(amount);

	if(! gold->move(me))
		gold->move(me->environment());

	return 1;
}

int CMoney::Player_Pay(CChar *me, LONG amount)
{
	CContainer * money;
	LONG gc;

	if(amount <= 0) return 0;

	if( ! (money = me->PresentName("coin", IS_MONEY)) ) return 0;
	gc = money->Query_Amount() * money->query("base_value");
	
	if (gc < amount) return 0;
	money->set_amount(gc - amount);
	return 1;
}

/*	CItem * g_ob, * s_ob, * c_ob;
	LONG gc, sc, cc, left;
	CContainer * env = me->environment();

	if (( g_ob = (CItem *)me->PresentName(Money_Gold, IS_MONEY)) )
		gc = g_ob->Query_Amount();
	else
		gc = 0;

	if ((s_ob = (CItem *)me->PresentName(Money_Silver, IS_MONEY)) )
		sc = s_ob->Query_Amount();
	else
		sc = 0;

	if ( ( c_ob = (CItem *)me->PresentName(Money_Coin, IS_MONEY)) )
		cc = c_ob->Query_Amount();
	else
		cc = 0;
	
	if (cc + sc * 100 + gc * 10000 < amount) return 0;
	
	left = cc + sc * 100 + gc * 10000 - amount;
	gc = left / 10000;
	left = left % 10000;
	sc = left / 100;
	cc = left % 100;

	if (g_ob)
		g_ob->set_amount(gc);
	else sc += (gc * 100);

	if (s_ob)
		s_ob->set_amount(sc);
	else if (sc) 
	{
		s_ob = (CItem *)load_item(Money_Silver);
		s_ob->set_amount(sc);
		if(! s_ob->move(me)) s_ob->move(env);
	}

	if (c_ob)
		c_ob->set_amount(cc);
	else if (cc) 
	{
		c_ob = (CItem *)load_item(Money_Coin);
		c_ob->set_amount(cc);
		if(! c_ob->move(me)) c_ob->move(env);
	}

	return 1;
}
*/

char * CMoney::Money_Str(LONG amount)
{
	static char output[255];

    snprintf(output, 255, "%ld金币",  amount);
    /*    
    }

    if (amount / 100) 
	{
        snprintf(tmp, 50, "%ld银币", amount / 100);
        amount %= 100;
		strcat(output, tmp);
    }
    
	if (amount)
	{
		snprintf(tmp, 50, "%ld铜币", amount);
		strcat(output, tmp);
	}
*/
	return output;
}
