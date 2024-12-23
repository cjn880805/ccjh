
// yuxiao_jianfa.h ��������
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSyuxiao_jianfa);

virtual void create()
{
	set_name( "��������");
	set("valid_force", "bibo_shengong");

	set("diff",130);

	Magic_t * magic;

	magic = add_magic("hua", do_hua);
	magic->name = "�ƺ�����";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N����һת�����е�$w���˸���Ȧ��һʽ������ĺĺ������$n��$l", 60, 10,5 , 30, 0,"����",},
		{"$N���ƺ��ƣ�һʽ���߻����¡���$w��ǰ������ָ��$n������", 120, 15, 10, 60, 4,"����",},
		{"$N���е�$w���˸���Ȧ��һʽ���绨ѩҹ������$n��$l����", 180, 20, 15, 90, 9,"����",},
		{"$N˫Ŀ΢����һʽ��ŭ�ξ��꡹��$w��������Բ����һ�����$n��$l", 250, 25, 20, 120,14 ,"����",},
		{"$N����Ծ���ֱ�΢̧��һʽ�������׺�������������$n��$l", 320, 30, 25, 150, 19,"����",},
		{"$N����š���������鱧��һ�С��Ʋ���������$w�й�ֱ��������$n��$l", 400, 35,30 , 180, 149,"����",},
	};
 		
	int level = me->query_skill("yuxiao_jianfa", 1);
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("dodge", (me->query("skill_pro/�һ���/��������/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/�һ���/��������/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/�һ���/��������/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��������/dodge"));
			if(me->query("skill_pro/�һ���/��������/dodge_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��������/dodge",1);
				me->set("skill_pro/�һ���/��������/dodge_point",1);
				tell_object(me,"\n$HIR�����������ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/�һ���/��������/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/��������/damage"));
			if(me->query("skill_pro/�һ���/��������/damage_point")>=level_point)
			{
				me->add("skill_pro/�һ���/��������/damage",1);
				me->set("skill_pro/�һ���/��������/damage_point",1);
				tell_object(me,"\n$HIR��������������������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if ( me->query("max_mp") < 500)
		return notify_fail("�������������");
	if ( me->query_skill("bibo_shengong", 1) < 150)
		return notify_fail("��ı̲��񹦻��̫ǳ��");
	if ( me->query_skill("luoying_shenjian", 1) < 100)
		return notify_fail("�����Ӣ�񽣻��̫ǳ��");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("�����������������������");
	me->receive_damage("hp", 30);
	return 1;
	
}

//perform 
static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target) )
		return notify_fail("���ƺ����롹ֻ�ܶ�ս���еĶ���ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "yuxiao_jianfa"))
		return notify_fail("���������������ʹ�á�");
	
	if(  me->query_skill("yuxiao_jianfa", 1) < 60 )
		return notify_fail("�������������������죬����ʹ�á����컨�꡹��");
	
	if(  me->query_skill("bibo_shengong", 1) < 100 )
		return notify_fail("��ı̲��񹦲�����죬����ʹ�á����컨�꡹��");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query("mp") < 100)		//add by Lanwood 2000-12-26
		return notify_fail("����������㡣");
	
	msg =  "$N����һ����һʽ���ƺ����롹���������佣�������ݳ���\n";
		
	if( random(me->query_combat_exp()) >  target->query_combat_exp()/3 )
	{
		if(target->query_temp("apply/no_�ƺ�����")&& (!random(2)||target->query("bigboss")))
		{
			msg += "����$p������$P����ͼ����û���ϵ���";
		}
		else
		{
			msg +=   " ���$p��$P���˸����ֲ�����"  ;
			int attack_time = random( me->query_skill("yuxiao_jianfa", 1) / 30);
			if(attack_time < 1)
				attack_time = 1;
		
			for(int	i = 0; i < attack_time; i++)
				g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
		
			me->start_busy(random(2));
			me->add("mp", -100);
		}
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���"  ;
		me->start_busy(random(3));
		me->add("mp", -50);				//add by lanwood 2000-12-26
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;




