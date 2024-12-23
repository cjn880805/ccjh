
// zuoyou_boji.h ���Ҳ���֮��
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSzuoyou_boji);

virtual void create()
{
	set_name( "���Ҳ���֮��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$NͻȻ��������ȭ����һ�٣��·�����ס��һ����$n���������ƣ�ȴͻȻ����һ��ȭͷ���ž�������Լ�������", 300, 15, 0,"����",},
		{"$N���κ�Ȼһ���������Ѿ����ƣ�б���Ϸ��˲��ϲ���ؼ���$n��С��", 325,55 ,10 ,"����",},
		{"$N�����ȭ��������һ�ģ��漴ֱ��������ع���$n��ͷ��", 350, 10, 20,"����",},
		{"$NͻȻ������������Լ������⣬������ָ�ſ�������Ѹ�ٵػ���$n����������������$n����������һ����ָɽ", 375, 45, 30,"����",},
		{"$N˫��һ�ģ��漴���ƹ���$n����磬$n��æ�мܣ�$N������ȴ�ѱ�ȭ�͵ص���$n���ؿ�", 400, 30, 40,"����",},
		{"$N�����£������ϵ�ǰ��һ�࣬�漴һ�������ƴ������ϻ������Ƴ�һ������֮��Ϯ��$n���ؿ�", 425, 15, 50,"����",},
		{"$N˫������ǰһ��Ȼ�����ֱ�ȭ����$n��ͷ����$n�����ո񿪣�ȴ����$N�������������Լ��������£����ɴ�",450 , 50, 60,"����",},
		{"$N�����͵�ץס�Լ�����ۣ�������һת�����ѱ��ƣ����������ֵ�������ǰ�����������$n��$l", 500, 40,70 ,"����",},
		{"$NͻȻ���ǰ�ұۺ󣬳�ʮ���μ�����ǰ��Ȼ���ұ���Ȼ������»�������ȭ����б���������ͻ�$n�����ǣ�", 550, 5, 80,"����",},
		{"$N��Ȼԭ�ص������һת��$n��ǰ��ʧȥ��$N����Ӱ��$n��������μ䣬ȴ��$NͻȻ��������ǰ��Ц�����ػ�ȭֱ��$n��С������", 600,80 , 90,"����",},
	};
  		
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zuoyou_boji", 1))
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
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("�����Ҳ���֮��������֡�");
    if ( me->query_skill("force", 1) < 30)
		return notify_fail("����ڹ��ķ���򲻹����޷������Ҳ���֮����");
    if ( me->query("max_mp") < 200)
		return notify_fail("�������̫�����޷������Ҳ���֮����");
    if( me->query_skill("zuoyou_boji",1)>1)
		return notify_fail("���Ҳ���֮���޷�ͨ���������ý�����");
	if( me->query("int") > 25 ) 
		return  notify_fail("������Բ��ʺ�ѧϰ˫�ֻ���֮��!") ;
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 40)
		return notify_fail("�������̫���ˡ�");
    if ( me->query("mp") < 30)
		return notify_fail("����������������Ҳ���֮����");
/*    if ( me->query_skill("zuoyou_boji",1) < 20)
		return notify_fail("����Ŀǰ�Ĺ����в����Լ���ϰ��");*/
    me->receive_damage("hp", 30);
    switch( random(3) ) 
	{
    case 0:
		me->add("combat_exp", -5);
		tell_object(me,   "��ֻ��������һ���ң�ͷһ���Σ���ľ��齵���ˣ�", "practice");
		break;
    case 1:
		me->add("sk_exp", - random( me->query_con() +  me->query_skill("zuoyou_boji",1) )/20);
		me->add("combat_exp", random( me->query_con() +  me->query_skill("zuoyou_boji",1) )/10);
		tell_object(me, "�㽫���ֺ����ִ�����ȥ����ϰ���Ҳ���֮������������ʵս���飬Ҳ��������Ǳ�ܻ������ߡ�", "practice");
		break;
    case 2:
		me->add("sk_exp", 3);
		tell_object(me,   "���������δ��Ǳ����ϰ������õ�Ǳ�ܼ����ˣ�", "practice");
		break;
	}
	return 1;
}

SKILL_END;
