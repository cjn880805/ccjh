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
		return notify_fail("����һ��������û����ɡ�");
	if( !query("liquid/remaining") )
		return notify_fail( (querystr("liquid/name")[0] ? "%s�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�":"%s�ǿյġ�"), name());
	
	add("liquid/remaining", -1);
   
	if (! msg[0])
	   snprintf(msg, 255, "$N����$n������غ��˼���%s��", querystr("liquid/name"));
        
	message_vision(msg, me, this);
   
	me->add("hp", 1);
	if( me->is_fighting()) me->start_busy(2);
	if( !query("liquid/remaining") )
		tell_object(me, snprintf(msg, 255, "���Ѿ���%s���%s�ȵ�һ��Ҳ��ʣ�ˡ�", name(), querystr("liquid/name")));

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
			snprintf(extra, 255, "����װ����%s��", querystr("liquid/name"));
		else if( amount > max/2 )
			snprintf(extra, 255, "����װ���ߡ��˷�����%s��", querystr("liquid/name"));
		else if( amount >= max/3 )
			snprintf(extra, 255, "����װ���塢��������%s��", querystr("liquid/name"));
		else if( amount > max/2 )
			snprintf(extra, 255, "����װ�������%s��", querystr("liquid/name"));
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
		return notify_fail("����һ��������û����ɡ�");
	
	
	if( ! (me->environment())->query("resource/water"))
		return notify_fail("����û�еط�����װˮ��");

	strcpy(liquid_name, "��ˮ");
    strcpy(liquid_type, "water");
   
	if( query("liquid/remaining") )
		message_vision(snprintf(msg, 255, "$N��%s��ʣ�µ�%s������", name(), querystr("liquid/name")), me);
   
	message_vision(snprintf(msg, 255, "$N��%sװ��%s��", name(), liquid_name), me);

	if( me->is_fighting() ) me->start_busy(2);

	set("liquid/type", liquid_type);
	set("liquid/name", liquid_name);
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0l);

	return 1;
}
