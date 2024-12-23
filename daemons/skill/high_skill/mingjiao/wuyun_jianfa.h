
// wuyun_jianfa.h 五韵七弦剑
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSwuyun_jianfa);

virtual void create()
{
	set_name( "五韵七弦剑");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "wuzheng_xinfa") || EQUALSTR(arg, "xuantian_shengong"))
		return 1;

	return notify_fail("五韵七弦剑必须与玄天神功或无争心法配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N左小指轻弹，一招「宫韵」悄然划向$n的后心", 120, 20, 60,0 ,"刺伤",},
		{"$N右手无名指若有若无的一划，将琴弦并做一处，[商韵]已将$n笼罩", 140, 15, 70, 0,"刺伤",},
		{"$N五指疾挥，一式[角韵]无形的刺向$n的左肋", 170, 15, 80, 9,"刺伤",},
		{"$N将手中剑横扫，同时左右手如琵琶似的疾弹，正是一招[支韵]", 190, 10, 90, 19,"刺伤",},
		{"$N使出「羽韵」，将剑提至唇边，如同清音出箫，剑掌齐出，划向$n的$l",240 ,10 ,100 ,29 ,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuyun_jianfa", 1))
		{
			level = random(i);
			CContainer * weapon;
			weapon = me->query_weapon();
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			if (weapon->query("mindtwist"))
			{
				m_actions.set("action", action[level].action);
			//	m_actions.set("force", action[level].force * weapon->query("mindtwist")/1000);
				m_actions.set("dodge", action[level].dodge * weapon->query("mindtwist")/1000);
				m_actions.set("damage", action[level].damage * weapon->query("mindtwist")/1000);
			}
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
	if ( me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if ( me->query_skill("sword", 1) < 20)
		return notify_fail("你的剑术造诣不足。");
	if ( me->query_skill("wuzheng_xinfa", 1) < 30
		&& me->query_skill("xuantian_shengong") < 30)
		return notify_fail("你的玄天神功或无争心法火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练五韵七弦剑。");
	me->receive_damage("hp", 30);
	return 1;
	
}
/***********
return __DIR__"wuyun-jianfa/" + action;

  //perform 
  virtual int Cast(string magic, CChar * me, CContainer *  ob = NULL)
  {
  string msg;
  CChar * target= NULL;
  
	if (ob && ob->Query(IS_CHAR))
	target=(CChar *) ob;
	
	  if (magic=="fugu")
	  {
	  
		}
		}
*********************/
SKILL_END;
