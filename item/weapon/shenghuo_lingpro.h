//shenghuo_lingpro.h ��ǿʥ����

EQUIP_BEGIN(CIshenghuo_lingpro);


virtual void create(int nFlag = 0)		
{
	set_name("ʥ����", "shenghuo ling");	

	set("wield_position", WIELD_RIGHT_HAND);		
 	set_weight(1000);		

	set("unit", "��");
 	set("long", "����һ�����������ĺ��ƣ��ǽ�������ʵؼ�Ӳ�ޱȣ���͸���������������л�����ڣ�ʵ��������ӳ�⣬��ɫ��á����Ͽ̵��в��ٲ�˹���֡�");
	set("value",  20000 );
	set("material", "steel");
	set("skill_type", "lingfa");
	set("wield_msg",  "$N��ৡ���һ������������һƬ����������������С�");
    set("unwield_msg",  "$N��ʥ���������䡣" );
 	set("apply/damage", random(70)+80);	
	set("no_duo",1);
   
};
/*
virtual int do_look(CChar * me)
{
	say("����һ�����������ĺ��ƣ��ǽ�������ʵؼ�Ӳ�ޱȣ���͸���������������л�����ڣ�ʵ��������ӳ�⣬��ɫ��á����Ͽ̵��в��ٲ�˹���֡�", me);
	if(query("kill") && EQUALSTR(querystr("owner"),me->id(1)))
	{
		AddMenuItem("��������׷ɱ��","$2zueisha $1 $2", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "zueisha") == 0)
		return do_zueisha(me, arg);
	return 0;
}

int do_zueisha(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("����׷ɱ˭�أ� ");

	if(query("kill"))
	{
		CChar * who = find_online(arg);
		if(! who)
			return notify_fail("ֻ�ܶ����ߵ���ҷ�������׷ɱ�");

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "������%s��ʼ׷ɱ%s(%s)��׷ɱ%ld�Σ�", env->name(), who->name(1), who->id(1), times));
	}

	return 1;
}
*/
EQUIP_END;




