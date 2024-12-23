// huashan_shenfa.h ��ɽ��
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_shenfa);

virtual void create()
{
	set_name( "��ɽ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge;
	}action[] = {
		{"$nһʽ���������᡹�������������������ݷ����У���$Nͷ����Ծ������", 10,},
		{"$nһʽ��������ϼ������һ����磬�滺��������$N���������ơ�", 20,},
		{"$nһʽ����س���������ӯ��һԾ��һת�ۼ���Ƶ���$N�����", 30,},
		{"$nһʽ��ȴ����ɡ���һת��䣬���Ʈ����һ��Զ", 40,},
		{"$nһʽ�����ճ�������ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���", 50,},
		{"$nһʽ�������ա���������һֻ�����������ˮ�ػ������ࡣ", 60,},
		{"$nһʽ���������ǡ���˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��", 70,},
		{"$nһʽ���������Ρ������ζ��ر��Ʈ����������$N�޷����塣", 80,},
		{"$nһʽ���������롹������һ����ʸ������Χ��$N���ٵ������˼�Ȧ��", 90,},
	};
 	int zhaoshu, level;
	zhaoshu = 9;
	level   =   me->query_skill("huashan_shenfa", 1);
	if (level < 80 )
		zhaoshu--;
	if (level < 60 )
		zhaoshu--;
	if (level < 40 )
		zhaoshu--;
	level =random(zhaoshu);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	return & m_actions;
};

virtual const char * query_dodge_msg(CChar * me)
{
	CMapping * m = query_action(me);
	return m->querystr("action");
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move");
}

virtual int valid_learn(CChar * me)
{
	return 1;

}

virtual int practice_skill(CChar * me)
{
	if(  me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������ɽ����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
