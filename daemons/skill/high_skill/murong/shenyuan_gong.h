// shenyuan_gong.h 神元功
//code by sound
//date : 2001-06-14

FORCE_BEGIN(CSshenyuan_gong);

virtual void create()
{
	CForce::create();

	set_name( "神元功");
	
	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("life_heal", do_life_heal);
	magic->name = "医疗术";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force") ;
}

virtual int valid_learn(CChar * me)
{
	
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，无法领会神元功。");
	
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
		|| me->query_skill("zixia_shengong",1) 
//		|| me->query_skill("shenyuan_gong",1) 
		|| me->query_skill("yunlong_shengong",1))
		return notify_fail("你不先散了别派内功，怎能学神元功？！");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("神元功只能用学来增加熟练度。");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];
	
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("shenyuan_gong", 1) < 20)
		return notify_fail("你的神元功修为还不够。");
	
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object( me, "你全身放松，坐下来开始运功疗伤。" );
	tell_room(me->environment(), snprintf(msg,255, "%s吐出一口瘀血，脸色看起来好多了。" , me->name() ),me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
//	me->set("mp_factor", 0);
	me->start_busy(2);
	
	return 1;
	
}

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
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 100 )
		return notify_fail("你的真气不够。");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 5 )
		return notify_fail("%s已经受伤过重，经受不起你的真气震荡", target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$HIY$N坐了下来运起神元功，将手掌贴在$n背心，缓缓地将真气输入$n体内......\n\n$n只觉一股真气源源不绝的输入体内，瞬间流遍全身各大穴位。$n吐出一\n\n口瘀血，脸色看起来红润多了，并觉全身真气无比充沛！！！\n$COM" , me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -100);
//	me->set("mp_factor", 0);
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
	me->start_busy(3);
	target->start_busy(3);
	return 1;
	
}

FORCE_END;
