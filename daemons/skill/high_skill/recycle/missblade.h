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
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, force,  parry, lvl;
	}action[7] = {
		{"$N使一招「春风拂人醉」，手中$w轻飘飘地向$n的$l斩去！",
		30, 10, 10, 0,},
		{"$N金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$n的$l",
		60,15,20,20,},
		{"$N身形一转，一招「飞花逐人香」$w刀光不定，斩向$n的$l",
		80,30,30,40,},
		{"$N舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$n的$l",
		120,45,	40, 60,},
		{"$N手中$w一晃，一招「倩影惹人怜」往$n的$l斜斜砍出一刀",
		160,60,50,80,},
		{"$N提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$n$l",
		200,75,60,100,},
		{"$N移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$n的$l",
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
			break;
		}
			
	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[][255] ={
		"$n使一招「春风拂人醉」，手中$w轻飘飘地向$N的$l斩去！",	
		"$n金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$N的$l",
		"$n身形一转，一招「飞花逐人香」$w刀光不定，斩向$N的$l",
		"$n舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$N的$l",
		"$n手中$w一晃，一招「倩影惹人怜」往$N的$l斜斜砍出一刀",
		"$n提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$N$l",
		"$n移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$N的$l",
	};

	if(! weapon) return 0;
	return parry_msg[random(7)];
}

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("相思刀法只有女子才能练。");

	if(me->query("max_mp") < 50)
		return notify_fail("你的内力不够，没有办法练相思刀法。");

	if(DIFFERSTR(me->query_skill_mapped("force"), "bingxin_jue"))
		return notify_fail("相思刀法必须配合冰心决才能练。");
	
	CContainer * weapon;

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("你必须先找一把刀才能练刀法。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if( DIFFERSTR(me->query_skill_mapped("force"), "bingxin_jue"))
		return notify_fail("相思刀法必须配合冰心决才能练。");

	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade") )
		return notify_fail("你必须先找一把刀才能练刀法。");

	if( me->query("hp") < 30
		||	me->query("mp") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习相思刀法。");

	me->receive_damage("hp", 25);
	me->add("mp", -5);
	message_vision("$HIG$N依相思之意舞了一遍相思刀法。", me);
	return 1;
}

static int do_xiangsi(CChar * me, CContainer * ob)
{
	CContainer * weapon = me->query_weapon();
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("「相思结」只能对战斗中的对手使用。");

	if (me->query_skill("blade") < 100)		
		return notify_fail("你的相思刀法还不够纯熟！");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");

	if (me->query("mp") < 250)
		return notify_fail("你的内力不够!");

	if(me->query_temp("using") == 1)
		return notify_fail("你正在使用「相思结」！");
		
	message_vision("$HIC$N收刀回旋,曼声清唱…………\n\n", me);
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
	
	Do_Attack(me, target, TYPE_REGULAR);
	
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
	
	message_vision("$HIB$N一刀挥出，像一道岁月的梦痕。\n$HIC弯弯秀刀如深深的眼，清清的眉。\n$HIY美丽的刀影，如情人的倩影；刀掠起，带着微微的香气与呻吟,\n$HIY刀弯处像处子的柔肩，刀落时，洒下些许绝代风华。\n$HIC----刀清艳。\n----一个凄落的人影。\n----一把惊艳的刀。\n$HIM一式「落花舞影」。",me,target);
	
	LONG ap = me->query("combat_exp")/2000 + me->query_skill("missblade",1);
	LONG dp = target->query("combat_exp") / 4000  ;
	
	if( dp < 1 )
		dp = 1;
		
	if( random(ap) > dp )
	{
		message_vision("$HIR$n稍不留神，被轻轻扫了一下。刀光漾映一片血红。\n",me,target);
		target->receive_damage("hp", random(ap * 2 - dp));
		target->receive_wound("hp", random(ap));
		me->add("mp", -200);
	}
	else 
	{
		message_vision("$HIR$n大惊之下，一个懒驴打滚，闪到一旁，虽然灰头土脸，命总算有了。\n",me,target);
		
		remove_effect(me);

		me->start_busy(random(2)+1);
		return;
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

	LONG damage = me->query_skill("dodge") - target->query_skill("dodge") + me->query_skill("blade") - target->query_skill("force");		
	
	if (damage<1)damage=1;
	
	message_vision("$HIR$N一声轻吟，动魄动心。\n$HIR$N玉颊很绯，很红，很艳；比平常更倦，更慵，更乏了。\n$HIB刀光倏没！\n$HIW刀光来的太快，而且又太轻柔。\n$HIG轻的就像一阵微风，柔的就像一抹月色:「风月无边」!\n$MAG$n遇到这么轻这么柔这么曼妙的刀法,一时也不只该如何抵御。\n",me,target);
	
	if( random(me->query("combat_exp")/250) > target->query("combat_exp")/400)
	{
		target->receive_damage("hp", damage );
		target->receive_wound("hp", random(damage));
		me->add("mp",-150);
		message_vision("$HIY结果$n身陷相思，被情所困,不得自拔。\n", me, target);
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
	
	message_vision("$HIY刀光连闪四下，疾地收回！\n$HIW刀仍在$N手中！\n", me, target);
	remove_effect(me);
	me->start_busy(random(3)+2);
}

SKILL_END;

