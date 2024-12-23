

ROOM_BEGIN(CRGuanWai_tianchi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ͷɽ���2");

	add_npc("pub_youke");      // add by zdn 2001-07-13
	add_npc("tdh_chen");	//�½���

	set("monster_chance", 2);

	add_door("�����ͷɽ���1", "�����ͷɽ���1", "�����ͷɽ���2");

	set("long","���ʮ������������ƣ�������˲Ϣ�����������꣬ʹ���ʱ������������������ʱ���������Ө��ɴ��ʱ����Ծ��󺣲��Σ���ɫ�������������" );

};


virtual int do_look(CChar * me)
{
	if ( random(me->query_dex())>25 )
		me->add_temp("teapot/lake",1);

	me->receive_damage("hp",50);
	
	if (random(me->query_temp("teapot/lake"))>30 )
	{
		me->set_temp("teapot/lakebook",1);
		me->delete_temp("teapot/lake");
		say("���ʮ������������ƣ�������˲Ϣ�����������꣬ʹ���ʱ������������������ʱ���������Ө��ɴ��ʱ����Ծ��󺣲��Σ��㿴�ž�ɫ������ͻȻһ����", me);
		AddMenuItem("���й۲�", "$0snowcrow $1", me);
		AddMenuItem("����˼", "", me);

	}
	say("���ʮ������������ƣ�������˲Ϣ�����������꣬ʹ���ʱ������������������ʱ���������Ө��ɴ��ʱ����Ծ��󺣲��Σ���ɫ�������������", me);
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (!me->query_temp("teapot/lakebook"))
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

	if( me->query_skill("dodge", 1) )
		return notify_fail("����Ŀ�����ط����������Ҳ�����һɲ�ǵĸо���");

	if( me->query_skill("ice_sword", 1) )
		return notify_fail("����Ŀ�����ط����������Ҳ�����һɲ�ǵĸо���");

	if( me->query_skill("sword", 1)<10 )
		return notify_fail("����Ŀ�����ط����������Ҳ�����һɲ�ǵĸо���");

	if( DIFFERSTR(me->querystr("gender"), "Ů��") )
		return notify_fail("����Ŀ�����ط����������Ҳ�����һɲ�ǵĸо���");

	tell_room(me->environment(), snprintf(msg, 255, "%s�����Ŀ�����ط�����", me->name()), me);

	me->set_skill("ice_sword",1);	

	tell_room(me->environment(), snprintf(msg, 255, "%s����һ����ֻ����һ�ƺ����ϳ壬�����͵�һ�𡭡�", me->name()), me);
	me->unconcious();


	return 1;
}




ROOM_END;
