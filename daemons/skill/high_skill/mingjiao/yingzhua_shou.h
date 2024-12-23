
// yingzhua_shou.h 鹰爪手（殷天正）
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSyingzhua_shou);

virtual void create()
{
	set_name( "鹰爪手");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("鹰爪手必须与独特内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N腾空而起，半空一个筋斗，一式「金雕擒兔」，迅猛地抓向$n的$l", 100, 10,10 ,0 ,0 ,"内伤",},
		{"$N单腿弯曲站立，双臂向后舒展，一式「雄鹰展翅」，双爪一前一后拢向$n的$l", 120,15 , 15, 5,10 ,"内伤",},
		{"$N一式「拔翅横飞」，全身向斜下里跃去，右腿一绷，双爪扣向$n的肩头", 150, 10, 10, 10, 20,"内伤",},
		{"$N双爪交错上举，使一式「迎风振翅」，一拔身，分别袭向$n左右腋空门", 190, 15, 15, 15,30 ,"内伤",},
		{"$N全身滚动上前，一式「雄鹰现爪」，右手向羽翼般在$n眼前一拂，突然左手鬼魅般抓向$n的胸口", 250, 20, 20, 15, 40,"内伤",},
		{"$N伏地滑行，一式「拨云瞻日」，上手袭向膻中大穴，下手反抓$n的裆部", 310,25 , 25,20 , 50,"内伤",},
		{"$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n", 380, 25, 25,25 ,55 ,"内伤",},
		{"$N腾空高飞三丈，一式「鹰翔万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",470 , 40, 40, 30, 60,"内伤",},
	};
 		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yingzhua_shou", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") ;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练鹰手必须空手。");
	if ( me->query_skill("hand",1) < 20)
		return notify_fail("你的基本手法太差劲了，无法学鹰爪手。");
	if ( me->query_skill("shenghuo_shengong", 1) < 40)
		return notify_fail("你的圣火神功还不到家，无法学鹰爪手。");
	if ( me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练鹰爪手。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练鹰爪手。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;

}

SKILL_END;
