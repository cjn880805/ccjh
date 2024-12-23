// vivien-sword.c ޱ������ 
// Create by rouma@FYtdwy(sh)
// Last Modify @ 2001-03-14
// by Teapot <������>

SKILL_BEGIN(CSvivien_sword);

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

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa"))
		return 1;

	return notify_fail("ޱ�������������Ĺ�����ڹ���Ů�ķ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge, damage,lvl;
	}action[] = {
	{"$Nʹһ�С��������С�������$w��һ�����߰����$n��",40, 200, 0,},
		{"$Nʹ��ޱ�������еġ��������������������ն��$n��",40, 210, 10, },
		{"$Nһ�С�����ٻӰ��,����$w����Ϊ������$n��", 35, 220, 20, },
		{"$N����$w�й�ֱ����һʽ���������ࡹ��׼$n�̳�һ����", 35, 250, 40,},
		{"$N����һԾ������$wһ�С�������ͷ����$nб��һ��", 45, 260, 60, },
		{"$N��$wƾ��һָ��һ�С�������ȥ������$n��", 45, 280, 80, },
		{"$N����$w����һ�֣�ʹһ�С�����֮�������ֶ�׼$nһ����ȥ��", 35, 290, 100, },
		{"$N�ὣ��ǰ������һת����$wʹһ�С�����֮�ġ�����һ���⻡����$n��", 55, 300, 120, },
		{"$Nʹ��ޱ�������е���߾������˼���ãݣ�����ͻȻ������ٻӰ�����е�$w�������������Ļ���$n��", 50, 320, 140, },
		{"ٻӰһ�֣���ʧ��������\n$w������ʧ��$NͻȻ������һ����\n$MAG��˼���õ�һʽ����ɽһ����", 120,110,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIM��˼���õڶ�ʽ������һ����", 120,120,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$RED��˼���õ���ʽ������һ����", 120,130,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIC��˼���õ���ʽ����Ůһ����", 120,140,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIB��˼���õ���ʽ����ˮһ����", 120,150,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIR��˼���õ���ʽ����˼һ����", 120,160,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$HIY��˼���õ���ʽ������һ����", 120,170,0,},
		{"$w������ʧ��$NͻȻ������һ����\n$BLU��˼�������һʽ��ٻӰһ����$GRN", 130,200,0,},
	
	};
	int level = me->query_skill("vivien_sword");

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

	return notify_fail("ʹ�����������Σ������������ꡣ");
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
	skilla=me->query_skill("vivien_sword",1);

	if( skilla < 240 )
		return notify_fail("���ޱ��������������죬ʹ���������������˼���á�");

	if( skilla > 349 )
		return notify_fail("���ޱ������̫�����ң��Ѿ��޷�ʹ�������������˼���á�");

	if( me->query("mp") < 700)	
		return notify_fail("����������㣬ʹ���������������˼���á�");

	if( !target || !me->is_fighting(target) )
		return notify_fail("����˼���á�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,�޷���ᵽ����˼���á����������į��");

	if(target->query_temp("apply/no_��˼����")&& (random(2)||target->query("bigboss")))
	{
		char msg[255];
		message_vision(snprintf(msg, 255,"$Nʹ��ޱ�������е���߾������˼���ãݣ�����ͻȻ������ٻӰ�����е�%s�������������Ļ���$n��",weapon->name(1)),me,target);
		return notify_fail(snprintf(msg, 255,"%s��ͷ��̾һ�����������ܣ�%sһ㶣�ĬĬͣ�֡�",target->name(1),me->name(1)));
	}

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





