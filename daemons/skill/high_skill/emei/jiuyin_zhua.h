// jiuyin_zhua.h �����׹�צ
//code by Fisho
//date : 2000-12-02

/*
	����������BUG���޸ġ�
	lanwood 2001-04-29
*/

SKILL_BEGIN(CSjiuyin_zhua);

virtual void create()
{
	set_name("�����׹�צ");

	Magic_t * magic;

	magic = add_magic("zhua", do_zhua);
	magic->name = "����һ��";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge, damage;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N����΢�Σ�һ�С���˼����ǡ���ʮָ��ꪣ�����$n��˫������", 
		200,10 , 0, "����", 0,},
		{"$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",
		220, 20, 0, "����", 10,},
		{"$N˫�ֺ������֣�һ�С���ָ�Ʋ����������Ȱ��ץ��$n�ļ�ͷ",
		250, 30, 0, "����", 20,},
		{"$N���ֵ��ػ��������ּ�����һ�С����µ����ա����͵�ץ��$n�Ķ�ͷ", 
		290, 25, 0, "����", 31,},
		{"$Nʹһ�С��������ķ�������������ľ��磬ײ��$n", 
		340,40, 0, "����", 43,},
		{"$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫���ջ���ǰ������һ�С�ɭȻ���׹ǡ�����ָ�繳��ֱץ��$n������", 
		400, 35, 0, "����", 56,},
		{"$Nʹ���������Բ�ɢ������Ȼ������ϣ�����$n��ת��Ȧ��$n���ۻ����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",
		430, 20,20,"����",71 ,},
		{"$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ѻ��֡���ʮָ���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ", 
		460, 5, 30,"����", 87,},
		{"$N������ӣ������������磬һ�����������$N�������ѱ�����ɫ�����ż��о���ʩչ����צ�ֹ������������ŵ�צӰ����$n��ͷ��", 
		520, 10, 20,"����", 110,},
	};
	
	int level = 0;
	
	for(int i=9; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jiuyin_zhua", 1))
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

virtual int valid_combine(string combo) { return combo=="xianglong_zhang"; }
virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	if ( me->query_weapon())
		return notify_fail("�������׹�צ������֡�");
	
    if (me->query_skill("force", 1) < 50)
		return notify_fail("����ڹ��ķ���򲻹����������׹�צ���߻���ħ��");
		if (me->query("max_mp") < 300)
			return notify_fail("�������̫�����޷��������׹�צ��");
		return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 8)
		return notify_fail("������������������׹�צ��");
    if (me->query_skill("jiuyin_zhua", 1) < 60)
		me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
}
virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("jiuyin_zhua",1)) > 50) 
	{
		victim->apply_condition("jy_poison", random(2)+1+victim->query("condition/jy_poison"));
    }

	return 0;
}

//perform 
static int do_zhua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query("repute") > 0)
        return notify_fail("�����������ʿ�������ܡ�����һ�������������书��");
	
    if( me->query_skill("jiuyin_zhua", 1) < 85 )
        return notify_fail("��ľ����׹�צ������죬��ʹ����������һ������");
	
    if( me->query_skill("force", 1) < 85 )
        return notify_fail("����ڹ��ķ���򲻹���ʹ�á�����һ�����������Լ��ľ�����");

	if(me->query("mp") < 300)
		return notify_fail("����������㡣");
	
    msg = "$NͻȻ��˫�Ʊ�צ������ǰ��Ȼ����糵�㼱ת��Ȧ������ʩչ��������һ������˫צ����һ�����������$n��ת��Ȧ���ֻص�ԭ�ء�\n";

	if(target->query_temp("apply/no_����һ��") && !random(3))
	{
		msg += "����$p������$P����ͼ������ͷ������һ�ߡ�";
	}

    else if (random(me->query_skill("force") + 1) > target->query_skill("force")/2||
        random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
		
        int damage = me->query_skill("jiuyin_zhua", 1);
		
		damage = damage + random(damage);
		
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/4);
        me->add("mp", -damage/3);
		
		msg += "ԭ��$N����$nͷ��������������������ָ����$nֻ����ͷ��һ�������������������һ���ˡ�����������";
    } 
	else
    {
        me->start_busy(4);
        msg += "����$p������$P����ͼ������ͷ������һ�ߡ�";
    }
    message_vision(msg.c_str(), me, target);
	
    //if(userp(target)) target->kill_ob(me);
    //else
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
	
}

SKILL_END;




