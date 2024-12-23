// Food.cpp: implementation of the CFood class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Food.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFood::CFood()
{
}

CFood::~CFood()
{

}

int CFood::Can_Use()
{
	return 1;
}

int CFood::do_use(CChar * me, CContainer * target)
{
	char eat_msg[255];	

	if( !query("food_remaining") )
		return notify_fail("%s已经没什么好吃的了。", name());

	int hp = me->query("hp"), mp = me->query("mp");

	int addhp = query("hp_supply");
	int addmp = query("mp_supply");
		
	if(!addhp) addhp = query("food_supply") / 3;	
	if(addhp <= 0) addhp = 1;

	me->receive_healing("hp", addhp);
	me->receive_healing("mp", addmp);

	char hpstr[40], mpstr[40];

	hpstr[0] = 0; mpstr[0] = 0;

	hp = me->query("hp") - hp;
	mp = me->query("mp") - mp;

	if(hp)	snprintf(hpstr, 40, " hp+%ld", hp);
	if(mp)	snprintf(mpstr, 40, " mp+%ld", mp);

	if( me->is_fighting()) me->start_busy(2);

	set("value", 0l);
	add("food_remaining", -1);

	strncpy(eat_msg, querystr("eat_msg"), 255);
	
	if( query("food_remaining") <= 0) 
	{
		if(query("food_supply"))
		{
			if(eat_msg[0])
			{
				strcat(eat_msg, "\n$n吃完了。");
			} 
			else
				strcpy(eat_msg, "$N将剩下的$n吃得干干净净。");
		}

		strcat(eat_msg, hpstr);
		strcat(eat_msg, mpstr);
		message_vision(eat_msg, me, this);

		if( ! finish_eat() )
		{
			DESTRUCT_OB(this, "CFood::do_use");
			me->SendState(me);
			return 1;
		}
    }
	else if(! eat_msg[0])
		strcpy(eat_msg, "$N拿起$n吃了几口。");
	
	strcat(eat_msg, hpstr);
	strcat(eat_msg, mpstr);
	message_vision(eat_msg, me, this);
	me->SendState(me);
	return 1;
}

int CFood::finish_eat()
{
	return 0;
}
