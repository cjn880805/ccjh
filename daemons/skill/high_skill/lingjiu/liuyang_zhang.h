// liuyang_zhang.h 六阳掌
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSliuyang_zhang);

virtual void create()
{
	set_name( "六阳掌");
	set("valid_force", "bahuang_gong");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("jie", do_jie);
	magic->name = "解生死符";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("zhong", do_zhong);
	magic->name = "种生死符";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") || EQUALSTR(arg, "beiming_shengong"))
		return 1;
	
	return notify_fail("六阳掌必须与专门的内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「落日熔金」，左掌叠于右掌之上，劈向$n", 130, 20,0 , 0,"瘀伤",},
		{"$N一招「安禅制毒龙」，面色凝重，双掌轻飘飘地拍向$n", 150, 10, 30, 20,"内伤",},
		{"$N一招「日斜归路晚霞明」，双掌幻化一片掌影，将$n笼罩于内。", 150, 30, 35,30 ,"瘀伤",},
		{"$N一招「阳关三叠」，向$n的$l连击三掌", 200, 25, 50, 40,"瘀伤",},
		{"$N一招「阳春一曲和皆难」，只见一片掌影攻向$n", 250, 20, 10, 40,"瘀伤",},
		{"$N双掌平挥，一招「云霞出海曙」击向$n", 300, 25, 50, 60,"瘀伤",},
		{"$N一招「白日参辰现」，只见一片掌影攻向$n",350 , 30,80 , 70,"内伤",},
		{"$N左掌虚晃，右掌一记「云霞出薛帷」击向$n的头部", 350, 30, 90, 80,"瘀伤",},
		{"$N施出「青阳带岁除」，右手横扫$n的$l，左手攻向$n的胸口", 400, -10, 90, 90,"瘀伤",},
		{"$N施出「阳歌天钧」，双掌同时击向$n的$l", 450, -10, 120,100 ,"瘀伤",},
	};
	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("liuyang_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/灵鹫宫/六阳掌/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/灵鹫宫/六阳掌/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/灵鹫宫/六阳掌/damage")+100) * action[level].damage/100);
			
			break;
		}
	}
	
	return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/灵鹫宫/六阳掌/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/六阳掌/force"));
			if(me->query("skill_pro/灵鹫宫/六阳掌/force_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/六阳掌/force",1);
				me->set("skill_pro/灵鹫宫/六阳掌/force_point",1);
				tell_object(me,"\n$HIR你的六阳掌配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/灵鹫宫/六阳掌/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/六阳掌/dodge"));
			if(me->query("skill_pro/灵鹫宫/六阳掌/dodge_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/六阳掌/dodge",1);
				me->set("skill_pro/灵鹫宫/六阳掌/dodge_point",1);
				tell_object(me,"\n$HIR你的六阳掌使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/灵鹫宫/六阳掌/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/六阳掌/damage"));
			if(me->query("skill_pro/灵鹫宫/六阳掌/damage_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/六阳掌/damage",1);
				me->set("skill_pro/灵鹫宫/六阳掌/damage_point",1);
				tell_object(me,"\n$HIR你的六阳掌威力更大了。\n");
			}
		}
	}
	if( damage < 100 ) return 0;
	
	if( random(damage/2) > victim->query_con() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return   "$N双掌挥动「乓」的一声，$n口吐鲜血象一捆稻草飞了出去！"  ;
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "strike"; 
}

virtual int valid_combine(string combo) { return combo=="zhemei_shou"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练天山六阳掌必须空手。");
	if ( me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练六阳掌。");
	
	
	
	CChar * who = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who && me->query_skill("liuyang_zhang", 1)>=350)
		return notify_fail("以你伴侣目前的功力，天山六阳掌已经无法继续指点了。");
	
	if(me->query_skill("liuyang_zhang", 1)>=350)
		return notify_fail("以你目前的功力，天山六阳掌已经无法继续请教了。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练天山六阳掌。");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}



//perform 
static int do_jie(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( !target)
		return notify_fail("你要给谁解生死符。");
	
	if(target == me)
		return notify_fail("你无法给自己解生死符！");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query_skill("bahuang_gong", 1) < 40 )
		return notify_fail("你的八荒六合功不够娴熟，不能解生死符。");
	
	if(  me->query_skill("liuyang_zhang", 1) < 40 )
		return notify_fail("你的天山六阳掌不够娴熟，不能解生死符。");
	
	if(  me->query("mp" ) < 200 )
		return notify_fail("你现在内力太弱，不能解生死符。");
	
	me->add("mp", -200);
	target->apply_condition("ss_poison", 0);
	
	message_vision("$N使出天山六阳掌，按解生死符的手法，快速的拍向$n的周身大穴。", me, target);
	return 1;
	
}

static int do_zhong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(!target || !me->is_fighting(target) )
		return notify_fail("生死符只能种在对手身上。");
	
	if(  me->query_skill("bahuang_gong", 1) < 60 )
		return notify_fail("你的八荒六合功不够娴熟，不能种生死符。");
	
	if(  me->query_skill("liuyang_zhang", 1) < 60 )
		return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query("mp" ) < 100 )
		return notify_fail("你现在内力太弱，不能种生死符。");
	
	//	if (! me->present("jiudai") )
	//        return notify_fail("你身上没有酒袋，不能化水为冰。");
	
	me->add("mp", -100);
	
	msg =   "$N化水为冰，凝于掌中，轻飘飘地拍向$n。\n";
	
	me->start_busy(1);
	if( random(  me->query_skill("liuyang_zhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		if(target->query_temp("apply/no_种生死符")&& !random(2))
			msg += "可是$p急忙闪在一旁，躲了开去。";
		else
		{
			msg += " 结果$P在$p身上种下了生死符！"  ;
			target->receive_damage("hp", me->query_skill("bahuang_gong",1));
			target->receive_wound("hp",15 + random(10));
			target->receive_wound("hp", 10);
			target->apply_condition("ss_poison", random(me->query_skill("liuyang_zhang",1)*3) +
				target->query("condition/ss_poison"));
			me->start_busy(random(2));
		}
	}
	else 
	{
		msg += "可是$p急忙闪在一旁，躲了开去。"  ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	target->start_busy(1 + random(2));
	return 1;
}

SKILL_END;




