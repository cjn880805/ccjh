// falun_daofa.h ���ⷨ�������˵�
//code by Teapot
//date : 2001-02-06

SKILL_BEGIN(CSfalun_daofa);

virtual void create()
{
	set_name( "���ⷨ�������˵�");

	Magic_t * magic;

	magic = add_magic("zhuang", do_zhuang);
	magic->name = "���ֳ�ת";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹ�����ְ�ʽ�е�����ʽ��������תʽ�������е�$w����һ���âն��$n��$l",500 , 5, 0,"����",},
		{"$N��һ����һ�С����ַ���ʽ�����е�$w�ó�һƬ������ɢ��$n��$l", 300, 10, 10,"����",},
		{"$N�����ת�����е�$wһ�С���������ʽ�������������$n��$l",320 , 15, 20,"����",},
		{"$N��Ӱ�ζ������������ң�һ�С������ޱ�ʽ�������е�$w������·ͻȻ����$n��$l", 300, 20, 30,"����",},
		{"$N��˫�ŵ�أ���������һ�С�����Ǭ��ʽ��ȫ��ת��һ�ŵ������$n", 300,25 , 40,"����",},
		{"$N�������ϣ�һ�С����ֻ���ʽ������һ��$n���벻���ĽǶ�����$n��$l", 360, 0, 50,"����",},
		{"$N�����е�$w���ҺỮ��һ�С����ֶ���ʽ���������ػصؿ�ɨ��$n��$l", 420, 35, 60,"����",},
		{"$Nʹ��������ħ������ʽ�е�����ʽ���򷨹���ʽ�������е�$wѸ���ޱȵؿ���$n��$l", 540, 40, 80,"����",},
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("falun_daofa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "blade") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 500)
		return notify_fail("�������������");
	if (me->query_skill("falun_gong", 1) < 20)
		return notify_fail("�㻹û�������ִ󷨵ľ��衣");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("����������������ⷨ�������˵���");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 

static int do_zhuang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("�����ֳ�ת������ʽ��ֻ����ս����ʹ�á�");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("�����ֳ�ת������ʽ�������õ���");
	
	if( me->query("mp") < 500 )
		return notify_fail("�������������");
	
	if( me->query_skill("blade") < 144 ||
		DIFFERSTR( me->query_skill_mapped("blade") , "falun_daofa"))
		return notify_fail("������ⷨ�������˵��������ң��޷�ʹ�÷��ֳ�ת������ʽ��");

	
	snprintf(msg ,255,"$N������ͨ�������ֳ�ת������ʽһ���ǳɣ�"  );
	message_vision(msg, me);
	
	snprintf(msg ,255,"ħת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"��ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"��ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"��ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"��ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"��ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"����ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	snprintf(msg ,255,"���ת��"  );
	message_vision(msg, me);
	g_Combatd.Do_Attack(me, target,  CCombatd::TYPE_QUICK);

	
	
	me->add("mp", -500);
	me->start_busy(random(6));	// 8 Hits and busy r.d.6,the best multi-strike perform.
	
	return 1;
	
}

SKILL_END;
