FORCE_BEGIN(CSxiaowuxiang);

virtual void create()
{
	CForce::create();

	set_name( "小无相功");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("shield", do_shield);
	magic->name = "防御术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("xiaowuxiang", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

	if ((DIFFERSTR(me->querystr("class"), "bonze")) && i > 29)
		return notify_fail("你不是僧人，学不了高深的小无相功。");

	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学小无相功。");

	if ( EQUALSTR(me->querystr("gender"), "无性") && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。");

	if (i > 10 && me->query("repute") > t * 100)
		return notify_fail("要学小无相功，你的表现还不够吧！ ");

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
//	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
//	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学小无相功。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("小无相功只能用学的来增加熟练度。");
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target )
		return notify_fail("你要用真气为谁疗伤？");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");

	if(target == me)
		return notify_fail("你没有为自己疗伤的能力！");

	if( me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");

	if( me->query("mp") < 150 )
		return notify_fail("你的真气不够。");

	if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail( "%s已经受伤过重，经受不起你的真气震荡！", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());

	message_vision("$HIY$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。$COM", 	me, target );
	target->receive_curing("hp", 10 + me->query_skill("force")/3 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) 
		target->set("hp", target->query("eff_qi"));

	me->add("mp", -150);
	me->set("mp_factor", 0l);

	//疗伤经验奖励    秦波 2002、7、18
	char expmsg[80];
	int addexp = me->query("level") / 4 + 1;
	int addrpt = 10 - target->query("level");

	addexp = int(((addexp + random(addexp)) / 2) *0.5);
	if(addrpt < 1) addrpt = 1;
	addrpt = (addrpt + random(addrpt)) / 2;

	addexp=1;
	addrpt=1;
	me->add("combat_exp", addexp);
	me->add("repute", addrpt);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了%ld点！", addexp, addrpt));
	//疗伤经验奖励

    me->start_busy(5);
    target->start_busy(5);
	return 1;
}

static int do_shield(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me ) 
		return notify_fail("你只能用小无相功来提升自己的防御力。\n");

	if( me->query("mp") < 100  ) 
		return notify_fail("你的内力不够。");

	if( me->query_temp("shield") ) 
		return notify_fail("你已经在运功中了。");

	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);

	message_vision("$HIW$N双手平举过顶，运起小无相功，全身笼罩在劲气之中！$COM", me);

	me->add_temp("apply/armor", skill*2);
	me->set_temp("shield", 1);

	me->call_out(remove_effect, skill, skill*2);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

static void remove_effect(CContainer * ob, LONG amount, LONG param2)
{
	CChar * me = (CChar *)ob;

	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	me->SendState(me);
	tell_object(me, "你的小无相功运行完毕，将内力收回丹田。");
}

FORCE_END;