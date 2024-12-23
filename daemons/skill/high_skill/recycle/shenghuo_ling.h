
// shenghuo_ling.h 圣火令法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_ling);

virtual void create()
{
	set_name( "圣火令法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,damage;
		char damage_type[5];
	}action[] = {
		{"$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣住了$n小腿上的‘中都’‘筑宾’两穴，$n只觉下半身酸麻难动，大吃一惊", -10, 30,"挫伤",},
		{"突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，身形早变。右手同时抓住$n后领，一抖之下，将$n向外远远掷了出去", -20, 50,"挫伤",},
		{"$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，已然一拳打在$n腿上。$n一个踉跄，$N横过$w戳向$n后心", -30, 70,"刺伤",},
		{"$N忽地放手，手中那柄$w尾端向上弹起，拍的一响，正好打中$n手腕。", -20, 90,"刺伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -20, 110,"瘀伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口$N手中$w急挥横扫，突然连翻三个空心筋斗。$n不知对方是何用意，心想还是避之为妙，刚向左踏开一步，眼前白光急闪，$N的$w已到右肩", -20, 130,"挫伤",},
		{"$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中", -20, 150,"挫伤",},
	};
 		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("shenghuo_ling", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	int lvl =  me->query_skill("qiankun_danuoyi", 1);
	
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你先天不足，再学下去难免走火入魔。");
	
	if ( me->query("max_mp") < 50)
		return notify_fail("就这么点内力还想学圣火令法？");
	
	if ( me->query_skill("jiuyang_shengong", 1) < 20)
		return notify_fail("你的九阳神功火候还不够，学不了圣火令法！");
	
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练圣火令法。");
	me->receive_damage("hp", 40);
	return 1;
}

SKILL_END;
