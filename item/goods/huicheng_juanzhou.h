AUTOCOMBINE_BEGIN(CIhuicheng_juanzhou)

virtual void create(int nFlag = 0)		
{
	set_name("回城卷轴", "huicheng juanzhou");
    set("base_weight", 1500);
	set("base_value", 100);
 
	set("material", "paper");

	set_amount(1);
};

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	if(me->is_fighting())
		return notify_fail("你正在战斗。");

	if(me->query_temp("no_fei"))
		return notify_fail("以你目前的情形，无法使用“回城卷轴”。");

	if(me->query_temp("no_fei_1"))
		return notify_fail("以你目前的情形，无法使用“回城卷轴”。");

	CRoom * r = load_room(me->querystr("start_city"));
//	if(r->query("corp"))
//		return notify_fail("无法使用“回城卷轴”回帮会总舵。");
	message_vision("$HIY$N在空中划出一道门，抬腿跨了进去。", me);
	me->move(r);
	tell_room(r, snprintf(msg, 255, "$BLU空中现出一道门，%s从中走了下来。", me->name()), me);

	destruct(this);
	return 1;
};

virtual int Can_Use()
{
	return 1;
};


AUTOCOMBINE_END;
