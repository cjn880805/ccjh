// vivien-sword.c ޱ������ 
// Create by rouma@FYtdwy(sh)
// Last Modify @ 2001-03-14
// by Teapot <������>

SKILL_BEGIN(CSviviensword);

virtual void create()
{
	set_name( "ޱ������");

	Magic_t * magic;

	magic = add_magic("freeze", do_freeze);
	magic->name = "��˼����";
	magic->mp = 700;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge, damage,lvl;
	}action[] = {
	{"$Nʹһ�С��������С�������$w��һ�����߰����$n��",0, 0, 0,},
		{"$Nʹ��ޱ�������еġ��������������������ն��$n��",0, 0, 0, },
		{"$Nһ�С�����ٻӰ��,����$w����Ϊ������$n��", 0, 0, 0, },
		{"$N����$w�й�ֱ����һʽ���������ࡹ��׼$n�̳�һ����", 0, 0, 0,},
		{"$N����һԾ������$wһ�С�������ͷ����$nб��һ��", 0, 0, 0, },
		{"$N��$wƾ��һָ��һ�С�������ȥ������$n��", 0, 0, 0, },
		{"$N����$w����һ�֣�ʹһ�С�����֮�������ֶ�׼$nһ����ȥ��", 0, 0, 0, },
		{"$N�ὣ��ǰ������һת����$wʹһ�С�����֮�ġ�����һ���⻡����$n��", 0, 0, 0, },
		{"$Nʹ��ޱ�������е���߾������˼���ãݣ�����ͻȻ������ٻӰ�����е�$w�������������Ļ���$n��", 0, 0, 0, },
		{"ٻӰһ�֣���ʧ��������\n$w������ʧ��$NͻȻ������һ����\n$MAG��˼���õ�һʽ����ɽһ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIM��˼���õڶ�ʽ������һ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$RED��˼���õ���ʽ������һ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIC��˼���õ���ʽ����Ůһ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIB��˼���õ���ʽ����ˮһ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIR��˼���õ���ʽ����˼һ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIY��˼���õ���ʽ������һ����", 0,0,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$BLU��˼�������һʽ��ٻӰһ����$GRN", 0,0,0,},
	
	};
	int level = me->query_skill("vivnensword");

	CContainer * weapon;
	weapon = me->query_weapon();

	level = random(8);
		if (me->query_temp("teapot/vivien"))
		{
			m_actions.set("action", action[(me->query_temp("teapot/vivien")+7)].action);
		}
		else
		{
			m_actions.set("action", action[level].action);
		}

		m_actions.set("dodge", action[level].dodge);
		m_actions.set("damage", action[level].damage);


	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") > 2000)
		return notify_fail("�������̫�ࡣ");

	if (me->query("age") > 30)
		return notify_fail("������̫�ϣ��޷������˼���⡣");

	if (me->query("age") <16)
		return notify_fail("������̫С���޷������˼���⡣");

	if (me->query("pks") >0 )
		return notify_fail("��ɱ��̫�أ��޷������˼���⡣");

	if (me->query("pds") >0 || me->query("mds")>5 )
		return notify_fail("������̫��޷������˼���⡣");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("ʹ�����������Σ������������ꡣ");
}


static int do_freeze(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon = me->query_weapon();

	if(ob && ob->is_character())
		target = (CChar *)ob;


	int skilla;
	skilla=me->query_skill("viviensword",1);

	if( skilla < 240 )
		return notify_fail("���ޱ��������������죬ʹ���������������˼���á�");

	if( skilla > 299 )
		return notify_fail("���ޱ������̫�����ң��Ѿ��޷�ʹ�������������˼���á�");

	if( me->query("mp") < 700)	
		return notify_fail("����������㣬ʹ���������������˼���á�");

	if( !target || !me->is_fighting(target) )
		return notify_fail("����˼���á�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (userp(me))
	{
		me->add("mp",-700);
		me->set("mp_factor",0l);
	}

	for(int n = 0; n < 9; n++)
	{
		me->set_temp("teapot/vivien",n);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	}

	me->start_busy(3);

	me->set_temp("teapot/vivien",9);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->delete_temp("teapot/vivien");
	return 1;
}


const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[6][255] ={
		"$nʹ��һ�С������������е�$W����һ�����磬�Ŀ���$N��",
		"$nʹ�����İ�����$W����ȥ����$N�������⡣",
		"$nʹ��һ�С������������е�$W��������ѩӰ��������$N��$w��",
		"$n���е�$Wһ����һ�С��ﰮ�����������ƬƬ��$N�ѱ��ȿ���",
	};

	if(! weapon) return 0;
	return parry_msg[random(4)];
}


SKILL_END;





