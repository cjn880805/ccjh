//lingshe_zhangfa.h �����ȷ�

//coded by Fisho
//data: 2000-11-29

SKILL_BEGIN(CSlingshe_zhangfa);

virtual void create()
{
	set_name( "�����ȷ�");
	set("valid_force", "hamagong");

	Magic_t * magic;

	magic = add_magic("pili", do_pili);
	magic->name = "��������";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar *me)
{
	static CMapping m_actions;

	struct{
			char action[100];
			int  force,dodge, damage,lvl;
			char damage_type[5];
	}action[]={
		{"$Nʹ��һ�С����߳�����������$w�󿪴���ɨ��$n��$l", 220, -3, 56, 10,"����",},
		{"$N����$w������죬һ�С�ҡͷ��β����$n��$l��ȥ", 240, -5, 68, 20,"����",},
		{"$N����$w���Ӹ�����ʹһ�С������½�������$n��$l", 280, -10, 80, 30,"����",},
		{"$Nһ�С�����ͦ��������$w����ɨ��$n��$l", 320, -5, 66, 80,"����",},
		{"$Nʹ��һ�С��������ߡ���$w�����ػ���$n��$lɨȥ", 360, -3, 120, 50,"����",},
		{"$N����$wһ�ӣ�ʹ��һ�С��߲����ҡ����������ɨ��$n��$l", 400, -5, 136, 60,"����",},
		{"$Nʹ��һ�С�������ɽ�����߾�����$w����ͷ����$n��$l", 440, -10, 168,80 ,"����",},
		{"$Nʹ��һ�С����߳�����������$w��һ̽��ֱɨ$n��$l", 480, -3, 180, 100,"����",},
	};
	for(int i = 8; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lingshe_zhangfa", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("force", (me->query("skill_pro/����ɽ��/�����ȷ�/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/����ɽ��/�����ȷ�/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/����ɽ��/�����ȷ�/damage")+100) * action[level].damage/100);
			break;
		}
	}
		
	if (me->query_temp("teapot/thunder"))
			m_actions.set("action", "$N���һ����ͻȻ����������һ�й���$n��");
	
	
	return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/����ɽ��/�����ȷ�/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/�����ȷ�/force"));
			if(me->query("skill_pro/����ɽ��/�����ȷ�/force_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/�����ȷ�/force",1);
				me->set("skill_pro/����ɽ��/�����ȷ�/force_point",1);
				tell_object(me,"\n$HIR��������ȷ�����ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/����ɽ��/�����ȷ�/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/�����ȷ�/dodge"));
			if(me->query("skill_pro/����ɽ��/�����ȷ�/dodge_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/�����ȷ�/dodge",1);
				me->set("skill_pro/����ɽ��/�����ȷ�/dodge_point",1);
				tell_object(me,"\n$HIR��������ȷ�ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/����ɽ��/�����ȷ�/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/�����ȷ�/damage"));
			if(me->query("skill_pro/����ɽ��/�����ȷ�/damage_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/�����ȷ�/damage",1);
				me->set("skill_pro/����ɽ��/�����ȷ�/damage_point",1);
				tell_object(me,"\n$HIR��������ȷ����������ˡ�\n");
			}
		}
	}
	if( random(me->query_skill("hamagong") + 1) > 10 ) 
	{
		victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
			victim->query("condition/snake_poison"));
        tell_object(victim,  "����ñ����еĵط�һ����ľ��"  );
        tell_object(victim,  "ԭ���Ǳ���ͷ�ܳ��Ķ���ҧ��һ�ڣ�"  );
	}
	return "";
}

virtual int valid_enable(string usage)
{ 
	return (usage == "staff") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");
	
	if (me->query("max_mp") < 70)
		return notify_fail("�������������");

 	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon ;
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("������������������ȷ���");

	me->receive_damage("hp", 20);
	return 1;
}

static int do_pili(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�");
		
	if(DIFFERSTR(me->querystr("family/family_name"), "����ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	me->set_temp("teapot/thunder",1);
	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
	me->delete_temp("teapot/thunder");
	me->start_busy(2);
	

    return 1;
}


SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp





