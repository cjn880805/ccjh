//shengji_blade.h 神机刀法

SKILL_BEGIN(CSshengji_blade);

virtual void create()
{
	set_name( "神机刀法");

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge,  parry;
		char damage_type[5];
	}action[] = {
		{"$N脸上浮现出一丝诡异的笑容，突然使出一招「笑里藏刀」，手中$w直劈$n的$l！",70,-10,200,"割伤"},
		{"$N使出一招「趁火打劫」掌中$w泛出闪闪刀光，映得$n眼花缭乱，趁机平削$n的$l！",140,-10,100,"割伤"},
		{"$N单掌虚晃，$w反手一招「声东击西」狠狠砍向$n的$l。",160,-10,100,"割伤"},
		{"$N身形一矮，一招「釜底抽薪」，$w往$n的$l斜斜撩出一刀。",180,-10,10,"割伤"},
		{"$N手中$w幻出满天刀光，一招「混水摸鱼」，身行如飞，无声无息地转到$n的背后，猛剁$n的$l。",210,-10,100,"割伤"},
		{"$N的$w走弧形，一招「关门打狗」，封住$n的退路，刀尖直刺$n的$l。",230,-10,100,"刺伤"},
		{"$N一招「擒贼擒王」，$w挂风，自上而下，电闪般砍向$n的$l。",200,-40,100,"割伤"},
		{"$N一招「打草惊蛇」，$w发疯般狂砍，攻得$n心惊胆战！",300,-200,100,"割伤"},
		{"$N使出一招「顺手牵羊」，$w布满内力，将$n向旁一带，斜刺里顺手一刀。",220,-10,100,"割伤"},
		{"$N身行一长，手中$w大开大合，一招「远交近攻」，方圆丈许布满刀风，将$n团团围住。",200,-10,80,"割伤"},
		{"$N手中$w一招「假途灭虢」，刀人合一，冲杀过去，突然回手一刀，劈向$n的$l。",120,-200,-100,"割伤"},
		{"$N一招「借刀杀人」，欺身而进，一刀攻向$n的$l。",120,-200,-100,"割伤"},
	};
 
  	int level = random(12);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
};

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$n使出一招「偷梁换柱」，手中$W虚点一招，突然回招换式，护住$n的全身。"},
		{"$n手中$W虚刺，半途突然翻转，一招「指桑骂槐」，护住全身要害。"},
		{"$n一招「借尸还魂」，身影闪过，又飘回原地，手中$W＂铛＂的一声磕开了$N的$w。"},
		{"$n一招「调虎离山」，身形虚晃，将$N的招式引开，$W却直袭$N之必救。"},
		{"$n一招「反客为主」，用手中的$W荡开了$N的招式。"},
		{"$n故意丢个破绽，一招「抛砖引玉」，手中$W反挥向$N之必救。"},
		{"$n手中$W舞得风雨不透，一招「瞒天过海」，逼得$N回手撤招。"},
		{"$n一招「围魏救赵」，全然不顾$N的攻击，$W直向$N砍去，逼得$N回招自保。"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(4)+4];
}

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

SKILL_END;


