ROOM_BEGIN(CRXueDao_shandong2);

virtual void create()
{
	set_name( "血刀门山洞2");
	add_door("血刀门大雪山山谷9", "血刀门大雪山山谷9", "血刀门山洞2");
	add_npc("lj_honghuangzi");
//	set("long","谷里积雪被拢成几个雪堆，这里时常有人扫除积雪。你前面的峭壁下隐隐约约有一个山洞。");
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
		say("一片堆满了积雪的谷地……山洞之中隐隐有寒风流动，你心中突有灵光一闪，瞬时即逝。", me);
		AddMenuItem("再行观察", "", me);
		AddMenuItem("凝神静思", "$0snowcrow $1", me);

	}
	say("一片堆满了积雪的谷地……山洞之中隐隐有寒风流动。突的一阵风起，雪花纷扬，迷住了你的眼睛。", me);
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
   return notify_fail("你现在正忙着呢。");

	
	me->receive_damage("hp",100);	

	if( me->query_skill("literate", 1) )
		return notify_fail("你凝神静思了半晌，只觉得千头万绪纷至沓来，心中一片混乱。");

	if( me->query_skill("frost_blade", 1) )
		return notify_fail("你凝神静思了半晌，只觉得千头万绪纷至沓来，心中一片混乱。");

	if( me->query_skill("blade", 1)<10 )
		return notify_fail("你凝神静思了半晌，只觉得千头万绪纷至沓来，心中一片混乱。");

	if( DIFFERSTR(me->querystr("gender"), "男性") )
		return notify_fail("你凝神静思了半晌，只觉得千头万绪纷至沓来，心中一片混乱。");

	tell_room(me->environment(), snprintf(msg, 255, "%s默默的站在风雪中，似乎正在用心揣摩什么。", me->name()), me);

	me->set_skill("frost_blade",1);	

	tell_room(me->environment(), snprintf(msg, 255, "%s心念一闪，只觉得一缕寒气上冲，浑身猛的一震……", me->name()), me);
	me->unconcious();


	return 1;
}









ROOM_END;
