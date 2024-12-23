
// shenghuo_shengong.h 圣火神功
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSshenghuo_shengong);

virtual void create()
{
	CForce::create();

	set_name( "圣火神功");

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
	int lvl =  me->query_skill("shenghuo_shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
		
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。");
	if ( me->query_skill("shenghuo_xinfa", 1)*3/2 < 
		me->query_skill("shenghuo_shengong", 1))
		return notify_fail("你的圣火心法修为不够。");
	
    return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("圣火神功只能用请教的来增加熟练度。");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	if ( me->query_skill("shenghuo_shengong", 1) < 30)
		return notify_fail("你的圣火神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	if(  me->query("eff_hp") ==  me->query("max_hp"))
		return notify_fail("你现在没有受任何伤。");
	if(  me->query("eff_hp") <  me->query("max_hp") / 7 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	tell_object(me,  "你双手着飞焰状运起圣火神功 疗伤。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s双手着飞焰状运起 圣火神功 疗伤。" ,me->name()),me);
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	return 1;
}

static int do_life_heal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if( !target )
		return notify_fail("你要用真气为谁疗伤？");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");

	if(target == me)
		return notify_fail("你不能用来为自己疗伤。");
	
	if ( me->query_skill("shenghuo_shengong", 1) < 40)
		return notify_fail("你的圣火神功修为还不够。");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 100 )
		return notify_fail("你的真气不够。");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 7 )
		return notify_fail("%s已经受伤过重，经受不起你的真气震荡！",target->name() );
	
	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$N盘膝坐下来运起圣火神功，缓缓将手掌贴在$n胸前，将真气缓缓输入$n体内...不久，$N收回双掌，$n吐出一口瘀血，感觉伤势好多了。"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") ) target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -100);
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

FORCE_END;
