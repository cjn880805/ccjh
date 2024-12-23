//xiaoyao-jian  逍遥剑法

SKILL_BEGIN(CSxiaoyao_jian);
virtual void create()
{
	set_name( "逍遥剑法");
	set("diff",100);
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N身形微动，一招「赤练长虹」手中$w化做一道白虹，直刺向$n的胸前", 120,5,20,0,30,},
		{"$N使一招「峰回路转」，看似漫不经心，忽然一剑直出，$w飞刺$n", 160,0,8,15,40,},
		{"$N轻提$w，舞起朵朵剑花，一招「纷纷扬扬」，刺向$n全身", 220,10,15,30,50,},
		{"$N脚步轻移，身形飘忽，一招「风吹落花」，$w同是刺向$n的各处要害", 240,10,20,50,50,},
		{"$N身形变幻，反手一剑，一招「回看风云」，急刺$n胸前", 270,20,15,80,60,},
		{"$N使出一招「笑看春风」，看似轻描淡写，却处处击向$n全身要穴", 300,35,50,100,60,},
		{"$N使一式「月光满地」，$w舞成一道剑光，处处迷茫着剑气，攻向$n", 300,40,70,130,80,},
		{"$N劲运于$w,一招「无声无息」，$w却以极慢的速度直直向$n刺去", 500,40,70,150,100,},
	};


	int level = me->query_skill("xiaoyao_jian", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/逍遥派/逍遥剑法/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/逍遥派/逍遥剑法/dodge")+100) * action[level].dodge/100);
			m_actions.set("parry", (me->query("skill_pro/逍遥派/逍遥剑法/parry")+100) *action[level].parry);
			m_actions.set("damage", (me->query("skill_pro/逍遥派/逍遥剑法/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/逍遥派/逍遥剑法/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥剑法/force"));
			if(me->query("skill_pro/逍遥派/逍遥剑法/force_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥剑法/force",1);
				me->set("skill_pro/逍遥派/逍遥剑法/force_point",1);
				tell_object(me,"\n$HIR你的逍遥剑法配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/逍遥派/逍遥剑法/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥剑法/dodge"));
			if(me->query("skill_pro/逍遥派/逍遥剑法/dodge_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥剑法/dodge",1);
				me->set("skill_pro/逍遥派/逍遥剑法/dodge_point",1);
				tell_object(me,"\n$HIR你的逍遥剑法使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/逍遥派/逍遥剑法/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥剑法/parry"));
			if(me->query("skill_pro/逍遥派/逍遥剑法/parry_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥剑法/parry",1);
				me->set("skill_pro/逍遥派/逍遥剑法/parry_point",1);
				tell_object(me,"\n$HIR你熟练的使用逍遥剑法，防守能力进一步加强了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/逍遥派/逍遥剑法/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/逍遥派/逍遥剑法/damage"));
			if(me->query("skill_pro/逍遥派/逍遥剑法/damage_point")>=level_point)
			{
				me->add("skill_pro/逍遥派/逍遥剑法/damage",1);
				me->set("skill_pro/逍遥派/逍遥剑法/damage_point",1);
				tell_object(me,"\n$HIR你的逍遥剑法威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("sword", 1) < 30)
		return notify_fail("你的基本剑法太差了，练不了逍遥剑法。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 20)
		return notify_fail("你的体力不够练不了逍遥剑法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
