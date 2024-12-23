// shenzhao_gong.h 神照功 NPC专用
// Teapot
// 2001-02-07

FORCE_BEGIN(CSshenzhao_gong);

virtual void create()
{
	CForce::create();

	set_name( "神照功");

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

	magic = add_magic("manalock", do_manalock);
	magic->name = "法术力缠结";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;


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

	message_vision("$N默运神照功，一掌四平八稳的拍出！", me);

	static char attack_msg[5][80] = {
		"$N大喝一声，一掌抵去，堪堪抵住攻势！(-%ld)",
		"$N惨叫一声，被打得气血翻动不已！(-%ld)",
		"$N运劲也一掌拍去，只听砰然大震，$N被震飞到两丈之外！(-%ld)",
		"$N左躲右闪，前避后让，还是被一掌拍中！(-%ld)",
		"$N被一掌拍中前胸，喷出一大口鲜血！(-%ld)",		
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
		if(target->query_skill("strike",1) > 250 && random(3) == 0)
			flee = 1;

		if(! flee)
		{
			int lvl = random(5);
			LONG damage = me->query("level") * (lvl + 1) * 2;
			damage = (damage + random(damage))*2;
			snprintf(msg, 255, attack_msg[lvl], damage);
			target->receive_wound("hp", damage);
			target->start_busy(3);
			target->SendState();
		}
		else
		{
			strcpy(msg, "$N身形左右迅闪，险险躲开！");
			target->start_busy(3);
		}

		message_vision(msg, target);
	}

	me->start_busy(random(5));
	return 1;
}

//水疗术
static int do_heal(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 50) 
		return notify_fail("你的法力不足！");

	me->add("mp", -50);

	message_vision("$N运起神照功，深深的吸了口气：呼～", me);

	static char heal_msg[4][80] = {
		"$N顿时神清目爽……(+%ld)",
		"$N顿时神清目爽……(+%ld)",		
		"$N顿时神清目爽……(+%ld)",		
		"$N顿时神清目爽……(+%ld)",		
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
		
		heal = (heal + random(heal));
		snprintf(msg, 255, heal_msg[lvl], heal);
		target->receive_curing("hp", heal);
		target->SendState();
		
		message_vision(msg, target);
	}

	me->start_busy(2);
	return 1;
}


static int do_manalock(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("法术力缠结无法使用。");
	
//	if (! (weapon = me->query_weapon())
//		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
//		return notify_fail("连山绝鼗无法使用。");
	
	if( me->query("mp") < 1500 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"$N集结起法术力，凝成淡蓝色的光芒环绕在%s周围，困住了%s！",target->name(),target->name());
	message_vision(msg, me);
	
	
	me->add("mp", -1500);
	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock

	
	return 1;
	
}

static void do_kml(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->environment())->Present(param1);
//	CContainer * weapon;
	char msg[255];


	if( !target || !me->is_fighting(target) )
		return ;
	
	if(! living(me))
		return ;

	if( me->query("mp") < 1500 )
	{
		tell_object(me,"你的法力衰竭了。");
		snprintf(msg ,255,"淡蓝色的光芒渐渐消失不见了。");
		target->start_busy(1);
		me->start_busy(3);
		me->set("mp",0l);
		message_vision(msg, me);
		return ;
	}

	me->add("mp",-1500);

	snprintf(msg ,255,"一阵淡蓝色的光芒在$N周身跳动。");
	message_vision(msg, target);

	me->add("mp", -1500);
	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock



}


FORCE_END;
