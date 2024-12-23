// wudu_shenzhang.h �嶾����
SKILL_BEGIN(CSwudu_shenzhang);

virtual void create()
{
	set_name( "�嶾����");

	Magic_t * magic;

	magic = add_magic("jiedu", do_jiedu);
	magic->name = "�ⶾ��";
	magic->mp = 300;
	magic->target = CAST_TO_RANDOM;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge, force;
	}action[] = {
			{"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
			30, 210,},
			{"$NͻȻ����������$n��˫�Ʒ�������$n��$l",
			10, 210,},
			{"$N�������������֣������ޱȵ�ץ��$n��$l",
			-20, 210,},
			{"$N˫�����,��������$n��$l",
			10, 210,}
	};

	int level = random(4);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", me->query_skill("wudu_shenzhang",1)/2 );

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }


virtual int valid_learn(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("ֻ�й�Ĺ�ɵ��ӷ���ѧϰ��");
	if ( me->query_weapon() )
		return notify_fail("���嶾���Ʊ�����֡�");
	if (me->query_skill("wudu_xinfa", 1) < 10)
		return notify_fail("����嶾�ķ���򲻹����޷����嶾���ơ�");
	if (me->query("max_mp") < 60)
		return notify_fail("�������̫�����޷����嶾����");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��"))
		return notify_fail("ֻ�й�Ĺ�ɵ��ӷ�����ϰ��");
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 8)
		return notify_fail("��������������嶾���ơ�");
	if (me->query_skill("wudu_shenzhang", 1) < 50)
		me->receive_damage("hp", 20);
	else
		me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}

     if( random(me->query_skill("wudu_xinfa")) > 150 &&  !wizardp(me) && (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��")) )
	{
        victim->apply_condition("wuduz_poison", (me->query_skill("wudu_shenzhang")/10) + 1 +
            victim->query("condition/wuduz_poison"));
	}

	if( random(me->query_str()) > victim->query_str())  
	{
	//	victim->receive_wound("hp", (damage - 100) / 2 );
		victim->receive_wound("hp", (me->query_skill("wudu_xinfa", 1)/3+me->query_skill("wudu_shenzhang", 1)/3)*(random(10)+1)); //�ز� 2002��1��15
		return "���������项һ�����죬$n��й����Ƥ�򻺻���̱����";
	}

	return 0;
}

static int do_jiedu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

    if( !ob || !ob->Query(CChar::IS_CHAR) )
		return notify_fail("��Ҫ��˭�ⶾ��");

	target = (CChar *)ob;

    if( me->query_skill("wudu_xinfa", 1) < 40 )
        return notify_fail("����嶾�ķ�������죬���ܽ��嶾���ơ�");

    if( me->query_skill("wudu_shenzhang", 1) < 40 )
        return notify_fail("����嶾���Ʋ�����죬���ܽ��嶾���ơ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

    if( me->query("mp") < 300 )
        return notify_fail("����������̫�������ܽⶾ��");
                
    if( target->query("condition/wuduz_poison") < 1)
		return notify_fail("û���ж���");

    me->add("mp", -300);
    target->apply_condition("wuduz_poison", 0);
	if(me == target)
	{
		message_vision("$Nʹ���嶾����֮�ⶾ�������Լ�������", me);
	}
	else
	{
		target->SendState();
		message_vision("$Nʹ���嶾���ƽⶾ���ַ�Ϊ$n���á����Ÿ�$n����һ����ҩ.", me, target);
	}

    return 1;
}

SKILL_END;




