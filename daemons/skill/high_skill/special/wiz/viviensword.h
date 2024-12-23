// vivien-sword.c 薇安剑法 
// Create by rouma@FYtdwy(sh)
// Last Modify @ 2001-03-14
// by Teapot <发烧中>

SKILL_BEGIN(CSviviensword);

virtual void create()
{
	set_name( "薇安剑法");

	Magic_t * magic;

	magic = add_magic("freeze", do_freeze);
	magic->name = "相思无用";
	magic->mp = 700;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge, damage,lvl;
	}action[] = {
	{"$N使一招「爱的真谛」，手中$w如一条银蛇般刺向$n！",0, 0, 0,},
		{"$N使出薇安剑法中的「爱的力量」，剑光霍霍斩向$n！",0, 0, 0, },
		{"$N一招「刀光倩影」,手中$w化剑为刀砍向$n！", 0, 0, 0, },
		{"$N手中$w中宫直进，一式「情意绵绵」对准$n刺出一剑！", 0, 0, 0,},
		{"$N纵身一跃，手中$w一招「爱在心头」对$n斜刺一剑", 0, 0, 0, },
		{"$N的$w凭空一指，一招「爱来爱去」刺向$n！", 0, 0, 0, },
		{"$N手中$w向外一分，使一招「纯爱之剑」反手对准$n一剑刺去！", 0, 0, 0, },
		{"$N横剑上前，身形一转手中$w使一招「爱神之心」画出一道光弧刺向$n！", 0, 0, 0, },
		{"$N使出薇安剑法中的最高境界［相思无用］，脑中突然想起了倩影，手中的$w化作长虹闪电般的击向$n！", 0, 0, 0, },
		{"倩影一现，消失．．．．\n$w剑光消失，$N突然手中又一亮！\n$MAG相思无用第一式：江山一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$HIM相思无用第二式：海天一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$RED相思无用第三式：君子一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$HIC相思无用第四式：淑女一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$HIB相思无用第五式：秋水一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$HIR相思无用第六式：相思一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$HIY相思无用第七式：无用一剑！", 0,0,0,},
		{"$w剑光消失，$N突然手中又一亮！\n$BLU相思无用最后一式：倩影一剑！$GRN", 0,0,0,},
	
	};
	int level = me->query_skill("vivnensword");

	CContainer * weapon;
	weapon = me->query_weapon();

	level = random(8);
		if (me->query_temp("teapot/vivien"))
		{
			m_actions.set("action", action[(me->query_temp("teapot/vivien")+7)].action);
		}
		else
		{
			m_actions.set("action", action[level].action);
		}

		m_actions.set("dodge", action[level].dodge);
		m_actions.set("damage", action[level].damage);


	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="sword" ; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") > 2000)
		return notify_fail("你的内力太多。");

	if (me->query("age") > 30)
		return notify_fail("你年龄太老，无法体会相思情意。");

	if (me->query("age") <16)
		return notify_fail("你年龄太小，无法体会相思情意。");

	if (me->query("pks") >0 )
		return notify_fail("你杀心太重，无法体会相思情意。");

	if (me->query("pds") >0 || me->query("mds")>5 )
		return notify_fail("你阅历太深，无法体会相思情意。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("痛饮长吟剑如梦，西风秋月醉花魂。");
}


static int do_freeze(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon = me->query_weapon();

	if(ob && ob->is_character())
		target = (CChar *)ob;


	int skilla;
	skilla=me->query_skill("viviensword",1);

	if( skilla < 240 )
		return notify_fail("你的薇安剑法极不够娴熟，使不出莲出淤泥的相思无用。");

	if( skilla > 299 )
		return notify_fail("你的薇安剑法太过霸烈，已经无法使出莲出淤泥的相思无用。");

	if( me->query("mp") < 700)	
		return notify_fail("你的内力不足，使不出莲出淤泥的相思无用。");

	if( !target || !me->is_fighting(target) )
		return notify_fail("「相思无用」只能对战斗中的对手使用。");

	if (! weapon || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if (userp(me))
	{
		me->add("mp",-700);
		me->set("mp_factor",0l);
	}

	for(int n = 0; n < 9; n++)
	{
		me->set_temp("teapot/vivien",n);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	}

	me->start_busy(3);

	me->set_temp("teapot/vivien",9);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->delete_temp("teapot/vivien");
	return 1;
}


const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[6][255] ={
		"$n使出一招「春爱」，手中的$W化作一条长虹，磕开了$N。",
		"$n使出「夏爱」，$W如风而去，将$N封于丈外。",
		"$n使出一招「冬爱」，手中的$W化做漫天雪影，荡开了$N的$w。",
		"$n手中的$W一抖，一招「秋爱」，但见枫红片片，$N已被迫开。",
	};

	if(! weapon) return 0;
	return parry_msg[random(4)];
}


SKILL_END;





