// magic.c 法术 Monster专用
// Lanwood
// 2001-02-03

FORCE_BEGIN(CSmagic);

virtual void create()
{
	CForce::create();

	set_name( "法术");

	Magic_t * magic;

	magic = add_magic("lieyan", do_lieyan);
	magic->name = "烈焰术";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("heal", do_heal);
	magic->name = "水疗术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;


	magic = add_magic("oildown", do_oildown);
	magic->name = "滚烫肥油降";
	magic->mp = 150;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("powerheal", do_powerheal);
	magic->name = "烟疗术";
	magic->mp = 80;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("meteor", do_meteor);
	magic->name = "流星爆击术";
	magic->mp = 300;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("法术只能用学的来增加熟练度。");
}

static int do_lieyan(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N伸出一根手指，口中念念有词~~~只见一大团火焰从天而降！", me);

	static char flee_msg[4][80] ={
		"结果$N纵身一跃，侥幸逃过一劫！",
		"$N吓得面色苍白，但并没被伤到毫毛。",
		"$N就地一滚，躲开了火焰。",		
		"$N跌跌撞撞，在浓烟中挣扎，总算逃过一劫！",
	};
	static char attack_msg[7][80] = {
		"$N躲闪不及，被燎到了头发！(-%ld)",
		"$N吓得面色苍白，衣服被火焰吞去了一角！(-%ld)",
		"$N头发起火，吓得哭爹喊娘！(-%ld)",
		"$N惨嚎一声，被火焰燎去了头发！(-%ld)",
		"$N全身被火焰包围，吓得哇哇大哭！(-%ld)",
		"$N左躲由闪，仍然没逃出火焰的包围！(-%ld)",
		"$N被火焰烧得焦头烂额，在浓烟中乱撞！(-%ld)",		
	};

	//烈焰术攻击敌全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("force") > 150 && random(2) == 0)
			flee = 1;
		else if(target->query_skill("force") > 100 && random(3) == 0)
			flee = 1;
		else if(target->query_skill("force") > 50 && random(5) == 0)
			flee = 1;
		else if(random(7) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(7);
			LONG damage = me->query("level") * (lvl + 1) * 2;
			damage = (damage + random(damage)) / 2;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_damage("hp", damage);
			target->start_busy(2);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(4)]);
			target->start_busy(1);
		}

		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}

//水疗术
static int do_heal(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 50) 
		return notify_fail("你的法力不足！");

	me->add("mp", -50);

	message_vision("$N双手合十，面露虔诚之色。只见一片雪花飘过……", me);

	static char heal_msg[4][80] = {
		"$N沐浴在雪花中，顿觉神清目明！(+%ld)",
		"$N深深的吸了两口，顿时恢复了气色！(+%ld)",
		"$N沐浴在雪花中，两眼放出光彩！(+%ld)",
		"雪花飘过，$N顿时觉得神彩飞扬！(+%ld)"		
	};

	//治疗全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(target != me && ! target->is_fighting() )
			continue;

		if(target->query_temp("fight/fight_team") != me->query_temp("fight/fight_team"))
			continue;
		
		int lvl = random(4);
		
		LONG heal = me->query("level") * (lvl + 1) * 2;
		
		heal = (heal + random(heal)) / 2;
		snprintf(msg, 255, heal_msg[lvl], heal);
		target->receive_healing("hp", heal);
		target->SendState();
		
		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}



