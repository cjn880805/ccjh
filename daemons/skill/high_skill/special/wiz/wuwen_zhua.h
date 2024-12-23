// wuwen_zhua.h ����צ
//code by oho
//date : 2001-3-20

SKILL_BEGIN(CSwuwen_zhua);

virtual void create()
{
	set_name( "����צ");

	Magic_t * magic;

	magic = add_magic("nv", do_zhua);
	magic->name = "����Ů";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N�˻���צ��һ�С������֡��������Ϸ������ĵ������ת�����ؾ���$n��˫��", 10,10 ,"����", 0,},
		{"$Nȫ�������Ȼͻ����˫צ���½�Ϯ��һ�С���������Ҫ��$n�����ڵ�",12 , 20,"����", 10,},
		{"$N����Ծ�𣬰��ת��һ�С�ץ�ڡ���������ɫ�Ļ��ץ��$n�Ķ�ͷ", 15, 20,"����", 10,},
		{"$N���д���,��ǰһ��������ײ��$n�ؿڣ�����˳��Ծ��һת��һ�С����ա�����Χ����Ȧ��ɫ��⡣", 29, 25,"����", 11,},
		{"$N�߸�̧����ţ��͵�һ�С��丫���������ֱ��$n�ļ��", 20,20 ,"����", 13,},
		{"$NͻȻ����Ծ��$n��ͷ��������л���һ�С��ٺ��ۡ�����$n�ĺ���", 24, 25,"����", 16,},
		{"$Nʹ����м�硱����Ȼ������ϣ���$n���������$n�����ͷ��$N��צ�Ѿ�����󣬽�$n˳��һ����", 20,20 ,"����",21 ,},
		{"$Nʹ�����С��˾Ʊ�������¶��Ц�������͵ؽ��������һ������ն�ʱɢ��������������Ѹ���ޱȵ�Ϯ��$n", 5, 30,"����", 27,},
		{"$N��������������$n�°ͣ������ŷ���Ծ��,���㲢�ã�����$nͷ�������������ɾ��С�������", 10, 20,"����", 50,},
	};
	
	int level = 0;
	
	for(int i=9; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuwen_zhua", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("������צ������֡�");
	
    if (me->query_skill("force", 1) < 20)
		return notify_fail("����ڹ��ķ���򲻹���������צ�ᱻ�Լ�������");
		if (me->query("max_mp") < 100)
			return notify_fail("�������̫�����޷�������צ��");
		return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 8)
		return notify_fail("�����������������צ��");
    if (me->query_skill("wuwen_zhua", 1) < 60)
		me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
}
virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("wuwen_zhua",1)) > 50) 
	{
		victim->apply_condition("wuwen_poison", random(2)+1+victim->query_condition("wuwen_poison"));
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
		return notify_fail("������Ů��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if( me->query("repute") > 0)
        return notify_fail("�����������ʿ���������á�����Ů�����������书��");
	
    if( me->query_skill("wuwen_zhua", 1) < 15 )
        return notify_fail("�������צ������죬��ʹ����������Ů����");
	
    if( me->query_skill("force", 1) < 35 )
        return notify_fail("����ڹ��ķ���򲻹���ʹ�á�����Ů����Ū���Լ�ָ�ס�");

	if(me->query("mp") < 100)
		return notify_fail("����������㡣");
	
    msg = "$NͻȻ���߾�˫ץ��Ȼ�����һ��ͻ����ʩչ��������Ů����˫צ�����ץ�����ץס$n�ز������Ļ����ڰ������³���\n";
	
    if (random(me->query_skill("force") + 1) > target->query_skill("force")/2||
        random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
		
        int damage = me->query_skill("wuwen_zhua", 1);
		
		damage = damage + random(damage);
		
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/4);
        me->add("mp", -damage/3);
		
		msg += "$nȫ���Ż����˿��������Ѫ��������������ǰ��������������.";
    } 
	else
    {
        me->start_busy(5);
        msg += "����$p������$P����ͼ�������ض�����һ�ߡ�";
    }
    message_vision(msg.c_str(), me, target);
	
    //if(userp(target)) target->kill_ob(me);
    //else
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
	
}

SKILL_END;
