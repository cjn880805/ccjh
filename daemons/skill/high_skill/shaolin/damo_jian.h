SKILL_BEGIN(CSdamo_jian);

virtual void create()
{
	set_name( "��Ħ��");
	
	Magic_t * magic;

	magic = add_magic("sanjue", do_sanjue);
	magic->name = "��Ħ������";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("��Ħ���������������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$Nʹһʽ��������Ե����������$w����΢�񣬻ó�һ���������$n��$l",
			120, -10, 15, 0,},
		{"$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w��������$n��$l��ȥ",
		140, -10, 20, 9,},
		{"$Nһʽ��������ɣԶ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
		160, 5, 20, 18,},
		{"$N��������Ծ��һʽ���ֻط����᡹���������ּ�ת������ն��$n��$l",
		180, 10, 35, 27,},
		{"$N����$w�й�ֱ����һʽ��ˮ��ͨ���š���������Ϣ�ض�׼$n��$l�̳�һ��",
		220, 15, 40, 36,},
		{"$N����$wбָ���죬��â���£�һʽ������������������׼$n��$lбб����",
		260, 5, 45, 44,},
		{"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��ǧ��һέȥ������$n��$l",
		320, 5, 55, 52,},
		{"$N���Ƶ�����һʽ�����Ķ���������$w�Ի���Ծ�����缲�������$n���ؿ�",
		380, 5, 60, 60,},
	};

	int level = me->query_skill("damo_jian", 1);
	for(int i = 8; i > 0; i--)
	{
		if(level > action[i-1].lvl)
		{
			level = random(i);
			if (DIFFERSTR(me->querystr("family/family_name"), "������"))
			{
				m_actions.set("action", "$N�ս�����$w�����һ����ŵ���$n��$l");
				m_actions.set("dodge", 1);
				m_actions.set("damage", 1);
				m_actions.set("force", 1);
			}
			else
			{
				m_actions.set("action", action[level].action);
				if(! me->query_temp("pfm_damijian"))
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage);
				}
				else
				{
					m_actions.set("force", action[level].force*3/2);
					m_actions.set("damage", action[level].damage*2);
				}
				m_actions.set("dodge", action[level].dodge);
			}
			break;
		}
	}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("���������������Ħ����");

	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "sword" || usage == "parry";}
virtual int valid_combine(string combo) {return combo=="xiuluo_dao";}

static int do_sanjue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
    
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(!target || !me->is_fighting(target) )
	    return notify_fail("����Ħ��������ֻ����ս����ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
			return notify_fail("��Ȼ������ô�Ħ��������������Ҳ����һ�ѽ������ð���");

	if(me->query_dex() < 30)
		return notify_fail("���������, Ŀǰ������ʹ���������! ");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����, ����ʹ����һ���� !");

	if(me->query_skill("dodge") < 135)
		return notify_fail("����Ṧ��Ϊ����, ����ʹ�ô�Ħ��������");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
 
	if(me->query_skill("sword") < 135)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�ô�Ħ������! ");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "damo_jian"))
		return notify_fail("������ϴ�Ħ����ʹ�á�");

    if(me->query("mp") < 500 )
		return notify_fail("�������������");

    message_vision("$Nʹ����Ħ���ľ�������Ħ��������������Ȼ�ӿ죡", me);

	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	
	me->add("mp", -150);
	me->start_busy(random(2));

    return 1;
}

SKILL_END;