//oho出品，质量不保证

// xixing_dafa.h 吸星大法
FORCE_BEGIN(CSxixing_dafa);

virtual void create()
{
	CForce::create();

	set_name( "吸星大法");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("mpsuck", do_mpsuck);
	magic->name = "膻中吸功";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "天灵吸功";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("mpsucks", do_mpsucks);
	magic->name = "引功入地";
	magic->mp = 5;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;


	magic = add_magic("suck", do_suck);
	magic->name = "隔物吸功";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("roar", do_roar);
	magic->name = "暗狱惊雷";
	magic->mp = 1000;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("吸星大法只能用请教的来增加熟练度。");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("xixing_dafa", 1);
	int t = 1, j;

	if(i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "无性") && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的吸星大法。");

	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学吸星大法。");


	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("taiji_shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1) 
		|| me->query_skill("huagong_dafa",1) 	
		|| me->query_skill("kurong_changong",1) )				
		
		return notify_fail("你不先散了别派内功，怎能学吸星大法？！");

	return 1;
}

int valid_enable(string usage) { return usage == "force"; }

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

    if (me->query_skill("xixing_dafa", 1)<20)
		return notify_fail("你的吸星大法修为还不够。");
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！");

	tell_object(me, "你全身放松，坐下来开始运功疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "%s吐出一口瘀血，脸色看起来好多了。", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(4);
	return 1;
}

