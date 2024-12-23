//xuanyuan_arrow.h 轩辕箭
SKILL_BEGIN(CSxuanyuan_arrow);

virtual void create()
{
	set_name( "轩辕箭");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("轩辕箭必须与独特内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, parry;
	}action[7] = {
		{"$N忽然纵声长啸，横跃于空，取箭上弦。\n只听弓弦响处，$w已到$n左肩，眼看就要对穿而过！\n这招「李广射石」果然有穿石之力",
		25, -20, 10,},
		{"$N弓交背后，俯身一招「廉颇负荆」，$w已带呼啸声向$n前胸飞去",
		35,  20, 20,},
		{"突然间，$N几个筋斗倒翻而去，已在$n数丈之外。\n$n正待追击，$N忽然转身，好一个「百步穿杨」，\n$w已带着破空之声，直射$n面门",
		20, -10, -10,},
		{"$N力开长弓，瞄准$n的左臂虚晃一箭。\n$n纵起闪避，突然发现并无羽箭射来。正在无处可去时，\n$N弯弓搭箭，只见一支$w向$n的$l疾飞而至",
		25, -20, 10,},
		{"$N手指微动，$n只听到「嗖」地一声，$w已到$l前数寸。\n$n没放到这招「后翌落日」来势如此之快，不禁手足无措",
		35, 10, -10,},
		{"$N马步站稳，劲力透背，拉的弓如满月，$w飞一般冲向$n的$l",
		40, 20, 20,},
		{"$n纵身而起，正待凌空一击。$N作势似要逃跑，突然扭腰回身，\n一招「犀牛望月」，手中$w如同长眼一般，直刺向$n的$l",
		30, -10, -10,},
	};
 
	int max = me->query_skill("throwing", 1) / 15;
	if ( max > 7) max = 7;

	int level = random(max);

  	m_actions.set("action", action[level].action);
	m_actions.set("damage", action[level].damage);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;
  
	if(me->query_skill("throwing",1) < 20)
		return notify_fail("如果弓箭不熟，怎能在激战中上箭开弓射敌？");
	if( me->query("max_mp") < 50 )
		return notify_fail("你的内力不够，拉不开弓！");
	if( !( weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("手中无弓箭怎能领悟师父所教？");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if( ! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("没有弓箭如何练准头？");

	if( me->query("hp") < 40 || me->query("mp") < 10)
		return notify_fail("你的体力不足，拉不开弓！");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	
	message_vision("$N弯弓搭箭，一箭射中红心！", me);
	g_Combatd.throw_weapon(me, NULL, weapon, 0);

	return 1;
}


SKILL_END;

