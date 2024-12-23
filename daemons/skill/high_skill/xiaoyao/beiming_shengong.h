// beiming_shengong.h 北冥神功

void beiming_remove_effect(CContainer * ob, LONG amount, LONG param)
{
	CChar * me = (CChar *)ob;

	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");

	me->SendState(me);

	tell_object(me, "你的北冥神功运行完毕，将内力收回丹田。");
}

void del_sucked(CContainer * ob, LONG amount, LONG param)
{
	CChar * me = (CChar *) ob;
	me->delete_temp("sucked");
}

FORCE_BEGIN(CSbeiming_shengong);

virtual void create()
{
	CForce::create();

	set_name( "北冥神功");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("shield", do_shield);
	magic->name = "护盾术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "化功大法";
	magic->mp = 20;
	magic->ap = 35;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("neilisuck", do_neilisuck);
	magic->name = "吸功术";
	magic->mp = 20;
	magic->ap = 35;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}


int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("beiming_shengong", 1);
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。");

	if ( me->query_skill("bibo_shengong",1)
//	|| me->query_skill("beiming_shengong",1)
//	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("shenghuo_shengong",1)
	|| me->query_skill("xiantian_shengong",1)
	|| me->query_skill("yunv_xinjing",1)
	|| me->query_skill("tianlong_shengong",1)
	|| me->query_skill("wuzheng_xinfa",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) 
	|| me->query_skill("jiuyang_shengong",1) 
	|| me->query_skill("kurong_changong",1) ) 
		return notify_fail("你不先散了别派内功，怎能学北冥神功？");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("北冥神功只能用请教的来增加熟练度。");
}

//exert heal
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

	if (me->query_skill("beiming_shengong", 1) < 20)
		return notify_fail("你的北冥神功修为还不够。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你全身放松，坐下来开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);
	
	me->receive_curing("hp", 10 + me->query_skill("force") / 5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	return 1;
}

static int do_shield(CChar * me, CContainer * ob)
{
	if( ob != me ) 
		return notify_fail("你只能用北冥神功来提升自己的防御力。");

	if( me->query("mp") < 100  ) 
		return notify_fail("你的内力不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query_skill("beiming_shengong",1) < 40 ) 
		return notify_fail("你的北冥神功修为不够。");

	if( me->query_temp("shield") ) 
		return notify_fail("你已经在运功中了。");

	int skill = me->query_skill("force");
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	message_vision("$N双手平举过顶，运起北冥神功，全身笼罩在劲气之中！", me);
	me->set_temp("shield", 1);
	
	me->add_temp("apply/armor", skill * 2);
	me->call_out(beiming_remove_effect, skill, skill * 2);
	
	if( me->is_fighting() ) me->start_busy(2);
	return 1;
	
}

static int do_maxsuck(CChar * me, CContainer * ob)
{
	int sp, dp;
	int my_max, tg_max;
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("在这里不能攻击他人。");


	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( ! target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("你要吸取谁的丹元？");

    if (DIFFERSTR(target->querystr("race"), "人类"))
		return notify_fail("搞错了！只有人才能有丹元！");
	
    my_max = me->query("max_mp");
    tg_max = target->query("max_hp");
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！");
	
	if (me->query_weapon())
		return notify_fail("你必须空手才能施用北冥神功吸人丹元！");
	
    if( ! me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。");

	if( me->query_skill("beiming_shengong",1) < 90 )
		return notify_fail("你的北冥神功功力不够，不能吸取对方的丹元！");
	
	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。");

	if( me->query_skill("force") < me->query("max_mp") /10 )
		return notify_fail("你的内功太低了，再吸取也是徒劳。");

	if( target->query("max_mp") < 100 )
		return notify_fail( "%s丹元涣散，功力未聚，你无法从他体内吸取任何东西！", target->name());

	if( target->query("max_mp") < me->query("max_mp")/10 )
		return notify_fail( "%s的内功修为远不如你，你无法从他体内吸取丹元！", target->name());

	message_vision("$N全身一振，伸出右手，轻轻握在$n的手臂上。", me, target );
	
	if ( living(target))
	{
		target->kill_ob(me);		
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2 + 1;
	dp = target->query_skill("force") + target->query_skill("dodge") + 1;
	me->set_temp("sucked", 1);
		
	if (( random(sp) > random(dp) ) || ! living(target) )
	{
		tell_object(target, "你只觉全身乏力，全身功力如融雪般消失得无影无踪！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的丹元自手掌源源不绝地流了进来。", target->name()));
		
		int idx;
		if(me->query_temp("taozhuang/g_3"))//装备缀玉华袍后效果加倍
			idx=2;
		else
			idx=1;
			
		target->add("max_mp",  -idx*(1+(me->query_skill("beiming_shengong", 1)-90)/5) );
		me->add("max_mp",       idx*(1+(me->query_skill("beiming_shengong", 1)-90)/5) );
		if ( target->query("max_mp") <1) target->set("max_mp",0l);
		
		me->start_busy(7);
		target->start_busy(random(7));
		me->add("mp", -10);

		me->call_out(del_sucked, 10);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，机灵地溜了开去。", me, target);
		me->start_busy(7);
		me->call_out(del_sucked, 20);
	}

	return 1;
}

static int do_neilisuck(CChar * me, CContainer * ob)
{
	int sp, dp;
	char msg[255];
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");


	if(DIFFERSTR(me->querystr("family/family_name"), "逍遥派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( !target || target == me || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("你要吸取谁的内力？");
	
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！");
	
	if( me->query_skill("beiming_shengong",1) < 50 )
		return notify_fail("你的北冥神功功力不够，不能吸取对方的内力！");
	
	//46 修改，逍遥可以用武器吸人内力
	//if (me->query_weapon())
	//	return notify_fail("你必须空手才能施用北冥神功吸人内力！");
		
	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用北冥神功。");
	
	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s没有任何内力！",target->name());
	
	if( target->query("mp") < 60 )
		return notify_fail( "%s已经内力涣散，你已经无法从他体内吸取任何内力了！",target->name());
	
	message_vision("$N身法陡然加快，右掌直出，猛地对准$n的膻中大穴按了上去！" ,	me, target );
	
	if ( living(target) )
	{
		target->kill_ob(me);
	}
	
	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2 + 1;
	dp = target->query_skill("force") + target->query_skill("dodge") + 1;
	
	me->set_temp("sucked", 1);		
	
	if (( random(sp) > random(dp) ) || !target->Query(IS_LIVING) )
	{
		tell_object(target,  "你顿觉全身内力如水银般循孔飞泄而出！" );
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地流了进来。" ,target->name()));
		
		int idx;
		if(me->query_temp("taozhuang/g_3"))//装备缀玉华袍后效果加倍
			idx=2;
		else
			idx=1;

		target->add("mp", -idx*(me->query_skill("beiming_shengong", 1) + target->query("mp_factor")) );
		if ( target->query("mp") <1 )
			target->set("mp",0l);
		me->add("mp", idx*(me->query_skill("beiming_shengong", 1) + target->query("mp_factor")) );
		
		//只能吸有效等级的四倍
		int limit_force = me->query_skill("force") * 40;

		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);
				
		me->start_busy(random(5));
		target->start_busy(random(4));
		
		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision( "可是$p看破了$P的企图，机灵地闪了开去。" , me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

FORCE_END;
