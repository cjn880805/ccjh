//liangyi-jian.c ���ǽ���

SKILL_BEGIN(CSliangyi_jian);

virtual void create()
{
	set_name( "���ǽ���");
	set("valid_force", "taiji_shengong");

	
	Magic_t * magic;

	magic = add_magic("ren", do_ren);
	magic->name = "���ͬ��";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge, damage, lvl;
	}action[] = {
		{"$N���⽣â������һ�С��������ء�������$w�����´󿪴��أ�һ��б�ϴ���$n��$l",
			20, 180, 0, },
		{"$N����Ȧת������$w��ճ������ƽƽչչ�ӳ���һ�С��������������Ữ��$n��$l", 
			20, 190, 10, },
		{"$N��������������������������$wʹ��һʽ��Ԩ����ǳ������$n��$l", 
			15, 200, 20, },
		{"$N������ָ��������ת��һ�С�ˮ����ơ�ֱȡ$n��$l", 
			15, 230, 30, },
		{"$N��â���£��������ߣ�����$wʹ��һʽ���ƺ����¡������Ƽ����������$n��$l", 
			25, 250, 40, },
		{"$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ�����ѵ�ׯ��ԾԾ����Ʈ��$n��$l", 
			25, 260, 50, },
		{"$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������ǡ�����������֮�ƣ�����$n��$", 
			15, 270, 60, },
		{"$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���ϵ�̳������¶��ϴ���$n��$l", 
			35, 280, 80, },
	};

	int level = me->query_skill("liangyi_jian", 1);

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage=="sword" ||  usage=="parry"; 
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if (me->query("max_mp") < 200)
		return notify_fail("�������������");
	if (me->query_skill("taiji_shengong", 1) < 50)
		return notify_fail("���̫���񹦻��̫ǳ��");
	if (me->query_skill("sword", 1) < me->query_skill("liangyi_jian", 1) )
		return notify_fail("��Ļ����������̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("����������������ǽ�����");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_ren(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target = NULL;
	CContainer * weapon;
	int damage;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("�����ͬ�ʡ�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʲô��Ц��ûװ��������ʹ�����ͬ�ʡ���");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
		return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if (me->query_skill("liangyi_jian", 1) < 60 )
		return notify_fail("�����ǽ���������죬ʹ���������ͬ�ʡ���");
	
	if (me->query_skill("taiji_shengong", 1) < 90 )
		return notify_fail("��̫���񹦻�򲻹���ʹ���������ͬ�ʡ���");
	
	if (me->query("max_mp")<400)
		return notify_fail("��������Ϊ���㣬�޷�����������");
	
	if (me->query("mp")<200)
		return notify_fail("����������������û�ܽ������ͬ�ʡ�ʹ�꣡");

    msg = "$N���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$n��$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�\n";

    if (random(me->query_skill("force")) > target->query_skill("force")/2 || 
		random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = me->query_skill("liangyi_jian", 1) + me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/3);
		msg += "$n��æ��ת��ȴ����$N�Ľ�����û����ƫ��һʽ�����ͬ�ʡ���$n��������һ��Ѫ����$nһ��ͷ�������ؿ���ѪӿȪ�����";
        me->add("mp", -damage/5);
    }
	else
    {
        me->start_busy(2);
		msg += "����$n����һЦ��������ת����Ȼ$N�Ľ�ʽͻȻ��չ����$n��ǰ�����������硣һ����ë��û�˵���";
    }
	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
