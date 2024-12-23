// linji_zhuang.h 临济十二庄//

FORCE_BEGIN(CSlinji_zhuang);

virtual void create()
{
	CForce::create();

	set_name( "临济十二庄");

	Magic_t * magic;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "疗伤术";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}


virtual int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int np, nf, nh, ns ;
	nf = me->query_skill("force", 1);
	nh = me->query_skill("linji_zhuang", 1);
	np = me->query_skill("mahayana", 1);
	ns = me->query("guilty");
	
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	if ( me->querymap("couple") || me->query("max_atman"))
		return notify_fail("你已经破了色戒，无法再学习临济十二庄！");
	
	if ( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("你非处女之体，不能练习临济十二庄。");
	
	
	if ( DIFFERSTR(me->querystr("class"), "bonze"))
		return notify_fail("你不是尼姑，学不了高深的临济十二庄。");
	
	if ( np <= nh && nh <= 150)
		return notify_fail("你的大乘涅磐功修为不够，无法领会更高深的临济十二庄。");
	
	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会临济十二庄。");
	
	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的临济十二庄。");
	
	if (
		me->query_skill("bahuang_gong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("kuihua_xinfa",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("longxiang",1)
	//	|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学临济十二庄？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("临济十二庄只能用请教的来增加熟练度。");
}

virtual void skill_improved(CChar* me)
{
	switch (me->query_skill("linji_zhuang",1))
	{
	case 30:
		tell_object(me,  "你天地庄练成了! "  );
		break;
	case 60:
		tell_object(me,  "你之心庄练成了! "  );
		break;
	case 90:
		tell_object(me,  "你龙鹏庄练成了! "  );
		break;
	case 120:
		tell_object(me,  "你风云庄练成了! "  );
		break;
	case 150:
		tell_object(me,  "你大小庄练成了! "  );
		break;
	case 180:
		tell_object(me,  "你幽冥庄练成了! "  );
		break;
		
	}
	return;
}

//为人疗伤
static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( ! target || target == me)
		return notify_fail("你要用真气为谁疗伤？");
    
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");
	
    if( me->query_skill("linji_zhuang",1) < 20 )
		return notify_fail("你的内力修为不够。");
	
    if( me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
    if( me->query("mp") < 150)
		return notify_fail("你的真气不够。");
	
    if( target->query("eff_hp") < target->query("max_hp") / 5 )
		return notify_fail(  "%s已经受伤过重，经受不起你的真气震荡！",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
    message_vision( "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内...."
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。" ,
		me, target );
	
	target->receive_curing("hp", 10 + me->query_skill("force")/2 );
	target->add("hp", 10 + me->query_skill("force")/3 );
	if( target->query("hp") > target->query("eff_hp") ) target->set("hp", target->query("eff_hp"));
		
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
	
static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

    if( ob != me )
		return notify_fail("你只能用临济庄功提升自己的战斗力。");

    if( me->query("mp") < 100 ) 
		return notify_fail("你的内力不够。");

    if( me->querymap_temp("powerup") )
		return notify_fail("你已经在运功中了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "峨嵋派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    skill = me->query_skill("force");
	
    me->add("mp", -100);
    me->receive_damage("hp",0);
	
    message_vision("$N微一凝神，运起临济庄，一声娇喝！" , me);
	    
	start_powerup(me, skill, skill/3, skill/3, "你的临济庄运行完毕，将内力收回丹田。");
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}

FORCE_END;



