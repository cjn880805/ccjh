// huoyan_dao.h 火焰刀
SKILL_BEGIN(CShuoyan_dao);

virtual void create()
{
	set_name( "火焰刀");

	Magic_t * magic;

	magic = add_magic("fen", do_fen);
	magic->name = "焚心以火";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*
	magic = add_magic("dian", do_dian);
	magic->name = "点蜡烛";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
  }

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("火焰刀必须与雪山内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, lvl, damage;
	}action[] = {
		{"$N使出一招「钻木取火」，飞身急转，双掌向前平平拍向$n", 150, 0, 60,},
		{"$N使出一招「祝融怀焰」，手掌如刀，斜斜劈向$的$l", 180, 10, 80,},
		{"$N使出一招「风火无边」，双掌一拍，一道内力自掌中攻向$n的$l", 200, 20, 100,},
		{"$N使出一招「六道轮回」，双手合十，当头劈向$n", 250, 30, 100,},
		{"$N使出一招「双龙吐焰」，双掌一错，两道内力交叉攻向$n的$l", 300, 40, 100,},

		{"$N使出一招「刀山火海」，双掌向下斜拍，顿时万千道内力从四面八方攻向$n", 350, 60, 100,},
		{"$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l", 400, 80, 100,},
		{"$N使出一招「火内莲花」，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n", 500, 100, 100,},
	};

	int level = me->query_skill("huoyan_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练火焰刀必须空手。");
	else if (me->query("max_mp") < 300)	//火焰刀要有很高的内力才能学
		return notify_fail("你的内力不够。");
	if (me->query_skill("longxiang", 1) >= 60 ||
	    me->query_skill("xiaowuxiang", 1) >= 60)
		return 1;
	else if (me->query_skill("longxiang", 1) < 60)
		return notify_fail("你的龙象般若功火候太浅。");
	else if (me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("你的小无相功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练火焰刀必须空手。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了火焰刀。");
	me->receive_damage("hp", 30);
	return 1;
}

//perform 
static int do_fen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||	! me->is_fighting(target) )
		return notify_fail("「焚心以火」只能对战斗中的对手使用。");

	if ( me->query_weapon() )
		return notify_fail("你必须空手运功。");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	int skill = me->query_skill("huoyan_dao",1);
	if( skill < 60)
		return notify_fail("你的「火焰刀」等级不够, 不能使出「焚心以火」！");
	if( me->query("mp") < 150 )
		return notify_fail("你的内力不够，无法运功！");

	msg = "$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n";
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("mp",-100);
		msg += "$n只觉得眼前一黑，“哇”的一声喷出一口鲜血！";
		
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		
		int qi_wound = neili_wound / 5;
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->add("hp",-qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg += "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！";
		if(userp(me))
			me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);

	return 1;
}

static int do_dian(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if ( me->query_weapon() )
		return notify_fail("你必须空手运功。");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	int skill = me->query_skill("huoyan_dao",1);
	if( skill < 60)
		return notify_fail("你的「火焰刀」等级不够, 不能使出「点蜡烛」！");
	if( me->query("mp") < 100 )
		return notify_fail("你的内力不够，无法运功！");

	msg = "$HIR$N聚气于掌，使出一招「点蜡烛」，向手里的蜡烛劈去！\n";
		

	msg += "$HIR众人只见一道火光闪过，$N手里的蜡烛被点燃了！！！";
		
		me->add("mp", -100);
		me->start_busy(random(3));

	message_vision(msg.c_str(), me, target);

	return 1;
}

SKILL_END;
