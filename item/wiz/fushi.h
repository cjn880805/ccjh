//地狱符石

ITEM_BEGIN(CIfushi);

virtual void create(int nFlag = 0)		
{
	set_name("符石","stone");

	set_weight(5000);
	set("value", 1);
	set("long", "这是产自地狱的一种的石头，幽幽的闪着暗蓝色的光芒，传说中它拥有着穿梭生死二界的神奇之效。");  

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting())
		return notify_fail("你正在战斗。");

	CContainer * env = me->environment();
	
	if(DIFFERSTR(env->querystr("area"),"高昌") && DIFFERSTR(env->querystr("area"),"野外"))
		return notify_fail("「符石」只能在地狱中使用！");

	message_vision("只见$N拿出符石，向上面吹了一口气，符石爆出一团光雾包围了$N。", me);
	me->set("start_obj",env->querystr("base_name"));
	me->set_temp("start_obj",env->querystr("base_name"));
	destruct(this);
    return 1; 
}

ITEM_END;
