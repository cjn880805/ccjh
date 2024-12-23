//xin.h 

ITEM_BEGIN(CImoonlock)

virtual void create(int nFlag = 0)		
{
	 set_name("月锁结魂印", "moonlock brand");
     set_weight(10000);
        
     set("unit", "块");
     set("material", "steel");
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("你要对谁使用？");

//	if (query("used"))
//		return notify_fail("%s只能使用一次。", name());

	if (me->is_fighting())
		return notify_fail("现在无法使用月锁结魂印！");

    if( (me->environment())->query("no_fight") && !query("special_make"))
		return notify_fail("此处无法使用月锁结魂印！");

	message_vision("$N从怀中摸出什么，冷冷的扬手挥出，掌中飞洒过一片银芒……", me, target);
	message_vision("银尘飞散之处，笼罩了$N和$n所站的三丈方圆……", me, target);
	
	CFightRoom * obj;
	obj = (CFightRoom *)load_item("fight_room");		
	obj->set("room_locked", FIGHT_LOCKED);
	obj->set_name( "月锁结魂阵", "array");
	obj->move(me->environment());
	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);
	target->move(obj);
	obj->Join_Team(target, CFightRoom::FIGHT_TEAM_B);
	obj->Begin_Fight(0);

	destruct(this);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "specialmake") == 0)
	{
		set("special_make",1);
		tell_object(me,"Ok.");
		return 1;
	}

	return CItem::handle_action(comm, me, arg);
}
ITEM_END;
