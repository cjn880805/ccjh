ROOM_BEGIN(CRXueDao_shandong2);

virtual void create()
{
	set_name( "Ѫ����ɽ��2");
	add_door("Ѫ���Ŵ�ѩɽɽ��9", "Ѫ���Ŵ�ѩɽɽ��9", "Ѫ����ɽ��2");
	add_npc("lj_honghuangzi");
//	set("long","�����ѩ��£�ɼ���ѩ�ѣ�����ʱ������ɨ����ѩ����ǰ����ͱ�������ԼԼ��һ��ɽ����");
};


virtual int do_look(CChar * me)
{
	if ( random(me->query_int())>25 )
		me->add_temp("teapot/snowvalley",1);

	me->receive_damage("hp",50);
	
	if (random(me->query_temp("teapot/snowvalley"))>30 )
	{
		me->set_temp("teapot/snowbook",1);
		me->delete_temp("teapot/snowvalley");
		say("һƬ�����˻�ѩ�Ĺȵء���ɽ��֮�������к���������������ͻ�����һ����˲ʱ���š�", me);
		AddMenuItem("���й۲�", "", me);
		AddMenuItem("����˼", "$0snowcrow $1", me);

	}
	say("һƬ�����˻�ѩ�Ĺȵء���ɽ��֮�������к���������ͻ��һ�����ѩ�������ס������۾���", me);
	SendMenu(me);

	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("teapot/snowbook"))
		return 0;
	if(strcmp(comm, "snowcrow") == 0)
		return do_ssb(me, arg);
	return 0;
}




int do_ssb(CChar *me, char * arg)
{
	char msg[255];

   if (me->is_busy() || me->query_temp("pending/exercising"))
   return notify_fail("��������æ���ء�");

	
	me->receive_damage("hp",100);	

	if( me->query_skill("literate", 1) )
		return notify_fail("������˼�˰��Σ�ֻ����ǧͷ�����������������һƬ���ҡ�");

	if( me->query_skill("frost_blade", 1) )
		return notify_fail("������˼�˰��Σ�ֻ����ǧͷ�����������������һƬ���ҡ�");

	if( me->query_skill("blade", 1)<10 )
		return notify_fail("������˼�˰��Σ�ֻ����ǧͷ�����������������һƬ���ҡ�");

	if( DIFFERSTR(me->querystr("gender"), "����") )
		return notify_fail("������˼�˰��Σ�ֻ����ǧͷ�����������������һƬ���ҡ�");

	tell_room(me->environment(), snprintf(msg, 255, "%sĬĬ��վ�ڷ�ѩ�У��ƺ��������Ĵ�Ħʲô��", me->name()), me);

	me->set_skill("frost_blade",1);	

	tell_room(me->environment(), snprintf(msg, 255, "%s����һ����ֻ����һ�ƺ����ϳ壬�����͵�һ�𡭡�", me->name()), me);
	me->unconcious();


	return 1;
}









ROOM_END;
