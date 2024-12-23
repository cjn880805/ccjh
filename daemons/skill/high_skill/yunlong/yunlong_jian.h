// yunlong-jian.c ������
SKILL_BEGIN(CSyunlong_jian);

virtual void create()
{
	set_name( "������");

	Magic_t * magic;

	magic = add_magic("xian", do_xian);
	magic->name = "��������";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[] = {
		{"$Nʹһʽ������˳��Ȼ��������$w����΢�񣬻ó�һ���׹����$n��$l", 120, -10, 15, 0,},
		{"$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w��������$n��$l��ȥ", 140, -10, 20, 0,},
		{"$Nһʽ��־�����Զ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l", 160, 5, 30, 15,},
		{"$N��������Ծ��һʽ�������γ�����������ˮ��һкǧ�����$nȫ��", 180, 10, 35, 20,},
		{"$N����$w�й�ֱ����һʽ�����Ǳ��ҹ����������Ϣ�ض�׼$n��$l�̳�һ��", 220, 15, 40, 30,},

		{"$N����$wһ����һʽ������ϸ��������������Ϣ�ػ���$n��$l", 250, 15, 40, 40,},
		{"$N����$wбָ���죬��â���£�һʽ������������������׼$n��$lбб����", 280, 25, 45, 50,},
		{"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ������һ��졹����$n���ʺ�", 320, 15, 55, 60,},
		{"$N���Ƶ�����һʽ�����Ļ���������$w�Ի���Ծ�����缲�������$n���ؿ�", 380, 15, 60, 70,},
		{"$N����һ���εض���һʽ��������ͬ�ԡ���$w�ó������Ӱ����$n����Χס", 420, 15, 70, 80,},
		
		{"$N�������Ʈ�䣬һʽ�����֪���⡹������$wƽָ����������$n����", 450, 15, 80, 90,},
		{"$N����΢����������һ�С��ߴ���ʤ�������йǽ�����쫷�����$nȫ��", 500, 15, 90, 100,},
		{"$Nļ��ʹһ�С���Ҷ����ɽ������ʱ�����м���Ѫ������$nȫ��", 500, 25, 100, 110,},
	};

	int level = me->query_skill("yunlong_jian", 1);
	for(int i=13; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 200)
		return notify_fail("�������������");
	if (me->query_skill("yunlong_xinfa", 1) < 20)
		return notify_fail("��������ķ����̫ǳ��");
	if (me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("�����������������������");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_xian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if( me->query_skill("yunlong_jian", 1) < 50 )
		return notify_fail("�����������������죬����ʹ�á��������֡���");

	if( me->query_skill("yunlong_shengong", 1) < 50 )
		return notify_fail("��������񹦲����ߣ��������������˵С�");

	if( me->query("mp") < 300 )
		return notify_fail("����������̫��������ʹ�á��������֡���");

	msg = "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n";
	
	if( random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		target->start_busy( random(me->query_skill("yunlong_jian", 1) / 30+1) );
		int damage = me->query_skill("yunlong_xinfa", 1);
		damage = damage +  me->query_skill("yunlong_shengong", 1);
		damage = damage +  me->query_skill("yunlong_jian", 1);
		if(me->Query(CChar::IS_NPC))
			damage=damage*(2+random(15));

		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->add("mp", -damage);

		msg += "ֻ��$N���н������һ������,�ڿն���,ٿ������$n,\n$nֻ��һ�ɴ�������ǵذ�ѹ��,��ʱ��ǰһ������������,�۵����һ����Ѫ����";
		me->add("mp", -100);
		me->start_busy(2);
	}
	else
	{
		msg += "����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��";
		me->add("mp", -100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
