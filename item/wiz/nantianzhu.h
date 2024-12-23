// nantianzhu.h
// 南天竺
// Lanwood 2001-03-22

ITEM_BEGIN(CInantianzhu);

virtual void create(int nFlag = 0)
{
        set_name("南天竺", "nantianzhu");
        set_weight(1000);
    
        set("unit", "盒");
		set("long", "一盒不知做什么的药材。据说从南天竺进口的。");
        set("value", 5000);
		
		set("no_sell", 1);		
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me == target)
		message_vision("$N服下一粒$n，浑身立刻变得燥热。", me, this);
	else
	{
		if(! target->is_character())
			return notify_fail("你要给谁服用？");
		if(living(target))
			return notify_fail("你企图把%s塞到%s口中，但是没有成功。", name(), target->name());

		message_vision("$N悄悄的在$n口里塞下一粒南天竺。", me, target);
	}

	
	((CChar *)target)->apply_condition("wc_poison", 30 + random(30));

	destruct(this);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;