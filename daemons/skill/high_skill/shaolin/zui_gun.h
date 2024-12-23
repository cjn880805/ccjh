SKILL_BEGIN(CSzui_gun);

virtual void create()
{
	set_name( "�������");

	Magic_t * magic;

	magic = add_magic("zuida", do_zuida);
	magic->name = "�������";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("һָ�����������ֶ����ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"�����ɺͣ�����Ȱ�������ʡ���$N����$w���ᣬ��������$n��$l",
			180, 0, 5, 10, 10,},
		{"�����ɹã������������ɲ�����$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",
		200, 5, 10, 15, 20,},
		{"���ܹ��ˣ�ǧ���������ѡ���$N����$w��ָ���أ���$n��$l��ȥ",
		230, 5, 5, 20, 30,},
		{"�������ӣ������������������$N����$w�����˻��˸���Ȧ������$n��$l",
		270, 5, 5, 25, 40,},
		{"�������룬������������������$N���й������ţ�����������$n",
		320, 10, 15, 30, 50,},
		{"��������ߵ���ɽ����ء���$N����֧�أ�һ��һ���������$n��$l",
		380, 5, 15, 35, 55,},
		{"���Ź��ϣ�����ױ�����¿����$NŤ������$w�ӿ�����������$n���ؿ�",
		450, 5, 20, 40, 60,},
		{"�������������������ǧ������$N�ڿն�����ɽ��Ӱ������ѹ��$n",
		530, 10, 25, 50, 64,},
	};

	int level = me->query_skill("zui_gun", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("����������������������");
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

virtual int valid_enable(string usage) { return (usage == "club") || (usage == "parry");}

static int do_zuida(CChar * me, CContainer * ob)	//[�������]
{
	CChar * target = NULL;
	CContainer * weapon;	
  	string msg;
	int count, count1, cnt, skill;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(! target || !me->is_fighting(target) )
	    return notify_fail("���������ֻ����ս����ʹ�á�");


	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
			return notify_fail("��ʹ�õ��������ԡ�");

	if( me->query_temp("zuida") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	if( me->query_str() < 25 )
		return notify_fail("��ı���������Ŀǰ����ʹ�ô˾���! ");

	if( me->query_skill("hunyuan_yiqi", 1) < 60)
		return notify_fail("��Ļ�Ԫһ�����Ĺ�������������ʹ�ô��������");

	if( me->query_skill("club") < 90)
		return notify_fail("��Ĺ�����Ϊ����������ʹ�ô������! ");

    if( me->query("mp") < 500 )
		return notify_fail("����������㣡");

	msg = "$HIY$Nʹ����������ľ�����������򡹣�������Ȼ����, ����Ȼ�ӿ죡$COM";
	
   	message_vision(msg.c_str(), me, target);
	skill = me->query_skill("zui_gun",1);
	cnt = me->query_condition("drunk") / 3 ;
	count = me->query("str") * random(cnt + 2);
	count1 = me->query("dex") * random(cnt + 2);

	me->add_temp("str", count);
	me->add_temp("dex", count1);
	me->set_temp("zuida", 1);

	me->call_out( remove_effect, skill / 3, count, count1);
	me->add("mp", -150);
   	return 1;
}

static void remove_effect(CContainer * ob, LONG amount, LONG amount1)
{
	CChar * me = (CChar *)ob;
	
	if (me->query_temp("zuida") ) 
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount1);
		me->delete_temp("zuida");
		tell_object(me, "$HIY��İ�������˹���ϣ��������ջص��");
		me->start_busy(4);
		me->SendState(me);
	}
}

SKILL_END;