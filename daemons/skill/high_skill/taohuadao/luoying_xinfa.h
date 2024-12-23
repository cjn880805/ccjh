
// luoying_xinfa.h 落英心法
//code by Fisho
//date : 2000-12-08
FORCE_BEGIN(CSluoying_xinfa);

virtual void create()
{
	CForce::create();

	set("name", "落英心法");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force") ;
}

virtual int valid_learn(CChar * me)
{
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("落英心法只能用请教的来增加熟练度。");
}

//perform 
static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (!target || target == me)
		return notify_fail("你要用真气为谁疗伤？");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 100)
		return notify_fail("你的真气不够。");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail( "%s已经受伤过重，经受不起你的真气震荡！",target->name() );

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。",me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/2 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	
	if(  target->query("hp") >  target->query("eff_hp") ) 
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -100);
	me->set("mp_factor", 0);
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

static int do_powerup(CChar * me, CContainer * ob)
{
	if( ob != me ) 
		return	notify_fail("你只能用落英心法提升自己的战斗力。");
	
	if(  me->query("mp") < 100 ) 
		return	notify_fail("你的内力不够。");
	if(  me->querymap_temp("powerup") ) 
		return notify_fail("你已经在运功中了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	int skill = me->query_skill("force");
	
	me->add("mp", -45);
	me->receive_damage("hp",0);
	message_vision( "$N微一凝神，运起落英心法，全身衣裳烈烈做响，眼中精光四射，很是摄人。"  , me );
	
	start_powerup(me, skill, skill/3, skill/3, "你的落英心法运行完毕，将内力收回丹田。");
	
	if( me->is_fighting() )
		me->start_busy(3);
	return 1;
}

FORCE_END;
