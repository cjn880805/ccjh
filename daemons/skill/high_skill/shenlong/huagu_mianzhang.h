
// huagu_mianzhang.h ��������
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CShuagu_mianzhang);

virtual void create()
{
	set_name( "��������");
	
	Magic_t * magic;

	magic = add_magic("hua", do_hua);
	magic->name = "���ֻ���";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N����΢�Σ�һ�С���������ǡ���ʮָ��ꪣ�����$n��˫������", 200, 10, 0, "����",},		
		{"$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",220 ,20 , 20, "����",},		
		{"$N˫�ֺ������֣�һ�С����紵�䳾�������Ȱ��ץ��$n�ļ�ͷ", 250,30 , 40, "����",},		
		{"$N���ֵ��ػ��������ּ�����һ�С�����ӳ��ɳ�����͵�ץ��$n�Ķ�ͷ", 290, 25, 60, "����",},		
		{"$Nʹһ�С�ɭȻ���ķ�������������ľ��磬ײ��$n", 340, 40, 80, "����",},		
		{"$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ֹǺ�����ʮָ���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ", 460, 30, 100, "����",},		
		{"$Nʹ������ɳƮ���꡹����Ȼ������ϣ�����$n��ת��Ȧ��$n���ۻ����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�", 430, 20, 120, "����",},		
		{"$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫���ջ���ǰ������һ�С��׹����޺�������ָ�繳��ֱץ��$n������", 400, 35, 140, "����",},		
	};
 
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		level++;
		if(action[i - 1].lvl < me->query_skill("huagu_mianzhang", 1))
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
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="shenlong_bashi"; }

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("���������Ʊ�����֡�");
	if (2* me->query_skill("shenlong_xinfa",1) < me->query_skill("shenlong_bashi",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�������ơ�");
    if ( me->query_skill("force", 1) < 50)
		return notify_fail("����ڹ��ķ���򲻹������������ƻ��߻���ħ��");
    if ( me->query("max_mp") < 300)
		return notify_fail("�������̫�����޷����������ơ�");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
        return notify_fail("�������̫���ˡ�");
    if ( me->query("mp") < 8)
        return notify_fail("��������������������ơ�");
    if (me->query_skill("huagu_mianzhang", 1) < 60)
        me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
	
}

virtual char * hit_ob(CChar * me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("huagu_mianzhang",1)) > 50) 
	{
		victim->receive_damage("hp", random(2) + 1);
    }
	return "";
}


//perform 
static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( (me->environment())->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! ");
	
	if( !target || ! me->is_fighting(target) )
		return notify_fail("���ֻ���ֻ�ܶԶ���ʹ�á�");
	
	if(  me->query_skill("shenlong_xinfa", 1) < 50 )
		return notify_fail("��������ķ�������죬���ܻ��ǡ�");
	
	if(  me->query_skill("huagu_mianzhang", 1) < 40 )
		return notify_fail("��Ļ������Ʋ�����죬���ܻ��ǡ�");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if(  me->query("mp") < 300 )
		return notify_fail("����������������ܻ��ǡ�");
	
    me->add("mp", -100);
	
	msg =   "$N�Ƴ������������$n��ͷ�ϡ�\n" ;
	
	me->start_busy(1);
	if( random(  me->query_skill("huagu_mianzhang",1))
		> random(target->query_skill("dodge"))+1 )
    {
		msg +=   "���ֻ���˵�һ����$p��$Pһ�����У�"  ;
		msg +=   "$pֻ����ȫ��ů����ģ��е��е���Ʈ�����ᡣ"  ;
		target->add_temp("apply/attack", -3);
		target->add_temp("apply/dodge", -3);
		target->add_temp("apply/defense", -3);
	}
	else 
	{
		msg +=  "����$p��æ����һ�ԣ����˿�ȥ��"  ;
		me->start_busy(3);
	}
	message_vision(msg.c_str(), me, target);
	//if( !target->is_fighting(me) ) target->kill_ob(me);
	return 1;
}

SKILL_END;
