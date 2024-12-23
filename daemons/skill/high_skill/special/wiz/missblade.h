//missblade.h 相思刀法

SKILL_BEGIN(CSmissblade);

virtual void create()
{
	set_name( "相思刀法");

	Magic_t * magic;

	magic = add_magic("xiangsi", do_xiangsi);
	magic->name = "相思结";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("combineb", do_combineb);
	magic->name = "守宫刀";
	magic->mp = 250;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, force,  parry, lvl;
	}action[7] = {
		{"$N使一招「春风拂人醉」，手中$w轻飘飘地向$n斩去！",
		30, 10, 10, 0,},
		{"$N金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$n！",
		60,15,20,20,},
		{"$N身形一转，一招「飞花逐人香」$w刀光不定，斩向$n！",
		80,30,30,40,},
		{"$N舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$n！",
		120,45,	40, 60,},
		{"$N手中$w一晃，一招「倩影惹人怜」往$n斜斜砍出一刀！",
		160,60,50,80,},
		{"$N提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$n！",
		200,75,60,100,},
		{"$N移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$n！",
		240,90,70,120,},
	};
 
  	int level = me->query_skill("missblade", 1);
	for(int i = 7; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("damage", action[level].damage);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);

		if (me->query_temp("teapot/perform_combineb"))
			m_actions.set("action", "只见刀气纵横，卷荡四方！");

		if (me->query_temp("teapot/perform_combines"))
			m_actions.set("action", "刀剑交织，并袭而过！");
			
//		if (me->query_temp("teapot/perform_combines"))
//			m_actions.set("action", "只见剑气穿梭，剑意飞扬！");

			break;
		}
			
	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] ={
		"$n使一招「春风拂人醉」，手中$W轻飘飘地向$N的$l斩去！",	
		"$n金刃劈风，$W随著一招「远山伴人痴」由下而上撩往$N的$l",
		"$n身形一转，一招「飞花逐人香」$W刀光不定，斩向$N的$l",
		"$n舞动$W，一招「柳叶随人笑」迅捷无伦地劈向$N的$l",
		"$n手中$W一晃，一招「倩影惹人怜」往$N的$l斜斜砍出一刀",
		"$n提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$N$l",
		"$n移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$N的$l",
	};

	return parry_msg[random(7)];
}

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
/*
	if( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("相思刀法只有女子才能练。");

	if(me->query("max_mp") < 50)
		return notify_fail("你的内力不够，没有办法练相思刀法。");

	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("你必须先找一把刀才能练刀法。");

	return 1;
*/
	return 0;
}

virtual int practice_skill(CChar * me)
{
/*	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("你必须先找一把刀才能练刀法。");

	if( me->query("hp") < 100
		||	me->query("mp") < 50 )
		return notify_fail("你的内力或气不够，没有办法练习相思刀法。");

	me->receive_damage("hp", 100);
	me->add("mp", -50);
	message_vision("$HIG$N依相思之意舞了一遍相思刀法。", me);
	return 1;
*/
	return 0;
}

static int do_xiangsi(CChar * me, CContainer * ob)
{
	CContainer * weapon = me->query_weapon();
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	string msg;

	if( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("「相思结」只有女子才能使用。");

	if( !target || !me->is_fighting(target) )
		return notify_fail("「相思结」只能对战斗中的对手使用。");

	if (me->query_skill("blade",1) < 200)		
		return notify_fail("你的基本刀法还不够纯熟！");

	if (me->query_skill("missblade",1) < 200)		
		return notify_fail("你的相思刀法还不够纯熟！");

	//if (me->query_skill("music",1)<40)		
	//	return notify_fail("你并不精通音乐，不能使用此式！\n");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
		return notify_fail("你阅历太浅，无法体会到相思情意。");


	if (me->query("mp") < 250)
		return notify_fail("你的内力不够!");

	if(me->query_temp("using") == 1)
		return notify_fail("你正在使用「相思结」！");
		
	message_vision("$HIC$N收刀回旋,曼声清唱…………\n", me);
	me->start_busy(1);
	me->set_temp("using",1);
	target->start_busy(1);
	
	me->call_out(yearn2, 1, target->object_id());
	return 1;	
}			

static void remove_effect(CChar * me)
{
	if (me->query_temp("missblade/add1"))
	{
		me->add_temp("apply/attack", -me->query_skill("blade")/4);
		me->delete_temp("missblade/add1");
	}

	if (me->query_temp("missblade/add2"))
	{
		me->add_temp("apply/damage", -me->query_skill("blade")/4);
		me->delete_temp("missblade/add2");
	}
}

static void yearn2(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("$YEL只道不相思,相思令人老,\n", me);
	
	//if (random(target->query_skill("music",1))<random(me->query_skill("music",1)))
	//target->receive_damage("sen", 10);

	target->start_busy(1);
	me->start_busy(1);
	me->call_out(yearn3, 1, param1);
}

static void yearn3(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;

	message_vision("$YEL几番几思量,还是相思好......\n", me);
	//if (random(target->query_skill("perception",1))<random(me->query_skill("music",1)))
	//target->receive_damage("sen", 10);

	target->start_busy(1);
	me->start_busy(1);
	me->call_out(yearn4, 1, param1);
}

static void yearn4(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) return;
	
	message_vision("$HIW然后$n就见到一道刀光！\n$WHT刀光淡淡,从中冉冉落下一个人......\n$HIY那一刀刀意未尽......\n$YEL刀色淡淡,如远山的望眉,夕阳的依照\n$YEL刀光过处,灯火全熄,谁也见不到谁\n$CYN只有一只蜡烛仍亮\n$HIC蜡烛托在掌上,像一只蜻蜓落在荷叶上,不惊落一滴露珠。\n$HIC刀光映着烛光,烛光映在$N温柔的脸上,刀光闪在眸里。\n$HIC$N落在刀光烛火中，轻盈若诗，优美如梦。\n$HIW这个随着一片刀光一朵烛光飘下来的人竟然----「意中无人」!\n", me, target);
	
	if (random(target->query_skill("force")) < random(me->query_skill("force")) )
	{
		me->add_temp("apply/attack", me->query_skill("blade")/4);
		me->set_temp("missblade/add1", 1);		
	}
	
	if (random(target->query_skill("dodge")) < random(me->query_skill("missblade",1)))
	{
		me->add_temp("apply/damage", me->query_skill("blade")/4);
		me->set_temp("missblade/add2", 1);
	}

	target->start_busy(1);
	me->start_busy(1);
	
	if (random(2)==1) 
	{
		me->delete_temp("using");
	}
	
	me->call_out(yearn5, 1, param1);
}

