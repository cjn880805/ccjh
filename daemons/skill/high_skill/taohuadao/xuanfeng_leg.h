
// xuanfeng_leg.h ����ɨҶ��
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSxuanfeng_leg);

virtual void create()
{
	set_name( "����ɨҶ��");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("kuangfeng", do_kuangfeng);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N˫����Σ�����͵ط���һʽ��������ӿ�����ż�ζ�������$n��ƨ��", 100, 15,10 ,"����",},
		{"$N��Ŷٵأ���ת�����������ߣ�ֻһɲ�Ǽ�һ�����ҽ�һʽ���չ�������������$n��$l", 120, 10, 0,"����",},
		{"$N����һ��������Ť��ס$n�����֣��ҽ�ͬʱ�߳���������׼��һʽ����Ԩ���ԡ������е�$n���ؿ�", 140, 15, 10,"����",},
		{"$NͻȻԾ��˫������Ȧת��һʽ�������Ҷ��������糾������$n��ȫ��", 160, 15, 10,"����",},
		{"$N���ֻ��أ�˫�Ž�������һʽ����ɨ���ơ����ŽŲ���$n����������", 180, 20, 20,"����",},
		{"$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶���һʽ������׹�ء�����$n������ֱ������", 200, 35, 30,"����",},
		{"$Nʹһʽ��˷�紵ѩ����ȫ��ͻȻ������ת��˫���ǰ����Ѹ���޼�����$n���ؿ�", 220, 30, 40,"����",},
		{"$N����Ծ�𣬿������������һ�����ˣ�һʽ���׶����졹��˫�������������$n��$l", 250, 35, 30,"����",},
	};

	int level = me->query_skill("xuanfeng_leg", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("dodge", (me->query("skill_pro/�һ���/����ɨҶ��/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/�һ���/����ɨҶ��/damage")+100) * action[level].damage/100);
	
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "leg";	//װ���������ȷ�
}

virtual int valid_combine(string combo) { return combo=="luoying_shenzhang"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/�һ���/����ɨҶ��/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/����ɨҶ��/dodge"));
			if(me->query("skill_pro/�һ���/����ɨҶ��/dodge_point")>=level_point)
			{
				me->add("skill_pro/�һ���/����ɨҶ��/dodge",1);
				me->set("skill_pro/�һ���/����ɨҶ��/dodge_point",1);
				tell_object(me,"\n$HIR�������ɨҶ��ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/�һ���/����ɨҶ��/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/�һ���/����ɨҶ��/damage"));
			if(me->query("skill_pro/�һ���/����ɨҶ��/damage_point")>=level_point)
			{
				me->add("skill_pro/�һ���/����ɨҶ��/damage",1);
				me->set("skill_pro/�һ���/����ɨҶ��/damage_point",1);
				tell_object(me,"\n$HIR�������ɨҶ�����������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        return notify_fail("����ɨҶ�ȱ�����֡�");
    if ( me->query_skill("bibo_shengong", 1) < 15)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ����ɨҶ�ȡ�");
    if ( me->query("max_mp") < 100)
        return notify_fail("�������̫�����޷�������ɨҶ�ȡ�");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if ( me->query("mp") < 20)
		return notify_fail("�����������������ɨҶ�ȡ�");
    me->receive_damage("hp", 20);
    me->add("mp", -1);
    return 1;
	
}


//perform 
static int do_kuangfeng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("����������ֻ����ս����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�һ���") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if (me->query_weapon()  )
		return notify_fail("������������ʼʱ�������ű�����");
	
	if(  me->query("mp") < 200 )
		return notify_fail("�������������");
	
	if(  me->query_skill("bibo_shengong",1) < 50 )
		return notify_fail("��ı̲��񹦲�����");
	
	if(  me->query_skill("luoying_shenzhang",1) < 100 ||
		me->query_skill("xuanfeng_leg",1) < 100)
		return notify_fail("������ƹ��򻹲����ң��޷�ʹ�ÿ�������");
/*
	if (EQUALSTR(me->query_skill_mapped("leg"), "xuanfeng_leg") && 
		EQUALSTR(me->query_skill_mapped("unarmed"), "anranxiaohun_zhang"))
		return notify_fail("������������ô������ȭͷ�����");
*/	
	message_vision("$Nʹ���һ�����������������������Ȼ�ӿ죡", me);
	
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	
	me->add("mp", -200);
	me->start_busy(2);
	
//	if(!((CChar *)ob)->is_fighting(me)) ((CChar *)ob)->kill_ob(me);
	return 1;
}

SKILL_END;
