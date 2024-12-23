

ROOM_BEGIN(CRGuanWai_tianchi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白头山天池2");

	add_npc("pub_youke");      // add by zdn 2001-07-13
	add_npc("tdh_chen");	//陈近南

	set("monster_chance", 2);

	add_door("关外白头山天池1", "关外白头山天池1", "关外白头山天池2");

	set("long","天池十天九雾，云蒸雾绕，变幻无穷。瞬息万变的雾霭风雨，使天池时而清亮如蓝天明镜，时而缥缈如轻莹薄纱，时而腾跃如大海波涛，景色大观令人神往。" );

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
		say("天池十天九雾，云蒸雾绕，变幻无穷。瞬息万变的雾霭风雨，使天池时而清亮如蓝天明镜，时而缥缈如轻莹薄纱，时而腾跃如大海波涛，你看着景色，心中突然一动。", me);
		AddMenuItem("再行观察", "$0snowcrow $1", me);
		AddMenuItem("凝神静思", "", me);

	}
	say("天池十天九雾，云蒸雾绕，变幻无穷。瞬息万变的雾霭风雨，使天池时而清亮如蓝天明镜，时而缥缈如轻莹薄纱，时而腾跃如大海波涛，景色大观令人神往。", me);
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
   return notify_fail("你现在正忙着呢。");

	
	me->receive_damage("hp",100);	

	if( me->query_skill("dodge", 1) )
		return notify_fail("你苦苦的看着天池发呆，但再找不到那一刹那的感觉。");

	if( me->query_skill("ice_sword", 1) )
		return notify_fail("你苦苦的看着天池发呆，但再找不到那一刹那的感觉。");

	if( me->query_skill("sword", 1)<10 )
		return notify_fail("你苦苦的看着天池发呆，但再找不到那一刹那的感觉。");

	if( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("你苦苦的看着天池发呆，但再找不到那一刹那的感觉。");

	tell_room(me->environment(), snprintf(msg, 255, "%s怔怔的看着天池发呆。", me->name()), me);

	me->set_skill("ice_sword",1);	

	tell_room(me->environment(), snprintf(msg, 255, "%s心中一动，只觉得一缕寒气上冲，浑身猛的一震……", me->name()), me);
	me->unconcious();


	return 1;
}




ROOM_END;
