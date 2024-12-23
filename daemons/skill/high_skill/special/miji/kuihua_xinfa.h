// kuihua_xinfa.h 葵花心法
//code by Fisho
//date : 2000-12-06

FORCE_BEGIN(CSkuihua_xinfa);

virtual void create()
{
	CForce::create();

	set_name( "葵花心法");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	int i =  me->query_skill("kuihua_xinfa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学葵花心法。");
	if (i > 10 &&  me->query("repute") > t * 100)
		return notify_fail("学葵花心法，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学葵花心法做什麽！");
	if ( me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学葵花心法？！");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("葵花心法只能用请教的来增加熟练度。");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("kuihua_xinfa", 1) < 20)
		return notify_fail("你的葵花心法修为还不够。");
	if(  me->query("mp") < 50 )
		return notify_fail("你的真气不够。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object(me, "你全身放松，坐下来开始运功疗伤。"  );
	tell_room(me->environment(),snprintf(msg,255,"%s吐出一口瘀血，脸色看起来好多了。" ,me->name() ), me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	
	return 1;
	
}

/*
static int do_jingheal(CChar * me, CContainer * ob)
{
	if ( !wizardp(me) )
		return notify_fail("你无权进行精的治疗！");
	
	if( !target )
		return notify_fail("你要用真气为谁疗伤？");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 150 )
		return notify_fail("你的真气不够。");
	
	message_vision( "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内...."
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。"  ,
		me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") )
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -10);
	me->set("mp_factor", 0l);
	
	return 1;
	
}
*/

FORCE_END;
