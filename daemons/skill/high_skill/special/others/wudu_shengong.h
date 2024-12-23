// wudu_shengong 五毒神功
FORCE_BEGIN(CSwudu_shengong);

virtual void create()
{
	set_name( "五毒神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;
}


int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("wudu_shengong", 1);
	int t = 1, j;

	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	
	if (me->query_skill("force", 1) < 10)
			return notify_fail("你的基本内功火候还不够。");
	
	if(lvl<=100)
	{
		if (lvl > 10 && me->query("repute") > -t * 100) 
			return notify_fail("心怀仁慈是练不好五毒神功的。");
	}
	else
	{
		if (me->query("repute") > -(51200 + (lvl - 100) * 1000)) 
			return notify_fail("不心狠手辣，如何能修炼五毒神功。");
	}
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("五毒神功只能用请教的来增加熟练度。");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

	if (me->query_skill("wudu_shengong", 1) < 30)
		return notify_fail("你的五毒神功修为还不够。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你调息凝精，默运内功开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s盘腿坐下，周身萦绕着一股淡蓝色的雾气。过了一会，雾气消去，%s看起来脸色好多了。", me->name(), me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(4);

	return 1;
}

FORCE_END;