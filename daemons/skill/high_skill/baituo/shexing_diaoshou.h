//shexing_diaoshou.h ���ε���

//coded by Fisho
//date : 2000-11-29

SKILL_BEGIN(CSshexing_diaoshou);

virtual void create()
{
	set_name( "���ε���");

	set("valid_force", "hamagong");

	Magic_t * magic;

	magic = add_magic("wugu", do_wugu);
	magic->name = "����ȭ";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge, damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһʽ�����߳�������������Σ���������ͻȻ����$n�ı����Ѩ", 200, 10, 30, 0, "����",},
		{"$N����һ�Σ�һʽ����ͷ��β������������$n�ļ�ͷ����ȭ����$n���ؿ�", 220, 10, 42 , 10, "����",},
		{"$Nһʽ���������㡹�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",230 , 20, 45,20 ,"����",},
		{"$N�������У�����ֱ����һʽ��������Ӱ������Ʈ��������$n������", 260 , 20, 40,30 ,"����",},
		{"$Nʹһʽ��������ܡ�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�", 300, 10, 45, 38, "����",},
		{"$Nһʽ���������񡹣�ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ", 310, 10, 55, 51,"����",},
		{"$N˫�ֱ�ȭ��һʽ��������ӿ������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��", 380, 10, 60, 56, "����",},
		{"$Nһʽ���������š���ȭ���������֣��������ޣ�����������$n�ĵ���", 460, 20, 70, 60, "����",},
	};
  		
 	for(int i = 8; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("shexing_diaoshou", 1))
		{
			int level = random(i);

			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("lvl", action[level].lvl);
			m_actions.set("damage_type", action[level].damage_type);
			
			m_actions.set("force", (me->query("skill_pro/����ɽ��/���ε���/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/����ɽ��/���ε���/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/����ɽ��/���ε���/damage")+100) * action[level].damage/100);
			
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
			me->add("skill_pro/����ɽ��/���ε���/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/���ε���/force"));
			if(me->query("skill_pro/����ɽ��/���ε���/force_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/���ε���/force",1);
				me->set("skill_pro/����ɽ��/���ε���/force_point",1);
				tell_object(me,"\n$HIR������ε�������ڹ������ڻ��ͨ�ˡ�\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/����ɽ��/���ε���/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/���ε���/dodge"));
			if(me->query("skill_pro/����ɽ��/���ε���/dodge_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/���ε���/dodge",1);
				me->set("skill_pro/����ɽ��/���ε���/dodge_point",1);
				tell_object(me,"\n$HIR������ε���ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/����ɽ��/���ε���/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/����ɽ��/���ε���/damage"));
			if(me->query("skill_pro/����ɽ��/���ε���/damage_point")>=level_point)
			{
				me->add("skill_pro/����ɽ��/���ε���/damage",1);
				me->set("skill_pro/����ɽ��/���ε���/damage_point",1);
				tell_object(me,"\n$HIR������ε������������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage)
{ 
	return (usage == "unarmed") || (usage == "hand") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon() )
		return notify_fail("���ε�����ʵ��һ�ֿ��ֵļ��ܡ�");
	
	if (me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ε��֡�");
	
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷������ε��֡�");

 	return 1;
}

virtual int practice_skill(CChar * me)
{

	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");

	if (me->query("mp") < 20)
		return notify_fail("����������������ε��֡�");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

static int do_wugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("ֻ�ܶ�ս���еĵ���ʹ�á�");

	if( me->query_dex() < 25)
		return notify_fail("�����ݲ���,����ʹ����һ����!");
	
	if( me->query_skill("hamagong",1) < 100)
		return notify_fail("���󡹦�Ĺ�����������ʹ������ȭ!");
	
	if( me->query_skill("shexing_diaoshou") < 120)
		return notify_fail("������ε�����Ϊ����,Ŀǰ������ʹ������ȭ!");
	
	if( me->query("mp") < 200)
		return notify_fail("���������ڲ���, ����ʹ������ȭ! ");
		
	if(DIFFERSTR(me->querystr("family/family_name"), "����ɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������� ",target->name() );
	
	msg =   "$N��������һ��ͻȻ���ֱ���ͬû���˹�ͷһ���ת������ž��һ������$n�ĺ����ϡ�\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 3 )
	{
		msg +=    "���$p��$P������ţ���ʱһ��ͷ���ۻ�������������С���Ľ���! "  ;
		target->start_busy(  me->query_skill("shexing_diaoshou",1) / 40 );
		me->add("mp", -50);
	}
	else
	{
		msg +=   "����$p������$P����ͼ������һԾ�����˿�ȥ��"  ;
		me->start_busy(2);
		me->add("mp", -50);		
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

