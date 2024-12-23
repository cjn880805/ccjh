//xingxiu_duzhang.h ���޶���
SKILL_BEGIN(CSxingxiu_duzhang);

virtual void create()
{
	set_name( "���޶���");
	set("valid_force", "huagong_dafa");

	Magic_t * magic;

	magic = add_magic("sandu", do_sandu);
	magic->name = "ɢ����";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("throw", do_throw);
	magic->name = "ʩ����";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int dodge, force;
	}action[] = {
		{ "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
			-10, 160,},
		{"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
		-10, 160,},
		{"$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
		-20, 150,},
		{"$N˫��Ю��һ���ȳ�֮������$n��$l",
		10, 160,},
		{"$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n",
		0, 300},
	};
	
	int level = random(4);
	
	if (random (me->query_skill("unarmed",1)) > 60 &&
		me->query_skill("force",1) > 50 &&
		me->query("mp") > 100 ) 
	{
        me->add("mp", -100);
		level = 4;
	}
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
        return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 8)
        return notify_fail("����������������޶��ơ�");
    if (me->query_skill("xingxiu_duzhang", 1) < 50)
        me->receive_damage("hp", 20);
    else
        me->receive_damage("hp", 30);
	me->add("mp", -5);
    return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�����޶��Ʊ�����֡�");
    if (me->query_skill("huagong_dafa", 1) < 10)
		return notify_fail("��Ļ����󷨻�򲻹����޷������޶��ơ�");
    if (me->query("max_mp") < 60)
		return notify_fail("�������̫�����޷������޶��ơ�");
    return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="sanyin_wugongzhao"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)

{
	if( random(me->query_skill("poison") + 1) > 50 ) 
	{
		victim->apply_condition("xx_poison", random(me->query_skill("poison")/10) + 1 +
			victim->query("condition/xx_poison"));

	}
	return 0;
}

static int do_sandu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->Query(IS_CHAR))
		target = (CChar *)ob;
	
	if( !me->query("condition/poison_sandu"))
		return notify_fail("������û����ɢ��");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! ");
	
	if(!target || ! userp(target) || wizardp(target) )
		return notify_fail("ɢ��ֻ�ܶ����ʹ�á�");
	
	if( target->query_combat_exp() < me->query_combat_exp()/2 )
		return notify_fail("������ɢ����û�õġ�");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ɢ����");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query_skill("xingxiu_duzhang", 1) < 40 )
		return notify_fail("������޶��Ʋ�����죬����ɢ����");

	if(me->query("mp") < 20)
		return notify_fail("����������㡣");
	
	msg = "$HIRֻ����$N�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n���󣬽������������ģ�ԴԴ���ϴ���$n���ڡ�\n";
	me->add("mp", -20);

	me->start_busy(1);
	if( random( me->query_skill("xingxiu_duzhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		msg += "���$p����������$P�ı�����������ɢ��$n���ڣ�";
        target->receive_damage("hp",20);
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("poison_sandu", 1000);
		me->clear_condition();
        target->start_busy(1 + random(2));
	} else 
	{
		msg += "����$p������������һ�𣬽�$N�������˿�ȥ��";
		me->start_busy(3);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

static int do_throw(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! ");
	
	if( !target || target == me)
		return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ʩ����");
	
	if( me->query_skill("xingxiu_duzhang", 1) < 40 )
		return notify_fail("������޶��Ʋ�����죬����ʩ����");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( me->query("mp") < 20)
		return notify_fail("����������㡣");
	
	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_CORPSE))
		&& ! (obj = me->PresentName("corpse_ob", IS_CORPSE)) )
		return notify_fail("����Χû��ʬ�塣");
	
	msg = "$N˳��ץ��ʬ�壬�������������ϣ�����$n��\n";
	me->add("mp", -20);

	me->start_busy(1);
	if( random( me->query_skill("xingxiu_duzhang",1))
		> random(target->query_skill("dodge") - 1) ) 
	{
		msg += "$HIR���$p��$P���˸����ţ�ʬ��ը�������õ�ʬҺ����$p�����ǣ�";
        target->receive_damage("hp", me->query_skill("poison",2)*(1+me->query_temp("apply/ʩ����")*random(100)/100));
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("xx_poison", random(me->query_skill("poison",1)/2) + 1 +
			target->query("condition/xx_poison"));
		target->start_busy(1 + random(2));
	} 
	else 
	{
		msg += "����$p��æ����һ�ԣ����˿�ȥ��";
		me->start_busy(1);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	DESTRUCT_OB(obj, "xingxiu_duzhang::do_throw");
	return 1;
}

SKILL_END;