static void yearn5(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

	message_vision("$HIC$N叹息出刀,\n$HIY刀光像一首动人的诗,\n$RED刀如梦。\n$BLU梦里花落。\n$HIR梦里花落知多少？\n$HIW----「梦里花落」就是这一刀!\n", me, target);
	
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	
	remove_effect(me);

	me->call_out(yearn6, 1, param1);	
}

static void yearn6(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

	me->delete_temp("using");
	
	message_vision("$HIB$N一刀挥出，像一道岁月的梦痕。\n$HIC弯弯秀刀如深深的眼，清清的眉。\n$HIY美丽的刀影，如情人的倩影；刀掠起，带着微微的香气与呻吟,\n$HIY刀弯处像处子的柔肩，刀落时，洒下些许绝代风华。\n$HIC----刀清艳。\n----一个凄落的人影。\n----一把惊艳的刀。\n$HIM一式「落花舞影」。\n",me,target);
	
	LONG ap = me->query("combat_exp")/2000 + me->query_skill("missblade",1);
	LONG dp = target->query("combat_exp") / 4000  ;
	
	if( dp < 1 )
		dp = 1;
		
	if( ap > dp )
	{
		message_vision("$HIR$n稍不留神，被轻轻扫了一下。刀光漾映一片血红。",me,target);
		int i;
		char msg[255];
		i=random(me->query("mp_factor")*15)+me->query_skill("blade")*4+me->query("level")*10+me->query_skill("missblade")*4;
		i=i/2+random(i);
		target->receive_damage("hp", i,me);
		message_vision(snprintf(msg,255,"$HIR$N受到了%d点的伤害！",i),target);
		
		//		target->receive_damage("hp", random(ap * 2 - dp)+800);
		//		target->receive_wound("hp", random(ap));
		me->add("mp", -200);
	}
	else 
	{
		message_vision("$HIR$n大惊之下，一个懒驴打滚，闪到一旁，虽然灰头土脸，命总算有了。\n",me,target);
		
		remove_effect(me);

		me->start_busy(random(2)+1);
	}

	me->call_out(yearn7, 1, param1);
}

static void yearn7(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}

//	LONG damage = me->query_skill("dodge") - target->query_skill("dodge") + me->query_skill("blade") - target->query_skill("force");		
//	if (damage<1)damage=1;
	
	message_vision("$HIR$N一声轻吟，动魄动心。\n$HIR$N玉颊很绯，很红，很艳；比平常更倦，更慵，更乏了。\n$HIB刀光倏没！\n$HIW刀光来的太快，而且又太轻柔。\n$HIG轻的就像一阵微风，柔的就像一抹月色:「风月无边」!\n$MAG$n遇到这么轻这么柔这么曼妙的刀法,一时也不只该如何抵御。\n",me,target);
	
	if( random(me->query("combat_exp")/250) > target->query("combat_exp")/400)
	{
//		target->receive_damage("hp", damage*3 );
//		target->receive_wound("hp", random(damage));
		me->add("mp",-150);
//		message_vision("$HIY结果$n身陷相思，被情所困,不得自拔。\n", me, target);
		int i;
		char msg[255];
		i=random(me->query("mp_factor")*20)+me->query_skill("blade")*6+me->query("level")*15+me->query_skill("missblade")*6;
		i=i/2+random(i);
		target->receive_damage("hp", i,me);
		message_vision(snprintf(msg,255,"$HIY结果$n身陷相思，被情所困,不得自拔。\n$HIR$n受到了%d点的伤害！",i),me,target);

	}
	else 
	{
		message_vision("$HIY但是$n经验老到,情急之中,反手打了自己一下，躲过了这缠绵的杀机。\n",me,target);
		target->receive_damage("hp", 10);
	}
	
	me->call_out(yearn8, 1, param1);	
}