//烟疗术
static int do_powerheal(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 80) 
		return notify_fail("你的法力不足！");

	me->add("mp", -80);

	message_vision("$N将手一划，一道乌烟自地下升起……", me);

	static char heal_msg[4][80] = {
		"$N在浓烟中大笑三声，中气愈来愈充足！(+%ld)",
		"$N深深的吸了两口，顿时恢复了气色！(+%ld)",
		"$N在乌烟中的身形越发灵活！(+%ld)",
		"乌烟绕$N盘旋了三圈，钻入$N体内！(+%ld)"		
	};

	//治疗全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(target != me && ! target->is_fighting() )
			continue;

		if(target->query_temp("fight/fight_team") != me->query_temp("fight/fight_team"))
			continue;
		
		int lvl = random(4);
		
		LONG heal = me->query("level") * (lvl + 1) * 2;
		
		heal = (heal + random(heal)) ;
		snprintf(msg, 255, heal_msg[lvl], heal);
		target->receive_healing("hp", heal);
		target->SendState();
		
		message_vision(msg, target);
	}

	me->start_busy(3);
	return 1;
}

static int do_oildown(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 150) 
		return notify_fail("你的法力不足！");

	me->add("mp", -150);

	message_vision("$N高举双手，口中念念有辞，猛的向下一挥！", me);
	message_vision("一大锅滚烫的肥油自天上降下！", me);

	static char flee_msg[4][80] ={
		"结果$N纵身一跃，侥幸逃过一劫！",
		"$N吓得面色苍白，但并没被伤到毫毛。",
		"$N望边上一闪，差点就被泼中。",		
		"$N身形一抖，迅捷的闪了开去！",
	};
	static char attack_msg[7][80] = {
		"$N躲闪不及，被泼到了脚趾！(-%ld)",
		"$N躲闪不及，被泼到了脚趾！(-%ld)",
		"$N吓得面色苍白，衣服被泼中，顿时一片焦黑！(-%ld)",
		"$N吓得面色苍白，衣服被泼中，顿时一片焦黑！(-%ld)",
		"$N惨叫一声，被淋了个正着！(-%ld)",
		"$N纵起身想逃开，结果太慢一步，冲进油中，顿时几被烤焦！(-%ld)",
		"$N左一闪，右一闪，望后一闪，望前再一闪，刚好站在一整锅肥油下！(-%ld)",
	};

	//滚烫肥油降攻击敌全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("dodge") > 150 && random(3) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 100 && random(5) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 50 && random(7) == 0)
			flee = 1;
		else if(random(9) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(7);
			LONG damage = me->query("level") * (lvl + 1) * 2;
			damage = (damage + random(damage)) *2 / 3;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_damage("hp", damage);
			target->start_busy(2);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(4)]);
			target->start_busy(1);
		}

		message_vision(msg, target);
	}

	me->start_busy(5);
	return 1;
}


//流星爆击术
static int do_meteor(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 300) 
		return notify_fail("你的法力不足！");

	me->add("mp", -300);

	message_vision("$N口中念念有词，将手冲你一指！", me);
	message_vision("只听得呼啸破空之声，一片流星雨冲战场落下！", me);

	static char flee_msg[2][80] ={
		"$N望边上一闪，一粒流星便砸在$N刚才站立的地方。",		
		"$N在地上一滚，差点就没避开！",
	};
	static char attack_msg[3][80] = {
		"$N惨叫一声，被砸了个头破血流！(-%ld)",
		"$N纵起身想逃开，结果太慢一步，一头撞在一块陨石上！(-%ld)",
		"$N左一闪，右一闪，望后一闪，望前再一闪，刚好站在一片流星下！(-%ld)",
	};

	//流星爆击术攻击敌全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;
		
		int flee = 0;
		if(target->query_skill("dodge") > 200 && random(4) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 160 && random(7) == 0)
			flee = 1;
		else if(target->query_skill("dodge") > 120 && random(10) == 0)
			flee = 1;
		else if(random(20) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(3);
			LONG damage = me->query("level") * (lvl*2 + 2) * 2;
			damage = (damage + random(damage)) *3/2;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_wound("hp", damage);
			target->start_busy(3);
			target->SendState();
		}
		else
		{
			strcpy(msg, flee_msg[random(2)]);
			target->start_busy(3);
		}

		message_vision(msg, target);
	}

	me->start_busy(9);
	return 1;
}



FORCE_END;
