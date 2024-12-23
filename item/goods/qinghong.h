//xin.h 

ITEM_BEGIN(CIqinghong)

virtual void create(int nFlag = 0)		
{
	 set_name("清虹追命针", "rainbow needle");
     set_weight(10000);
        
     set("unit", "盒");
     set("material", "steel");
	 set("no_give",1);
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

	if (query("used"))
		return notify_fail("%s只能使用一次。", name());

	if (me->is_fighting())
		return notify_fail("现在无法使用清虹追命针！");

    if( (me->environment())->query("no_fight"))
		return notify_fail("在这不可偷袭！");

	message_vision("$N阴笑一声，从怀里摸出一件东西对准$n，从盒子爆射出一缕青光！．．．", me, target);
	
	int i;
	i=target->query_skill("dodge");	
	i=1000 - i;	
	i=i*3;	
	if (i<1) i=1;

	message_vision("只听$N发出一声悠长的惨叫：啊～～～～～。", me);   

	target->apply_condition("rainbow_poison", 20 + random(20));

	set("used",1);
	target->kill_ob(me);
	target->receive_wound("hp",i);	
	me->start_busy(4);

	return 1;
}

ITEM_END;
