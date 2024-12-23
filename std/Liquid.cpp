// Liquid.cpp: implementation of the CLiquid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Liquid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLiquid::CLiquid()
{

}

CLiquid::~CLiquid()
{

}

int CLiquid::Can_Use()
{
	return 1;
}

int CLiquid::do_use(CChar * me, CContainer * target)
{
	char msg[255];

	strncpy(msg, querystr("drink_msg"), 255);
   
	if ( ! living(me) ) return 1;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。");
	if( !query("liquid/remaining") )
		return notify_fail( (querystr("liquid/name")[0] ? "%s已经被喝得一滴也不剩了。":"%s是空的。"), name());
	
	add("liquid/remaining", -1);
   
	if (! msg[0])
	   snprintf(msg, 255, "$N拿起$n咕噜噜地喝了几口%s。", querystr("liquid/name"));
        
	message_vision(msg, me, this);
   
	me->add("hp", 1);
	if( me->is_fighting()) me->start_busy(2);
	if( !query("liquid/remaining") )
		tell_object(me, snprintf(msg, 255, "你已经将%s里的%s喝得一滴也不剩了。", name(), querystr("liquid/name")));

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	if(EQUALSTR( querystr("liquid/type"), "alcohol"))
		me->apply_condition("drunk", me->query("condition/drunk") + query("liquid/drunk_apply"));

	return 1;
}

int CLiquid::handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "fill") == 0)
	{
		return do_fill(me);
	}

	return 0;
}

char * CLiquid::extra_long()
{
   int amount, max;
   static char extra[255];

   if( (amount = query("liquid/remaining")) )
   {
		max = query("max_liquid");
		if( amount == max )
			snprintf(extra, 255, "里面装满了%s。", querystr("liquid/name"));
		else if( amount > max/2 )
			snprintf(extra, 255, "里面装了七、八分满的%s。", querystr("liquid/name"));
		else if( amount >= max/3 )
			snprintf(extra, 255, "里面装了五、六分满的%s。", querystr("liquid/name"));
		else if( amount > max/2 )
			snprintf(extra, 255, "里面装了少许的%s。", querystr("liquid/name"));
		return extra;
   }
   else return 0;
}


int CLiquid::do_fill(CChar * me)
{
	char liquid_name[20];
	char liquid_type[20];
	char msg[255];

	if( !living(me))  return 1;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。");
	
	
	if( ! (me->environment())->query("resource/water"))
		return notify_fail("这里没有地方可以装水。");

	strcpy(liquid_name, "清水");
    strcpy(liquid_type, "water");
   
	if( query("liquid/remaining") )
		message_vision(snprintf(msg, 255, "$N将%s里剩下的%s倒掉。", name(), querystr("liquid/name")), me);
   
	message_vision(snprintf(msg, 255, "$N将%s装满%s。", name(), liquid_name), me);

	if( me->is_fighting() ) me->start_busy(2);

	set("liquid/type", liquid_type);
	set("liquid/name", liquid_name);
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0l);

	return 1;
}
