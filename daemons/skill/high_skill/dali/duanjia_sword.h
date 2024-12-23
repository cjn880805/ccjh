// duanjia_sword.c �μҽ�
// last modified by sound 2001-05-29
// ����perform "�����Ļ�" ��

SKILL_BEGIN(CSduanjia_sword);

virtual void create()
{
	set_name( "�μҽ�");

	Magic_t * magic;

	magic = add_magic("jingtian", do_jingtian);
	magic->name = "����һ��";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("fenglei", do_fenglei);
	magic->name = "�����Ļ�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("�μҽ��������������ڹ����ʹ�á�");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force,dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N��ǰ����һ����һ�С��ƺ����롹������$w����������$n��$l������ȥ", 
		100, 20, 25, 0, "����",},
		{"$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ������ֱ�¡�ֱ��$n��$l", 
		120, 15, 30, 9, "����",},
		{"$Nһ�С�ѩӿ���ء���$w�����������⣬���¶��Ϸ���$n��$l", 
		140, 15, 35, 19, "����",},
		{"$Nһ�С����ͻ�𡹣�����$w���ƺ�ɨʵ��б��������$n��$l", 
		160, 10, 45, 29, "����",},
		{"$Nʹ����ҹ��̽������$w����������������಻�ϻ���$n��$l", 
		180, 10, 60, 39, "����",},
		{"$Nһ�С�̩ɽѹ����������һ�󽣾�������$w���϶������������ֱ��$n��$l������ȥ", 
		210, 5, 70, 49, "����",},
		{"$Nһ�С�����滨�������ڰ�գ�$w�س飬���ֹ���$n��$l", 
		250, 10, 90, 69, "����",},
		{"$N��Ӱһ��, �Ƶ�$n����һ�С���¹��ԭ����������$n��$l����", 
		300, -5, 100, 89, "����",},
	};
 
	int level = 0;

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("duanjia_sword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
//			m_actions.set("dodge", action[level].dodge);
			if(me->query_temp("apply/��_�μҽ�"))
//				m_actions.set("damage", (me->query_temp("apply/��_�μҽ�")+100) * action[level].damage/100);
				m_actions.set("damage", (me->query("skill_pro/����μ�/�μҽ�/damage")+me->query_temp("apply/��_�μҽ�")+100) * action[level].damage/100);
			else
//				m_actions.set("damage", action[level].damage);
				m_actions.set("damage", (me->query("skill_pro/����μ�/�μҽ�/damage")+100) * action[level].damage/100);
			
			m_actions.set("dodge", (me->query("skill_pro/����μ�/�μҽ�/dodge")+100) * action[level].dodge/100);
			break;
		}
	}

	return & m_actions;
};

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("dodge")) 
		{
			me->add("skill_pro/����μ�/�μҽ�/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/����μ�/�μҽ�/dodge"));
			if(me->query("skill_pro/����μ�/�μҽ�/dodge_point")>=level_point)
			{
				me->add("skill_pro/����μ�/�μҽ�/dodge",1);
				me->set("skill_pro/����μ�/�μҽ�/dodge_point",1);
				tell_object(me,"\n$HIR��Ķμҽ�ʹ�õø��ӵ���Ӧ���ˡ�\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/����μ�/�μҽ�/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/����μ�/�μҽ�/damage"));
			if(me->query("skill_pro/����μ�/�μҽ�/damage_point")>=level_point)
			{
				me->add("skill_pro/����μ�/�μҽ�/damage",1);
				me->set("skill_pro/����μ�/�μҽ�/damage_point",1);
				tell_object(me,"\n$HIR��Ķμҽ����������ˡ�\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "staff") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{

	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("kurong_changong", 1) < 20)
		return notify_fail("��Ŀ����������̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("��������������μҽ���");
	me->receive_damage("hp", 20);
	return 1;
}

//perform 
//�μҽ���������һ����
static int do_jingtian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query_skill("duanjia_sword", 1) < 70 )
		return notify_fail("��Ķμҽ���������죬����ʹ�á�");
	
	if (me->query_skill("kurong_changong", 1) < 70 )
		return notify_fail("��Ŀ���������Ϊ�����ߡ�");
	
	if (me->query("mp") < 300)
		return notify_fail("����������̫��������ʹ�á�����һ������");

	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	msg = "$NһԾ��������һ�������һ�������Ľ���������$n��\n";

	if (random(me->query_skill("force")) > ((CChar *)target)->query_skill("force")/2 )
	{
		target->start_busy( me->query_skill("duanjia_sword") / 20 + 1);
		
		int damage = me->query_skill("kurong_changong", 1);
		damage = damage +  me->query_skill("duanjia_sword", 1);
		damage = damage +  me->query_skill("sword", 1);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/4);
		me->add("mp", -damage);
		msg += "ֻ��$N�˽���һ������$n,$nֻ��һ���������Ķ�������ͷһ����Ѫ���������";
		me->start_busy(2);
	} 
	else 
	{
		msg += "����$p�͵������һԾ,������$P�Ĺ�����Χ��";
		me->add("mp", -100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	if(! target->is_killing(me))
		target->kill_ob(me);

	return 1;

}

//�μҽ����������Ļ���

static int do_fenglei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int i = me->query_skill("duanjia_sword", 1);
    
	if( !target ||! me->is_fighting(target) )
		return notify_fail("�������Ļ���ֻ����ս����ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("�����޽�,����ôʹ�ó��������Ļ�����");

	if ( me->query("mp") < 500 )
		return notify_fail("�����������������ʹ�á������Ļ�����");

	if ( me->query_skill("wuluo_zhang",1) < 100 ||
		DIFFERSTR(me->query_skill_mapped("strike"), "wuluo_zhang") )
		return notify_fail("������������ƻ������ң��޷�ʹ�á������Ļ���������");

	if ( me->query_skill("strike",1) < 100 )
		return notify_fail("����Ʒ����費�����޷�ʹ����˸���ġ������Ļ���������");

	if ( me->query_skill("duanjia_sword", 1) < 150 )
		return notify_fail("��Ķμҽ����������ң��޷�ʹ�á������Ļ���������");

//	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�") && me->querymap_temp("biwu"))
//		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if(DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
		return notify_fail("����ϡ�л��ǡ������Ļ�����Ҫ������ϧ�뿪����μ�̫�ã��Ѿ��޷��������еľ��衣");

	message_vision("$BLU$N��Цһ�����������֣�������ϣ�ʩչ�������Ļ�������,��ͼ���ٻ���$n $COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);
	me->add("mp",-300); 
	me->add_temp("apply/attack", i);
	me->add_temp("apply/dodge", i);
	
	message_vision("$HIY$N�ս�ֱ�ϣ�����$n����һ����$COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	message_vision("$HIY$N�Ų����ǲ�������ǰ�����֮���ѵ�$n��ǰ��$COM", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	message_vision("$HIY$N�������һ�׳��죬һ��[����׵�]���������$n��$COM ", me, target);
	g_Combatd.Do_Attack(me, target, g_Combatd.TYPE_QUICK);

	me->start_busy(2);
	me->add_temp("apply/dodge", -i);
	me->add_temp("apply/attack", -i);

	return 1;
}

SKILL_END;
