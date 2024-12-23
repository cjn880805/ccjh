//rouqing_zhi.h 柔情指
//秦波 2002、1、16

SKILL_BEGIN(CSrouqing_zhi);


virtual void create()
{
	set_name( "柔情指");
	
	Magic_t * magic;
	set("diff",150);
	
	magic = add_magic("caiyue", do_caiyue);
	magic->name = "菊楼采月";
	magic->mp = 300;
	magic->ap=200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") )
		return 1;
	
	return notify_fail("柔情指必须与灵鹫独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[4] = {
		{"$N左手一挥，一招「杏台望月」右手点向$n$l",100, -40, 220, 0,},
		{"$N使一招「雪桥翦梅」，身影忽前忽后，突然一转身左手往$n的$l点去",240, -50, 340,  39,},
		{"$N身法稍顿，左手一扬使出「柳亭簪花」往$n的$l点去",410, -55, 450, 69,},
		{"只见$N纤腰一摆，陡然滑出数尺，右手顺着来势一招「桃坟扑蝶」往$n的$l点去",500, -70, 650, 121,},
	};
	
	int level = me->query_skill("rouqing_zhi", 1);
	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/灵鹫宫/柔情指/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/灵鹫宫/柔情指/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/灵鹫宫/柔情指/damage")+100) * action[level].damage/100);
			
			break;
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
			me->add("skill_pro/灵鹫宫/柔情指/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/柔情指/force"));
			if(me->query("skill_pro/灵鹫宫/柔情指/force_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/柔情指/force",1);
				me->set("skill_pro/灵鹫宫/柔情指/force_point",1);
				tell_object(me,"\n$HIR你的柔情指配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/灵鹫宫/柔情指/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/柔情指/dodge"));
			if(me->query("skill_pro/灵鹫宫/柔情指/dodge_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/柔情指/dodge",1);
				me->set("skill_pro/灵鹫宫/柔情指/dodge_point",1);
				tell_object(me,"\n$HIR你的柔情指使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/灵鹫宫/柔情指/damage_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/柔情指/damage"));
			if(me->query("skill_pro/灵鹫宫/柔情指/damage_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/柔情指/damage",1);
				me->set("skill_pro/灵鹫宫/柔情指/damage_point",1);
				tell_object(me,"\n$HIR你的柔情指威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ((int)me->query("mp") < 20)
		return notify_fail("你的内力不够练柔情指。");
	if (DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("柔情指是只有女子才能练的武功。");
	if ( DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫"))
		return	notify_fail("柔情指必须是灵鹫宫弟子方可以练习");
	if ((int) me->query_skill("rouqing_zhi", 1) > 99)
		return notify_fail("你已经无法通过自我修行来提升了柔情指。");
	if (me->query_skill("bahuang_gong", 1) < (40+me->query_skill("rouqing_zhi", 1)))
		return notify_fail("你的八荒六合唯我独尊功火候不够，无法练习柔情指。");
	if (me->query_skill("finger", 1) < me->query_skill("rouqing_zhi", 1))
		return notify_fail("你的基本指法火候不够，无法练习柔情指。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练柔情指必须空手。");
	if (DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("柔情指是只有女子才能学的武功。");
	if ( DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫"))
		return	notify_fail("柔情指必须是灵鹫宫弟子方可以学习");
	if (me->query_skill("bahuang_gong", 1) < 80)
		return notify_fail("你的八荒六合唯我独尊功火候不够，无法学柔情指。");
	if (me->query_skill("finger", 1) < 80)
		return notify_fail("你的基本指法火候不够，无法学柔情指。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练柔情指。");
	if ((int) me->query_skill("rouqing_zhi", 1) > 300)
		return notify_fail("你已经无法通过请教来提升了柔情指。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry";  }

static int do_caiyue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	int harm;
	string msg;
	char cmd[255];
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if(! target || ! me->is_fighting(target))		
		return notify_fail("只能对战斗中的敌人使用！");
	
	if(me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!");
	
	if ( !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫")))
		return	notify_fail("［菊楼采月］必须是灵鹫宫弟子方可以使用");
	
	if(me->query_skill("bahuang_gong",1) < 100)
		return notify_fail("你的八荒六合唯我独尊功功力不够，不能使用［菊楼采月］!");
	
	if (me->query_weapon())
		return notify_fail("你不能使用武器！");
	
	if (me->query_skill("finger", 1)
		&& !EQUALSTR(me->query_skill_mapped("finger"), "rouqing_zhi"))
		return notify_fail("［菊楼采月］必须要装备到基本指法上才可以使用这一绝招");
	
	if(me->query_skill("finger") < 180)
		return notify_fail("你的指法修为不够,目前还不能使用［菊楼采月］绝技!");
	
	if(me->query("mp") < 500)
		return notify_fail("你内力现在不够, 不能使用［菊楼采月］! ");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());
	
	msg = "\n$HIY$N并起二指，凌空虚点，指风直奔$n的周身大穴。\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp() / 5 )
	{
		if(!EQUALSTR(target->query_skill_mapped("dodge"), "lingboweibu"))
		{
			msg +=  "\n$HIG$N点出的凌厉指风将$n逼得连退几步。 $COM";
			message_vision(msg.c_str(), me, target);
			if(random(me->query("dex"))>target->query("dex")/4)
			{
				if(me->query_skill("rouqing_zhi", 1)<351)
				{
					msg =  "\n$HIY$n闷哼了一声，嘴角渗出几丝血丝。 $COM";
					harm=(random(me->query("age")/4+me->query("per")/3)+1)*(random(me->query_skill("rouqing_zhi", 1)/20)+25)*4;
				}
				else
				{
					msg =  "\n$HIY$n只觉一阵剧痛,闷哼了一声，嘴角渗出几丝血丝。 $COM";
					harm=(random(me->query("age")/3)+me->query("per")/2+1)*(random(me->query_skill("rouqing_zhi", 1)/10)+30)*4;
				}
				target->add("hp", -harm);
				if(target->query("hp")<1)target->set("hp",1);
				message_vision(msg.c_str(), me, target);
				snprintf(cmd ,255,"$HIY结果造成了%d点的伤害。",harm);
				message_vision(cmd,me,target);
			}
			target->start_busy(6);
			me->add("mp", -300);
		}
		else
		{
			msg += "$HIM$p变幻莫测的步法反而让$P看的眼睛发花,惊讶间顿时不知动弹。\n$COM";
			message_vision(msg.c_str(), me, target);
			me->start_busy(6);
			me->add("mp", -300);
		}
	}
	else
	{
		msg += "$HIM可是$p看破了$P的企图，并没有上当。\n$COM";
		message_vision(msg.c_str(), me, target);
		me->start_busy(4);
		me->add("mp", -400);
	}
	
	return 1;
}

SKILL_END;




