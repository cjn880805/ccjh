// huoyan_dao.h ���浶
SKILL_BEGIN(CShuoyan_dao);

virtual void create()
{
	set_name( "���浶");

	Magic_t * magic;

	magic = add_magic("fen", do_fen);
	magic->name = "�����Ի�";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*
	magic = add_magic("dian", do_dian);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
  }

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("���浶������ѩɽ�ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, lvl, damage;
	}action[] = {
		{"$Nʹ��һ�С���ľȡ�𡹣�����ת��˫����ǰƽƽ����$n", 150, 0, 60,},
		{"$Nʹ��һ�С�ף�ڻ��桹�������絶��бб����$��$l", 180, 10, 80,},
		{"$Nʹ��һ�С�����ޱߡ���˫��һ�ģ�һ�����������й���$n��$l", 200, 20, 100,},
		{"$Nʹ��һ�С������ֻء���˫�ֺ�ʮ����ͷ����$n", 250, 30, 100,},
		{"$Nʹ��һ�С�˫�����桹��˫��һ�������������湥��$n��$l", 300, 40, 100,},

		{"$Nʹ��һ�С���ɽ�𺣡���˫������б�ģ���ʱ��ǧ������������˷�����$n", 350, 60, 100,},
		{"$Nʹ��һ�С��׷��ȡ�����ۻ��գ�����������ֱ��$n��$l", 400, 80, 100,},
		{"$Nʹ��һ�С�������������˫��΢��������ǰ�죬һ���ھ�����ɽ�����㹥��$n", 500, 100, 100,},
	};

	int level = me->query_skill("huoyan_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�����浶������֡�");
	else if (me->query("max_mp") < 300)	//���浶Ҫ�кܸߵ���������ѧ
		return notify_fail("�������������");
	if (me->query_skill("longxiang", 1) >= 60 ||
	    me->query_skill("xiaowuxiang", 1) >= 60)
		return 1;
	else if (me->query_skill("longxiang", 1) < 60)
		return notify_fail("���������������̫ǳ��");
	else if (me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("���С���๦���̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�����浶������֡�");
	
	if (me->query("hp") < 50)
		return notify_fail("������������������˻��浶��");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_fen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	! me->is_fighting(target) )
		return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if ( me->query_weapon() )
		return notify_fail("���������˹���");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	int skill = me->query_skill("huoyan_dao",1);
	if( skill < 60)
		return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�");
	if( me->query("mp") < 150 )
		return notify_fail("��������������޷��˹���");

	msg = "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n";
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("mp",-100);
		msg += "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��";
		
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		
		int qi_wound = neili_wound / 5;
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->add("hp",-qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg += "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����";
		if(userp(me))
			me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( me->query_weapon() )
		return notify_fail("���������˹���");

	if(DIFFERSTR(me->querystr("family/family_name"), "ѩɽ��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	int skill = me->query_skill("huoyan_dao",1);
	if( skill < 60)
		return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������򡹣�");
	if( me->query("mp") < 100 )
		return notify_fail("��������������޷��˹���");

	msg = "$HIR$N�������ƣ�ʹ��һ�С������򡹣��������������ȥ��\n";
		

	msg += "$HIR����ֻ��һ�����������$N��������򱻵�ȼ�ˣ�����";
		
		me->add("mp", -100);
		me->start_busy(random(3));

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;
