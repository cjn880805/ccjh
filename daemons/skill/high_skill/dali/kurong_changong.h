// kurong_changong.c 枯荣禅功

FORCE_BEGIN(CSkurong_changong);

virtual void create()
{
	CForce::create();

	set_name( "枯荣禅功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 150;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	if ( EQUALSTR(me->querystr("gender"), "无性"))
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣禅功。");
	
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
		//	|| me->query_skill("kurong_changong",1)
		|| me->query_skill("linji_zhuang",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("mizong_xinfa",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("xiantian_qigong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yijinjing",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("yunv_xinfa",1)
		|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学枯荣禅功？！");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("枯荣禅功只能用请教的来增加熟练度。");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");
	
	if (me->query_skill("kurong_changong", 1) < 20)
		return notify_fail("你的枯荣禅功修为还不够。");

	if( me->query("mp") < 50 ) 
		return notify_fail("你的真气不够。");
	
	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");
	
	tell_object( me, "你全身放松，坐下来开始运功疗伤。" );
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( ob != me )
		return notify_fail("你只能用枯荣禅功来提升自己的战斗力。");

	if( me->query("mp") < 150  )
		return notify_fail("你的内力不够。");
	if( me->querymap_temp("powerup") )
		return notify_fail("你已经在运功中了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "大理段家") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	skill = me->query_skill("force");
	me->add("mp", -50);
	me->receive_damage("hp", 0);
	message_vision( "$N暗自凝神，运起枯荣禅功，真气游遍全身。" ,me);
	
	start_powerup(me, skill, skill/3, skill/3, "你的枯荣禅功运行完毕，将内力收回丹田。");

	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

FORCE_END;
