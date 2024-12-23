//feifeng_whip.h  飞凤鞭法

SKILL_BEGIN(CSfeifeng_whip);

virtual void create()
{
	set_name( "飞凤鞭法");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("飞凤鞭法必须与大理独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char weapon[10],damage_type[5];
	}action[] = {
		{"$N向上跃起，一招「凤凰展翅」，手中$w自下而上，击向$n的脸颊", 100, 0,20 ,15 ,"凤凰展翅","刮伤",},
		{"$N一招「彩凤栖梧」，手中$w直绕向$n的$l", 110, -10, 30, 20,"彩凤栖梧","内伤",},
		{"$N一招「鸾凤和鸣」，手中$w腾空一卷，一声脆响入磬，猛地向$n劈头打下", 120, -15, 40, 40,"鸾凤和鸣","劈伤",},
		{"$N踏上一步，冲着$n轻佻一笑，手中$w却毫不停留，一招「游龙戏凤」，扫向$n的$l",130 , -30, 60, 50,"游龙戏凤","刺伤",},
		{"$N跃在半空，一招「龙飞凤舞」，手中$w如游龙洗空，长凤戏羽，乱雨倾盆般分点$n左右", 150, -35, 70, 60,"龙飞凤舞","刺伤",},
		{"$N向前急进，手中$w圈转如虹，一招「龙凤呈祥」，罩向$n前胸", 170, -40,85 , 75,"龙凤呈祥","内伤",},
	};
 
  
	int level = 0;
	for(int i=6; i>0; i--)
	{
		
		if(action[i - 1].lvl < me->query_skill("feifeng_whip", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="whip" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

 	if (me->query_skill("kurong_changong",1)< 20)
		return notify_fail("你的枯荣禅功火候太浅。");
	
 	if ( DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("大老爷们学这飞凤鞭？天资不足吧。");

	if ( !(weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("你必须先找一条长鞭才能练鞭法。");
 
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if ( !(weapon = me->query_weapon())	|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练飞凤鞭法。");

	me->receive_damage("hp", 10);
	return 1;
}

SKILL_END;

/*********
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }
********/