static void yearn8(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(!target || ! me->is_fighting(target)) 
	{
		remove_effect(me);
		return;
	}
	
	message_vision("\n$HIY刀光连闪四下，疾地收回！\n$HIW刀仍在$N手中！\n", me, target);
	remove_effect(me);
	me->start_busy(random(3)+2);
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	CChar * target = NULL;
	string msg;
//	CContainer * weapon;

		target = victim;

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return "";	// Busy : Maybe Casting / Performming

	int skilla;
	skilla=me->query_skill("missblade",1);

	if( skilla < 40 )
		return "";	// Don't pef this if lv < 40.

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return "";	// Return;
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return "";
	}
	if (me->query_team() != mvs->query_team())
	{
		return "";
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return "";

	if (me->query_temp("teapot/love_combine_strike"))
		return "";
	
	CContainer * weapon2;
	weapon2 = mvs->query_weapon();
	if (!weapon2)
		return "";
	if ( DIFFERSTR(mvs->query_skill_mapped(weapon2->querystr("skill_type")), "misssword" ))
		return "";

	int skillb;
	skillb=mvs->query_skill("misssword",1);

	if( skillb < 40 )
		return "";

	mvs->set_temp("teapot/love_combine_strike",1);
	g_Combatd.Do_Attack(mvs,victim,CCombatd::TYPE_REGULAR);
	message_vision("\n$HIR$N剑势未弱，$n刀势又起！\n",mvs,me);
	int i;
	i=mvs->query_skill("misssword",1)+me->query_skill("missblade",1);
	i =i+random(mvs->query_skill("misssword",1)+me->query_skill("missblade",1));
	victim->receive_damage("hp",i );

	me->start_busy(0);
	mvs->start_busy(0);
	mvs->delete_temp("teapot/love_combine_strike");

	victim->SendState(victim);

	return "";

}

static int do_combineb(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob ==me )
		msg="123";

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if ( !(weapon = me->query_weapon()) )
		return notify_fail("你使用的武器不对。");

	if (weapon->query("apply/damage")<50)
		return notify_fail("此刀的杀气不够，无法被人力所激发。");

	if (me->query_skill("blade",1) < 200)		
		return notify_fail("你的基本刀法还不够纯熟！");

	int skilla;
	skilla=me->query_skill("missblade",1);

	if( skilla < 250 )
		return notify_fail("你的相思刀法极不够娴熟，无法催动刀气，纵横四方。");

	if( me->query("mp") < 1000)	
		return notify_fail("你的内力不足以催动刀气，纵横四方。");

	me->add("mp",-1000);

	string mvsname;
	string mvsid;
	mvsname=me->querystr("couple/name");
	mvsid=me->querystr("couple/id");

	if (!mvsname.length() || !mvsid.length())
	{
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");
	}

	CContainer * env;
	env=me->environment();
	CChar * mvs;
	mvs=(CChar * ) env->present(mvsid.c_str());

	if (!mvs || !mvs->is_fighting(target))
	{
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");
	}
	if (me->query_team() != mvs->query_team())
	{
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");
	}


	 if (mvs->is_busy() || mvs->query_temp("pending/exercising"))
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");

	
	CContainer * weapon2;

	if (! (weapon2 = mvs->query_weapon()) )
//		|| !weapon2->query("is_icesword") )
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");

	if (weapon2->query("apply/damage")<50)
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");


	int skillb;
	skillb=mvs->query_skill("misssword",1);

	if( skillb < 200 )
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");

	if( mvs->query("mp") < 1000)	
		return notify_fail("没有销魂剑的配合，纵然你功力再高，也无法使出守宫刀。");

	mvs->add("mp",-1000);

	message_vision("$N清啸一声，将全部内力贯注刀峰，刀气磅礴而出！",me);
	message_vision("\n$HIR$N和$n的身行突然交织在一起，越转越快！$GRN\n" ,mvs,me);

	me->set_temp("teapot/perform_combineb",1);
	mvs->set_temp("teapot/perform_combineb",1);

	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
//		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

		if(! target->is_fighting(me)) continue;

		g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);
	}

	me->delete_temp("teapot/perform_combineb");
	mvs->delete_temp("teapot/perform_combineb");

	me->start_busy(4);
	mvs->start_busy(4);

	return 1;
}



SKILL_END;


