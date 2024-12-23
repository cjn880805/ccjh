//leg.h 基本腿法
//lanwood 2001-03-12


SKILL_BEGIN(CSleg);

virtual void create()
{
	set_name( "基本腿法");
}

CMapping * query_action(CChar * me)
{
	static CMapping m;
	
	m.set("action", "$N向$n一脚接一脚的踢了过去。");
	m.set("dodge", -10);
	m.set("damage", 1);
	
	return & m;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp