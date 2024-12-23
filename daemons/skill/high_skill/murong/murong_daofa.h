// murong_daofa.h Ľ�ݵ���
SKILL_BEGIN(CSmurong_daofa);

virtual void create()
{
	set_name( "Ľ�ݵ���");
/*
	Magic_t * magic;

	magic = add_magic("yingzhang", do_yingzhang);
	magic->name = "��Ӱ��";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("Ľ�ݵ�����������Ԫ�����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N���һ�������С���һ�С�����ǵ���׳־�����������϶�����$n��$l��ȥ", 
		160, 10, 30, 0, "����",},
		{"$Nһ�С��䵶��ת��Ǭ����������$w�ڿ��м���ת����Ȧ������$n��$l��", 
		200, 10, 60, 30, "����",},
		{"$N��һ����һ�С�ң����ǧ��ѩ��,$wֱ��$n�ľ���նȥ", 
		260, 5, 90, 70, "����",},
		{"$Nһ�С�׳־���������������������⻯����㷱�ǣ���$n��$l��ȥ", 
		300, 5, 120, 100, "����",},
	};

	int level = me->query_skill("murong_daofa", 1);
	for(int i=4; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			m_actions.set("damage_type", action[level].damage_type);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	
	if (me->query_skill("shenyuan_gong", 1) < 20)
		return notify_fail("�����Ԫ�����̫ǳ��");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 40)
		return notify_fail("�������������Ľ�ݵ�����");

	if (me->query("mp") < 15)
		return notify_fail("�������������Ľ�ݵ�����");

	me->receive_damage("hp", 25);
	me->receive_damage("mp", 8);
	return 1;
}
/*
static int do_yingzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	int d=me->query_skill("yanling_shenfa",1)/5;
	int j=me->query_skill("murong_daofa", 1)/5;
	int i=me->query_skill("xingyi_zhang", 1)/5;

//	weapon = me->query_temp("weapon");
	weapon = me->query_weapon();

	if( !target || ! me->is_fighting(target))
		return notify_fail("��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( me->query_skill("murong_daofa", 1) < 100 )
		return notify_fail("��ĵ�����δ���ɣ�����ʹ�õ�Ӱ�ƣ�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("������û�е����޷�ʹ�õ�Ӱ�ƣ�");

	if( me->query_skill("xingyi_zhang", 1) < 100 )
		return notify_fail("����Ʒ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�");

	if( me->query("mp") < 600 )
		return notify_fail("�������������㣬����ʹ�õ�Ӱ�ƣ�");

	if( me->query_skill("blade", 1) < 100 )
		return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�");

	if( me->query_skill("strike", 1) < 100 )
		return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�");

	msg += "\n$YEL$N���һ��ʹ����Ӱ�ƣ����浶�ߣ������м����������Ʒ�һ����$n��$COM";
	me->add("mp", -250); 
	me->add_temp("apply/dodge", d); 
	me->add_temp("apply/attack", (i+j)/2); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	weapon->unequip(); 
	msg += "$YEL$N�������ƣ����η�ת��$COM\n";
	me->add_temp("apply/strike", i/2); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	msg += "$YEL$N���ƻ��������η�ת��$COM\n";
	me->add_temp("apply/strike", -i/2); 
	weapon->wield(); 
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	me->add_temp("apply/attack", -((i+j)/2)); 
	me->add_temp("apply/dodge", -d); 
        me->start_busy(5);

        return 1;
}
*/
SKILL_END;
