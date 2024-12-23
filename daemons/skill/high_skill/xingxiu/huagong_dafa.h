// huagong_dafa.h 化功大法
FORCE_BEGIN(CShuagong_dafa);

virtual void create()
{
	CForce::create();

	set_name( "化功大法");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "自疗术";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "激励术";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("mpsuck", do_mpsuck);
	magic->name = "膻中吸功";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("maxsuck", do_maxsuck);
	magic->name = "化功";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("hpsuck", do_hpsuck);
	magic->name = "吸血补身";
	magic->mp = 10;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("suck", do_suck);
	magic->name = "隔物吸功";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("huo", do_huo);
	magic->name = "阴火幽燃";
	magic->mp = 120;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("化功大法只能用请教的来增加熟练度。");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("huagong_dafa", 1);
	int t = 1, j;

	if(i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学化功大法。");

	if(i<=100)
	{
		if (i > 10 && - me->query("repute") < t * 100) 
			return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}
	else
	{
		if (- me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}

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
		|| me->query_skill("shenghuo_shengong",1)
		|| me->query_skill("kurong_changong",1)
		|| me->query_skill("bibo_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("xuantian_shengong",1) )
		
		return notify_fail("你不先散了别派内功，怎能学化功大法？！");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "force"; }

static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？");

    if (me->query_skill("huagong_dafa", 1)<20)
		return notify_fail("你的化功大法修为还不够。");
	if( me->query("mp") < 50 )
		return notify_fail("你的真气不够。");

	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("你已经受伤过重，一运真气肯定毒气攻心死掉！");

	tell_object(me, "你全身放松，坐下来开始运毒疗伤。");
	tell_room(me->environment(), snprintf(msg, 255, "$HIR%s吐出一口冒白烟的毒血，脸色看起来好多了。", me->name()), me);

	me->receive_curing("hp", 10 + me->query_skill("force")/6 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
    me->start_busy(5);
	return 1;
}

static int do_mpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];	
	int sp, dp;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if ( target == me ) return notify_fail("不能吸自己的内力，也不需要吸自己的内力。");
	
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR咦，有内力的人都去了哪里了？");
	
	if( me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");
	
	if ( me->query_temp("sucked") )
		return notify_fail("$HIR你刚刚吸取过内力，你想丹田爆炸吗！");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_weapon() )
		return notify_fail("你必须空手才能施用化功大法吸人内力！");
	
	if( me->query_skill("huagong_dafa",1) < 60 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的内力！");
	
	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。");
	
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
    dp = target->query_skill("force") + target->query_skill("dodge");
	
	me->set_temp("sucked", 1);		
	
    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地流了进来。", target->name()));
		
		target->add("mp", -1*(me->query_skill("huagong_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
		me->add("mp", me->query_skill("huagong_dafa", 1) + target->query("mp_factor") );
		
		//只能吸有效等级的四倍
		int limit_force = me->query_skill("force") * 40;
		
		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);
		
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
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	
	
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren" ))
		return notify_fail("你要化解谁的丹元？");
	
	if( me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");
	
	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚化解过丹元！");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_weapon() )
		return notify_fail("你必须空手才能施用化功大法化人丹元！");
	
	if( me->query_skill("huagong_dafa",1) < 90 )
		return notify_fail("你的化功大法功力不够，不能化解对方丹元！");
	
	if( me->query("mp") < 500 )
		return notify_fail("你的内力不够，不能使用化功大法。");
	
	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s已经没有任何内力，废人一个！哈哈哈！", target->name());
	
    if( target->query("max_mp") < 10 )
		return notify_fail("%s已经内力尽失，废人一个了！哈哈哈！", target->name());
	
	message_vision("$HIR$N哈哈一笑，右掌突然燃起绿火，一把扣住$n的脉门！", me, target );
	
	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
	
    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "$HIR你正感觉不妙，对方手上的剧毒已经直逼了过来！");
		tell_object(me, snprintf(msg, 255, "$HIR你运功把毕生所练的剧毒往%s身上逼去。", target->name()));
		
		if ( target->Query(IS_LIVING) )
		{
			if( !target->is_killing(me) ) target->kill_ob(me);
		}
		
		sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("huagong_dafa",1)/2;
		dp = target->query_skill("force") + target->query_skill("dodge") + 1;
		
		me->set_temp("sucked", 1);		
		
		if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
		{
			tell_object(target, "$HIR你只觉剧毒侵入经脉，自己半生辛苦所练的内功丹元竟然就此散去，不禁又惊又怒。！");
			tell_object(me, snprintf(msg, 255, "$HIR你觉得%s的丹元被你的毒性化的无影无踪，不禁内心大是畅快。",  target->name()));
			
			int addmp = 1 + (me->query_skill("poison", 1) - 20) / 2;
			if(addmp < 0) addmp = 0;

			target->add("max_mp", - addmp);
			if ( target->query("max_mp") <1) target->set("max_mp",0l);
			
			me->start_busy(3);
			target->start_busy(random(3));
			me->add("mp", -50);
			
			me->call_out(del_sucked, 4);
		}
		else
		{	
			message_vision("可是$p看破了$P的企图，内力猛地一震，借势溜了开去。", me, target);
			me->start_busy(3);
			me->call_out(del_sucked, 10);
		}
	}

	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;

	if( me->query("mp") < 100)
		return notify_fail("你的内力不够。");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->querymap_temp("powerup"))
		return notify_fail("你已经在运功中了。");

	skill = me->query_skill("force");

	message_vision("$N舌尖一咬，喷出一口毒血，运起化功大法已将全身潜力尽数提起！", me);

	start_powerup(me, skill, skill/3, skill/3, "你的化功大法运行完毕，将内力收回丹田。");

	me->add("mp", -100);		//add by Lanwood 2000-12-25
	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

static int do_hpsuck(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];
	int sp, dp;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if ( target == me ) return notify_fail("疯了吗？企图吸自己的血？！你是不是毒性入脑了？。");

	if( (me->environment())->query("no_fight") )
		return notify_fail("在这里不能攻击他人。");

	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR奇怪，有血液的人都去了哪里了！！");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸过血！");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query_weapon() )
		return notify_fail("你必须空手才能抓住对手吸血！");

	if( me->query_skill("huagong_dafa",1) < 30 )
		return notify_fail("你的化功大法功力不够，还不能把吸的血为己所用。");

	if( me->query("mp") < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。");

    if( target->query("hp") < 30 )
		return notify_fail( "%s已经失血过多，你已经无法从他体内吸血液了！", target->name());

	message_vision("$HIR$N突然满脸狰狞，双手一抱，白深深的牙齿朝$n的脖子咬了过来！", me, target );

	if ( target->Query(IS_LIVING) )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	int lvl1 = me->query_skill("zhaixinggong", 1);
	int lvl2 = me->query_skill("feixing_shu", 1);

    sp = me->query_skill("force") + me->query_skill("dodge") + (lvl1 > lvl2 ? lvl1 : lvl2) /2;
    dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "$HIR你全身血液自颈部伤口奔涌而出，脑里一晕，只觉天旋地转！");
		tell_object(me, snprintf(msg, 255, "你觉得的对方的血自口里源源不绝地流进了肚子里，化作一股暖流。", target->name()));
		target->apply_condition("xx_poison", random(me->query_skill("poison",1)/20) + 1 +
			target->query("condition/xx_poison"));
		target->receive_damage("hp", me->query_skill("huagong_dafa", 3) );
		me->add("hp", me->query_skill("huagong_dafa", 3) );
		me->add("eff_hp", me->query_skill("huagong_dafa", 3)*2/3 );
		if ( me->query("eff_hp") > me->query("max_hp") ) me->set("eff_hp", me->query("max_hp"));

		if( target->query_combat_exp() >= me->query_combat_exp() )
			me->add("combat_exp",4);

        me->start_busy(2);
        target->start_busy(random(3));
		me->add("mp", -5);

		me->call_out(del_sucked, 1);
	}
	else
	{	
		message_vision("可是$p看破了$P的企图，内力猛地一震，借势溜了开去。", me, target);
        me->start_busy(2);
		me->call_out(del_sucked, 2);
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

    if ( target == me ) return notify_fail("自己的内力吸了也白吸，你不会不知道吧？");
	if( ! target || EQUALSTR(target->querystr("id"), "mu ren") )
		return notify_fail("$HIR咦，有内力的人都去了哪里了？");
	if( (me->environment())->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( ! (ob = me->query_weapon()) )
		return notify_fail("你没有用兵器！");

	if( ! (tar = target->query_weapon()) )
		return notify_fail("你的对手没有用兵器！");

	if( me->query_skill("huagong_dafa",1) < 60 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的内力！");

	if( me->query("mp") < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。");

	if( target->query("max_mp") <= 0 )
		return notify_fail( "%s没有任何内力！", target->name());

    if( target->query("mp") < 60 )
		return notify_fail( "%s已经内力涣散，你已经无法从他体内吸取任何内力了！", target->name());

	message_vision(snprintf(msg, 255, "$N突然将%s朝$n的%s压上去！", ob->name(), tar->name()), me, target);
	
	if( !target->is_killing(me) ) target->kill_ob(me);

	int lvl1 = me->query_skill("zhaixinggong", 1);
	int lvl2 = me->query_skill("feixing_shu",1);

    sp = me->query_skill("force") + me->query_skill("dodge") + (lvl1 > lvl2 ? lvl1 : lvl2) /2;
    dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

    if (( random(sp) > random(dp) ) || ! target->Query(IS_LIVING) )
	{
		tell_object(target, "你顿时觉得全身内力如水银般循着兵器飞泄而去！");
		tell_object(me, snprintf(msg, 255, "你觉得%s的内力自手掌源源不绝地流了进来。", target->name()));

		target->add("mp", -1*(me->query_skill("huagong_dafa", 1) + target->query("mp_factor")) );
        if ( target->query("mp") <1 ) target->set("mp",0l);
		me->add("mp", me->query_skill("huagong_dafa", 1) + target->query("mp_factor") );
		
		//只能吸有效等级的四倍
		int limit_force = me->query_skill("force") * 40;

		if (me->query("mp") > limit_force)
			me->set("mp", limit_force);

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

static int do_huo(CChar * me, CContainer * ob)
{
	if( me->query("mp") < 150)
		return notify_fail("你的内力不够。");

	if(me->environment()->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方施放「阴火幽燃」!");

	if(!me->is_fighting())
		return notify_fail("只能在战斗中施放「阴火幽燃」。");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") )
		return notify_fail("你依稀还记得「阴火幽燃」这一招，可是却早已忘却了如何使用。");

	if(me->query_temp("huagong/huo"))
		return notify_fail("你的内息不足以同时支撑两堆阴火。");

	if(me->query_skill("huagong_dafa",1) < 180 )
		return notify_fail("你的化功大法功力不够，内息无法施放出「阴火幽燃」。");

	message_vision("\n$HIR$N舌尖一咬，喷出一口毒血，运起化功大法已将全身潜力尽数提起。\n一簇火焰徐徐自双掌升起，高约尺许，色作纯碧，鬼气森森，和寻常火焰大异！", me);

	int skill = me->query_skill("huagong_dafa", 1);

	me->add("mp", -120);
	me->set_temp("huagong/huo",1);
	me->call_out(remove_effect, skill/2);
	me->start_busy(2);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
    char msg[255];
	CChar * me = (CChar *)ob;  
	me->delete_temp("huagong/huo");
	tell_room(me->environment(), snprintf(msg, 255,"\n$HIW%s身旁的一簇阴火突然爆出几朵火花，慢慢的松散黯淡下来，熄灭了。\n" ,me->name()));
}
FORCE_END;