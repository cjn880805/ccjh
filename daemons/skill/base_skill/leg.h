//leg.h �����ȷ�
//lanwood 2001-03-12


SKILL_BEGIN(CSleg);

virtual void create()
{
	set_name( "�����ȷ�");
}

CMapping * query_action(CChar * me)
{
	static CMapping m;
	
	m.set("action", "$N��$nһ�Ž�һ�ŵ����˹�ȥ��");
	m.set("dodge", -10);
	m.set("damage", 1);
	
	return & m;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp