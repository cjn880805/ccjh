//xiaoyao-jian  ��ң����

SKILL_BEGIN(CSxiaoyao_jian);
virtual void create()
{
	set_name( "��ң����");
	set("diff",100);
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N����΢����һ�С��������硹����$w����һ���׺磬ֱ����$n����ǰ", 120,5,20,0,30,},
		{"$Nʹһ�С����·ת���������������ģ���Ȼһ��ֱ����$w�ɴ�$n", 160,0,8,15,40,},
		{"$N����$w�������佣����һ�С��׷����������$nȫ��", 220,10,15,30,50,},
		{"$N�Ų����ƣ�����Ʈ����һ�С��紵�仨����$wͬ�Ǵ���$n�ĸ���Ҫ��", 240,10,20,50,50,},
		{"$N���α�ã�����һ����һ�С��ؿ����ơ�������$n��ǰ", 270,20,15,80,60,},
		{"$Nʹ��һ�С�Ц�����硹���������赭д��ȴ��������$nȫ��ҪѨ", 300,35,50,100,60,},
		{"$Nʹһʽ���¹����ء���$w���һ�����⣬������ã�Ž���������$n", 300,40,70,130,80,},
		{"$N������$w,һ�С�������Ϣ����$wȴ�Լ������ٶ�ֱֱ��$n��ȥ", 500,40,70,150,100,},
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
			m_actions.set("force", (me->query("skill_pro/��ң��/��ң����/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/��ң��/��ң����/dodge")+100) * action[level].dodge/100);
			m_actions.set("parry", (me->query("skill_pro/��ң��/��ң����/parry")+100) *action[level].parry);
			m_actions.set("damage", (me->query("skill_pro/��ң��/��ң����/damage")+100) * action[level].damage/100);
			
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
			me->add("skill_pro/��ң��/��ң����/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/force"));
			if(me->query("skill_pro/��ң��/��ң����/force_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/force",1);
				me->set("skill_pro/��ң��/��ң����/force_point",1);
				tell_object(me,"\n$HIR�����ң��������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/��ң��/��ң����/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/dodge"));
			if(me->query("skill_pro/��ң��/��ң����/dodge_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/dodge",1);
				me->set("skill_pro/��ң��/��ң����/dodge_point",1);
				tell_object(me,"\n$HIR�����ң����ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("parry")) 
		{
			me->add("skill_pro/��ң��/��ң����/parry_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/parry"));
			if(me->query("skill_pro/��ң��/��ң����/parry_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/parry",1);
				me->set("skill_pro/��ң��/��ң����/parry_point",1);
				tell_object(me,"\n$HIR��������ʹ����ң����������������һ����ǿ�ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/��ң��/��ң����/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/��ң��/��ң����/damage"));
			if(me->query("skill_pro/��ң��/��ң����/damage_point")>=level_point)
			{
				me->add("skill_pro/��ң��/��ң����/damage",1);
				me->set("skill_pro/��ң��/��ң����/damage_point",1);
				tell_object(me,"\n$HIR�����ң�������������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("sword", 1) < 30)
		return notify_fail("��Ļ�������̫���ˣ���������ң������");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 20)
		return notify_fail("�������������������ң������");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
