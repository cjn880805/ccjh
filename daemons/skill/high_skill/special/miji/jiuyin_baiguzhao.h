//jiuyin_baiguzhao.h �����׹�צ
//code by sound
//date : 2001-07-23

SKILL_BEGIN(CSjiuyin_baiguzhao);

virtual void create()
{
	set_name("�����׹�צ");
	
	Magic_t * magic;
	
	magic = add_magic("zhua", do_zhua);
	magic->name = "����һ��";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
	
	magic = add_magic("cuijin", do_zhua);
	magic->name = "�ݽ��ƹ�";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge, damage;
		int  lvl;
		char damage_type[5];
	}action[5] = {
		{"$N��צ��Σ���צ������һ�С�������ǡ�ֱ����$n��$l", 
		320, 10, 30, 0, "����",},
		{"$N˫��������צ��צצ����$n������������������$n��$lץ��",
		380, 20, 45, 20, "����",},
		{"$N����Χ$nһת��ʹ�������޵�������$n��$l����ȫ������צӰ��",
		440, 30, 55, 40, "����",},
		{"$Nʹһ�С������ơ���˫צ�ó�����צӰץ��$nȫ��", 
		520, 40, 70, 60, "����",},
		{"$N����������һ�С�Ψ�Ҷ���˫צ������$n�������", 
		620, 50, 100, 100, "����",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jiuyin_baiguzhao", 1))
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

virtual int valid_enable(string usage) 
{ 
	return usage == "claw" || usage == "unarmed" || usage == "parry";
}

virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
	
	if( random(damage_bonus/2) > victim->query_str() ) 
	{
		victim->receive_wound("hp", (damage_bonus - 100) / 2 );
		return "$HIR��������������һ�����죬�����ǹ����������$COM\n";
	}
	return 0;
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("�������׹�צ������֡�");
	
	if (me->query_skill("force", 1) < 50)
		return notify_fail("����ڹ��ķ���򲻹����������׹�צ���߻���ħ��");

	if (me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷��������׹�צ��");

	return 1;
}

virtual int practice_skill(CChar * me)
{

	if( me->query("hp") < 250)
		return notify_fail("�������̫���ˡ�");

	if( me->query("mp") < 250)
		return notify_fail("������������������׹�צ��");

	if( (me->environment())->query("no_fight") )
		return notify_fail("�����������������ˡ�");

	if( (me->environment())->query("sleep_room") )
		return notify_fail("������������ű�����Ϣ��");

	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_CORPSE))
		&& ! (obj = me->PresentName("corpse_ob", IS_CORPSE)) )
		return notify_fail("�������׹�ץ����ʬ�塣");

	if( me->query_skill("jiuyin_baiguzhao",1) > 100 && me->query("repute") > -100)
		return notify_fail("����а���书��������������ġ�");

	me->receive_damage("hp", 40);
	me->add("mp", -100);
	char msg[255];
	tell_room(me->environment(), snprintf(msg, 255, "$HIBֻ��%s������Ȧ�¹���������ת���������߰˰㻨�������������һ�죬�۵�һ�죬�����ֱָ�������ʬ������š���������ָ$HIRѪ����$HIB���Ὣ������", me->query("name")), me);
/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]==me ) continue;
		if(skill+random(skill/2)<ob[i]->query("con")*2) continue;
		damage = skill - (ob[i]->query("mp") );
		if( damage > 0 )
		{
			ob[i]->receive_damage("hp", damage );
			if( ob[i]->query("mp") < skill * 2 )
				ob[i]->receive_wound("hp", damage);
			tell_object(ob[i], 
				HIB"��Ȼ��ǰ��Ӱ���裬�������ǰһ������ֱϮ���ţ�ȫ����Ȼ�е�Ҫ��˺�ѿ�һ����$COM\n");
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
*/
	return 1;
}

virtual void skill_improved(CChar * me)
{
    tell_object(me, "$HIR���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�$COM\n" );
    me->add("repute", -200);
}

// zhua.c  �����׹�צ������һ����
static int do_zhua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    int extra = me->query_skill("jiuyin_baiguzhao",1);

	if( !target ||! me->is_fighting(target) )
        return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query("repute") > 0)
        return notify_fail("�����������ʿ�������ܡ�����һ�������������书��");
	
    if( me->query_skill("jiuyin_baiguzhao", 1) < 85 )
        return notify_fail("��ľ����׹�צ������죬��ʹ����������һ������");

    if( me->query("mp") < 300 )
		return notify_fail("�����������ˡ�");

    if( me->query_skill("force", 1) < 85 )
        return notify_fail("����ڹ��ķ���򲻹���ʹ�á�����һ�����������Լ��ľ�����");

	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);

	message_vision("$HIR$NͻȻ��˫�Ʊ�צ������ǰ��Ȼ����糵�㼱ת��Ȧ������ʩչ��������һ������˫צ����һ�����������$n��ת��Ȧ���ֻص�ԭ�ء�$COM\n", me, target);
	
//	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

    me->add("mp", -100);
	me->start_busy(2);
	me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra*2);

    return 1;
}

// cuijin.c  �����׹�צ���ݽ��ƹǡ�
static int do_cuijin(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    int damage;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("���ݽ��ƹǡ�ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query_skill("jiuyin_baiguzhao", 1) < 180 )
		return notify_fail("$WHT��ľ����׹�צ������죬��ʹ�������ݽ��ƹǡ���$COM");

    if( me->query_skill("force", 1) < 180 )
		return notify_fail("$RED����ڹ��ķ���򲻹���ʹ�á��ݽ��ƹǡ��������Լ��ľ�����$COM");

    if( me->query("mp") < 800 )
		return notify_fail("�����������ˡ�");

    msg = "$HIC$Nһ����Х������$n��ת��Ȧ������ʩչ�����ݽ��ƹǡ���˫צ�����ֱ��$nǰ�ء�$COM\n";

    if (random(me->query("combat_exp")) > target->query("combat_exp")/2)
	{
		if (me->query("mp") > target->query("mp")/2)
		{
			me->start_busy(3);
			damage = target->query("max_hp");
			target->receive_damage("hp", damage/2);
			target->receive_wound("hp", damage/2);                         
			me->add("mp", -300);

			msg += "$HIR$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������$COM\n";
		} 
		else 
		{
			me->start_busy(3);
			damage = target->query("max_hp");
			target->receive_damage("hp", damage/20);
			target->receive_wound("hp", damage/20);                         
			me->add("mp", -400);

			msg += "$HIY$Nֻ��$n�������˫צ�����ܹ��ض���,ֻ��$n��ǰ������һ��Ѫ�ۣ�����$COM\n";
		} 
	} 
    else
	{
		me->start_busy(3);
		me->add("mp", -300);
		msg += "$HIY����$p���з��������Ų�æ,ж����$P��˫צ��$COM\n";
	}
	message_vision(msg.c_str(), me, target);

	if( !target->is_killing(me) ) target->kill_ob(me);
/*
    if(userp(target)) target->fight_ob(me);

    else if( !target->is_killing(me) ) target->kill_ob(me);
*/
    return 1;
}

SKILL_END;
