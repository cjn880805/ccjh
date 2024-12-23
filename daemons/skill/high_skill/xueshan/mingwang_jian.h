// mingwang_jian.c 明王剑 是明，笨！


SKILL_BEGIN(CSmingwang_jian);

virtual void create()
{
	set_name( "明王剑");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, lvl, damage;
	}action[] = {
		{"$N怒目圆睁，使出一招「明王」，手中$w一抖，直刺$n的$l ", 100, -10, 0, 30,},
		{"$N使出一式「起手出剑」，足下一滑，剑芒闪向$n的$l", 140, 5, 8, 30,},
		{"$N使出一招「山崩」，纵身跃入半空，$w如山崩般劈向$n的$l", 180, -10, 16, 40,},
		{"$N使出「千旋转」，将$w舞得如纺车一般，忽然一剑刺向$n的$l", 220, 10, 24, 48,},
		{"$N使出一招「降魔舞」，全身劲气贯于$w中，剑气直指$n的$l", 250, 10, 32, 54,},

		{"$N单足独立，使出一式「鹤舞」，一道剑光如白影般向$n的$l扫去", 280, 15, 40, 60,},
		{"$N使出一招「龙腾」，手中$w如游龙般扑向$n的$l", 300, 20, 48, 66,},
		{"$N飞身一跃，居高临下使出「花雨满天」，顿时剑尖如雨刺向$n的$l", 320, 25, 80, 80,},
	};
	
	int level = me->query_skill("mingwang_jian", 1);
	
	CContainer * weapon;
	weapon = me->query_weapon();
	char msg[255];
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			if (weapon->query("mingwang_jian") && me->query("mp")>20)
			{
				m_actions.set("force", action[level].force*2);
				me->add("mp",-20);
				snprintf(msg,255,"$HIW %s $COM",action[level].action);
				m_actions.set("action", msg);
			}
			else
			{
				m_actions.set("force", action[level].force);
			}
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("force", 1) <= 30 )
		return notify_fail("你的基本内功火候不够。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了明王剑。");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;




