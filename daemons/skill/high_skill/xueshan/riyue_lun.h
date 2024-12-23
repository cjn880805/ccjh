// riyue_lun.c �����ַ�
SKILL_BEGIN(CSriyue_lun);

virtual void create()
{
	set_name( "�����ַ�");

	Magic_t * magic;
	magic = add_magic("feilun", do_feilun);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("�����ַ�������ѩɽ�ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$Nʹһ�С������ơ����������е�$w��$n��$l��ȥ", 220, -10, 10, 0, 90,},
		{"$Nʹһ�С���ɽ���ơ���˫��һ�����趯����$w��$n��$l��ɨ", 260, -20, 20, 8, 95,},
		{"$Nʹһ�С���΢�ơ����͵�һ�����������¶�������$n��$l", 300, -20, 10, 16, 90,},
		{"$Nʹһ�С������ơ����������֮��$wɨ��$n��$l", 340, 5, 15, 24, 95,},
		{"$Nʹһ�С�Բ���ơ���$w������֮����ֱ��$n��$l", 380, -10, 10, 32, 90,},

		{"$NԾ���գ�ʹһ�С����ػ��ơ����߾�$w����$n��$l", 320, 10, 10, 40, 95,},
		{"$Nʹһ�С�׽���ơ���б������$w����$n��$l", 360, -15, 15, 48, 90,},
		{"$N��һ��������ʹ�����Լ��项��$wɨ��$n��ͷ��", 440, -20, 15, 56, 100,},
	};
	
	int level = me->query_skill("riyue_lun", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="hammer" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("����������������������ַ�����");
	me->receive_damage("hp", 30);
	return 1;
}

static int do_feilun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
    CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || ! me->is_fighting(target) )
        return notify_fail("�ҷ�ȱ���ֻ��ս���вų������ˡ�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("������ʲô������ʹ�������������ǲ����Եģ�");	

    if( me->query_skill("riyue_lun", 1) < 100 )
        return notify_fail("��������ַ�������죬����ʹ�÷�������");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
    if( me->query("mp") < 100 )
        return notify_fail("����������������ʹ����������");
	
    int skill = me->query_skill("riyue_lun", 1);
	
    me->add("mp", -50);
    target->receive_damage("hp", skill/ 3);
	
    msg = "ֻ��$N���е�";
	msg += weapon->name();
	msg += "�����ǰ���$n������ȥ��";
	
    me->start_busy(1);
	if( random( me->query_skill("riyue_lun", 1))
		> random(target->query_skill("dodge") + 1) ) 
	{
		msg = "$HIR���$p��$P�ľ��д�����Ҫ����λ��ʹ�ô����Һ���\n";
		target->receive_wound("hp", random(skill) * 8);

	} 
	else 
	{
		msg += "����$p�����$P�ı�ɱһ����\n";
	}

	if(userp(me))
		weapon->move(me->environment());
	else
	{
		msg += weapon->name();
		msg += "��ת��Ȧ���ַɻ�$N���У�";
	}
	message_vision(msg.c_str(), me, target);
		
	//use out all throwing
	
	return 1;
}

SKILL_END;
