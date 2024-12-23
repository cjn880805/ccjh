
// taixuan_gong.h 侠客岛太玄功
//code by Fisho
//date : 2000-12-08

//inherit SKILL;
//inherit FORCE;

SKILL_BEGIN(CStaixuan_gong);

virtual void create()
{
	set_name( "侠客岛太玄功");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$n左手拍出，劲风到处，把$N震到一边。"},
		{"$n手臂回转，抓住$N手肘一推，将$N远远掷开。"},
		{"$n两腿轻蹬，激跃而出，竟已落在十数丈外。"},
		{"$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。"},
	};
	
	return dodge_msg[random(4)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage;
		char damage_type[5];
	}action[] = {
		{"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退", 200, 20, 240, "瘀伤",},
		{"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去", 220, 20, 250, "瘀伤",},
		{"$N大喝一声，张口一股内气向$n脸上喷去", 400, 30, 250, "瘀伤",},
		{"$N猱身而上，双掌猛地拍向$n", 225, 30, 270, "瘀伤",},
		{"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门", 230, 40, 300, "瘀伤",},
		{"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出", 230, 40, 300, "瘀伤",},
	};
	
	int level = 0;
	
	level = random(6);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}

virtual int valid_learn(CChar * me)
{
	if (random(me->query("int")) > 11)		//原来是kar的 lanwood 2001-02-17
		return 1;
	return notify_fail("你对着石壁冥思苦想了一会，对满目蝌蚪文一点不懂。");
	
}

SKILL_END;
