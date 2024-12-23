//sword.h 基本剑术

SKILL_BEGIN(CSSword);

virtual void create()
{
	set_name( "基本剑术");
}

virtual CMapping * query_action(CChar * me)
{
	static struct {
		char action[80];
		int dodge, parry;
	}action[] = {
		{"$N挥舞着$w，神采飞扬的指向$n。", 15, -15,},
		{"$N手中$w幻化成一缕白光，直向$n的咽喉刺去。", 15, -15,},
		{"$N步影随形，轻轻飘飘的将$w送到$n胸前。", 15, -15,},
		{"$N喝道：“小子你不想活了。”说着手中$w已经指到$n面前。", 20, -10,},
		{"$N不紧不慢，一把$w挥舞得天衣无缝，把$n看得目瞪口呆。", -30, -30,},
		{"$N微微一笑，手中$w不知不觉间已送到$n的胸前。", -10, -10,},
		{"$N身形一变，眨眼间转到$n面前，$w直戳$n的胸口。", -10, -10,},
		{"$N高高举起手中$w，奋力的向$n的头顶劈去！", 0, 20,},
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
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

/*	if(who1 && me->query_skill("sword", 1)>=350)
		return notify_fail("以你伴侣目前的功力，你的基本剑术已经无法继续指点了。");

	if(me->query_skill("sword", 1)>=350)
		return notify_fail("以你目前的功力，基本剑术已经无法继续请教了。");
*/
	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;



