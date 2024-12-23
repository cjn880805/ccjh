// yunlong_shengong.h 云龙神功
FORCE_BEGIN(CSyunlong_shengong);

virtual void create()
{
	CForce::create();

	set_name( "云龙神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{

	int  nb, nf, nh;
	nb = me->query_skill("yunlong_xinfa", 1);
	nf = me->query_skill("force", 1);
	nh = me->query_skill("yunlong_shengong", 1);

	if ( EQUALSTR(me->querystr("gender"), "无性") && nh > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的云龙神功。");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的云龙心法修为不够，无法领会更高深的云龙神功。");

	if ( nf < 40)
		return notify_fail("你的基本内功火候还不够，无法领会云龙神功。");


	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	//|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学云龙神功？");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("云龙神功只能用请教的来增加熟练度。");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

	if (me->query_skill("yunlong_shengong", 1) < 40)
		return notify_fail("你的云龙神功修为还不够。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你调息凝精，默运内功开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}
	
static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me )
		return notify_fail("你只能用云龙神功提升自己的战斗力。");

	if( me->query("mp") < 100  )
		return notify_fail("你的内力不够。");

	if( me->querymap_temp("powerup") )
		return notify_fail("你已经在运功中了。");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N长吸一口气，运起云龙神功已将全身潜力尽数提起！", me);
	
	start_powerup(me, skill, skill/3, skill/3, "你的云龙神功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

FORCE_END;
