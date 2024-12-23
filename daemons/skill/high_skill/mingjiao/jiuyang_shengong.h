
// jiuyang_shengong.h 九阳神功
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSjiuyang_shengong);

virtual void create()
{
	CForce::create();

	set_name( "九阳神功");

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
	int lvl =  me->query_skill("jiuyang_shengong", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。");
	
	if ( me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。");
	
	return 1;
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 30)
		return notify_fail("你的九阳神功修为还不够。");
	if(  me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	if(  me->query("eff_hp") ==  me->query("max_hp"))
		return notify_fail("你现在没有受任何伤。");
	
	if(  me->query("eff_hp") <  me->query("max_hp") / 7 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object( me, "你运起 九阳神功 开始疗伤。" );
	tell_room(me->environment(),snprintf(msg,255,"%s运起 九阳神功 开始疗伤。",me->name() ), me);
	
	me->receive_curing("hp", 10 +  me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
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
		return notify_fail("你不可以为自己疗伤。");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 40)
		return notify_fail("你的九阳神功修为还不够。");
	
	if(  me->query("max_mp") < 300 )
		return notify_fail("你的内力修为不够。");
	
	if(  me->query("mp") < 100 )
		return notify_fail("你的真气不够。");
	
	if(  target->query("eff_hp") <  target->query("max_hp") / 9 )
		return notify_fail("%s已经受伤过重，经受不起你的真气震荡！",target->name());

	if( target->query("eff_hp") >= target->query("max_hp"))
		return notify_fail("%s没有受伤。", target->name());
	
	message_vision("$N盘膝坐下来运起九阳神功，缓缓将手掌贴在$n胸前，将真气缓缓输入$n体内...不久，$N收回双掌，$n吐出一口瘀血，感觉伤势好多了。"  ,	me, target );
	
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
	me->add("combat_exp", addexp);
	
	tell_object(me, snprintf(expmsg, 80, "你的修行提高了%ld点！声望提高了0点！", addexp));
	//疗伤经验奖励

	me->start_busy(5);
	target->start_busy(5);

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
	
	message_vision("$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。"  ,	me, target );
	
	target->receive_curing("hp", 10 +  me->query_skill("force")/3 );
	target->add("hp", 10 +  me->query_skill("force")/3 );
	if(  target->query("hp") >  target->query("eff_hp") )
		target->set("hp",  target->query("eff_hp"));
	
	me->add("mp", -10);
	me->set("mp_factor", 0l);
	
	return 1;
	
}
*/

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "明教")))
		return notify_fail("你不是明教弟子不能使用九阳神功.九阳神功博大精深, 非少林弟子不传, 真不知道你是怎么学会的!善哉, 善哉, 阁下在德行方面是否需要再好好学一学.");

	if( ob != me ) 
		return notify_fail("你只能用九阳神功来提升自己的战斗力。");
	
	if(  me->query("mp") < 100  ) 
		return notify_fail("你的内力不够。");
	if(  me->querymap_temp("powerup") ) 
		return notify_fail("你已经在运功中了。");
	
	skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	
	message_vision(	"$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起。 "  , me);
		
	start_powerup(me, skill, skill/3, skill/3, "你的九阳神功运行完毕，将内力收回丹田。");
	
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
	
}

int practice_skill(CChar * me)
{
	return notify_fail("只能通过请教来提高!");
}

FORCE_END;
