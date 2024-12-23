//sword.h ��������

SKILL_BEGIN(CSSword);

virtual void create()
{
	set_name( "��������");
}

virtual CMapping * query_action(CChar * me)
{
	static struct {
		char action[80];
		int dodge, parry;
	}action[] = {
		{"$N������$w����ɷ����ָ��$n��", 15, -15,},
		{"$N����$w�û���һ�ư׹⣬ֱ��$n���ʺ��ȥ��", 15, -15,},
		{"$N��Ӱ���Σ�����ƮƮ�Ľ�$w�͵�$n��ǰ��", 15, -15,},
		{"$N�ȵ�����С���㲻����ˡ���˵������$w�Ѿ�ָ��$n��ǰ��", 20, -10,},
		{"$N����������һ��$w����������޷죬��$n����Ŀ�ɿڴ���", -30, -30,},
		{"$N΢΢һЦ������$w��֪���������͵�$n����ǰ��", -10, -10,},
		{"$N����һ�䣬գ�ۼ�ת��$n��ǰ��$wֱ��$n���ؿڡ�", -10, -10,},
		{"$N�߸߾�������$w����������$n��ͷ����ȥ��", 0, 20,},
	};

	int level = random(8);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	return & m_actions;
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

/*	if(who1 && me->query_skill("sword", 1)>=350)
		return notify_fail("�������Ŀǰ�Ĺ�������Ļ��������Ѿ��޷�����ָ���ˡ�");

	if(me->query_skill("sword", 1)>=350)
		return notify_fail("����Ŀǰ�Ĺ��������������Ѿ��޷���������ˡ�");
*/
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;