static int do_mpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( target == me ) return notify_fail("不能吸自己的内力。");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("你要吸取谁的内力？");

	if( me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！");

	if( me->query_weapon() )
		return notify_fail("你必须空手才能施用吸星大法吸人内力！");

	if( me->query_skill("xixing_dafa",1) < 60 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！");

	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用吸星大法。");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s没有任何内力！", target->name());

    if( target->query("mp") < 60 )
		return notify_fail("%s已经内力涣散，你已经无法从他体内吸取任何内力了！", target->name());

	message_vision("$N一张脸突然变得惨白，右掌直出，猛地对准$n的膻中大穴按了上去！", me, target );

    if ( target->Query(IS_LIVING))
    { 
		if( !target->is_killing(me) ) target->kill_ob(me); 
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地流了进来。", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
//		me->add("mp", me->query_skill("xixing_dafa", 1) + target->query("mp_factor") );

		//只能吸有效等级的四倍
//		int limit_force = me->query_skill("force") * 40;

//		if (me->query("mp") > limit_force)
//			me->set("mp", limit_force);

        me->start_busy(4);
		target->start_busy(random(4));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，机灵地闪了开去。", me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static int do_maxsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;
	int my_max, tg_max;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( target == me ) return notify_fail("不能对自己使用。");

	if( me->environment()->query("no_fight") )
		return notify_fail("在这里不能攻击他人。");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("你要吸取谁的丹元？");
	if (DIFFERSTR(target->querystr("race"), "人类"))
		return notify_fail("搞错了！只有人才能有丹元！");

    my_max = me->query("max_mp");
    tg_max = target->query("max_mp");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！");

	if( me->query_weapon() )
		return notify_fail("你必须空手才能施用吸星大法吸人丹元！");

    if( me->query_skill("xixing_dafa",1) < 90 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的丹元！");

	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用吸星大法。");

	if( me->query_skill("force") < me->query("max_mp") /10 )
		return notify_fail("你的内功太低了，再吸取也是徒劳。");

	if( target->query("max_mp") < 100 )
		return notify_fail(	"%s丹元涣散，功力未聚，你无法从他体内吸取任何东西！",  target->name());

    if( target->query("max_mp") < me->query("max_mp")/10 )
		return notify_fail( "%s的内功修为远不如你，你无法从他体内吸取丹元！",  target->name());

	message_vision("$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！", me, target );

	if ( target->Query(IS_LIVING) )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的丹元自手掌源源不绝地流了进来。",  target->name()));

        target->add("max_mp",  -1*(1+(me->query_skill("xixing_dafa", 1)-90)/5) );
//        me->add("max_mp",       1*(1+(me->query_skill("xixing_dafa", 1)-90)/5) );
        if ( target->query("max_mp") <1) target->set("max_mp",0l);

        me->start_busy(7);
        target->start_busy(random(7));
        me->add("mp", -10);

		me->call_out(del_sucked, 10);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，内力猛地一震，借势溜了开去。", me, target);
        me->start_busy(7);
		me->call_out(del_sucked, 20);
	}

	return 1;
}





static int do_suck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;
	CContainer * tar;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if ( target == me ) return notify_fail("你不能吸自己的内力。");
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("你要吸取谁的内力？");
	if( (me->environment())->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！");

	if( ! (ob = me->query_weapon()) )
		return notify_fail("你没有用兵器！");

	if( ! (tar = target->query_weapon()) )
		return notify_fail("你的对手没有用兵器！");

	if( me->query_skill("xixing_dafa",1) < 60 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！");

	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用吸星大法。");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s没有任何内力！", target->name());

    if( target->query("mp") < 60 )
		return notify_fail( "%s已经内力涣散，你已经无法从他体内吸取任何内力了！", target->name());

	message_vision(snprintf(msg, 255, "$N突然将%s朝$n的%s压上去！", ob->name(), tar->name()), me, target);
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你全身内力如水银般循孔从手掌飞泄而出！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地流了进来。", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
//		me->add("mp", me->query_skill("xixing_dafa", 1) + target->query("mp_factor") );

	    me->start_busy(3);
		target->start_busy(random(3));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，机灵地闪了开去。", me, target);
		me->start_busy(3);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static void del_sucked(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;

	if ( me->query_temp("sucked") )
		me->delete_temp("sucked");
}

static int do_mpsucks(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *)ob;



	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("你要引导谁的内力？");

	if( me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！");

	if( me->query_weapon() )
		return notify_fail("你必须空手才能施用吸星大法引导别人内力！");

	if( me->query_skill("xixing_dafa",1) < 10 )
		return notify_fail("你的吸星大法功力不够，不能引导对手的内力！");

	if( me->query("mp") < 5 )
		return notify_fail("你的内力不够，不能使用吸星大法。");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s没有任何内力！", target->name());

    if( target->query("mp") < 10 )
		return notify_fail("%s已经内力涣散，你已经无法从他体内吸取任何内力了！", target->name());

	message_vision("$N傲然一笑，右掌直出，猛地对准$n的膻中大穴按了上去！", me, target );

    if ( target->Query(IS_LIVING))
    { 
		if( !target->is_killing(me) ) target->kill_ob(me); 
	}

    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing_dafa",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge") + 1;

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你顿觉不妙，全身功力都仿佛在流失！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地传入地下。", target->name()));

		target->add("mp", -1*(me->query_skill("xixing_dafa", 3) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);


        me->start_busy(4);
		target->start_busy(random(4));
        me->add("mp", -7);

		me->call_out(del_sucked, 2);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，机灵地闪了开去。", me, target);
		me->start_busy(4);
		me->call_out(del_sucked, 4);
	}

	return 1;
}

static int do_roar(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 1000 )
       return notify_fail("你的内力不够。");

    if( (me->environment())->query("no_fight") )
       return notify_fail("在这里不能攻击他人。");

    int skill = me->query_skill("force");

    me->add("mp", -800);
    me->receive_damage("hp", 10);

    me->start_busy(5);
    message_vision("$HIY$N深深地吸一囗气，将全身真气汇聚，发出一声惊天动地的巨吼！\n$COM", me);

    DTItemList search;
	POSITION p;
	CContainer * obj;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		who = (CChar *)obj;
		if( skill/2 + random(skill/2) < who->query("con") * 2 )
			continue;
					
		((CChar *)obj)->set_killer(me);
		me->set_killer((CChar *)obj);
		
		int damage = skill - (who->query("max_mp") / 10);
		if( damage > 0 )
		{
			who->receive_damage("hp", damage * 2, me);
			if( who->query("mp") < skill * 2 )
            who->receive_wound("hp", damage, me);
			tell_object(who, "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！");
       }
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//场景内所有人都kill本人。
      
	return 1;
}

virtual void skill_improved(CChar * me)
{
    if ((me->query_skill("xixing_dafa",1) == 100) ||
        (me->query_skill("xixing_dafa",1) == 110) ||
        (me->query_skill("xixing_dafa",1) == 120) ||
        (me->query_skill("xixing_dafa",1) == 130) ||
        (me->query_skill("xixing_dafa",1) >= 140))
    {
        tell_object(me, "你体内的异种真气开始互相冲突了。");
        me->apply_condition("congtu",1000);
    }
}

FORCE_END;