//hanxing_bada.h 寒星八打
//lanwood 2001-01-04

SKILL_BEGIN(CShanxing_bada);

virtual void create()
{
	set_name( "寒星八打");

	Magic_t * magic;

	magic = add_magic("lastrisk", do_lastrisk);
	magic->name = "孤注一掷";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage, lvl;
	}action[8] = {
		{"$N使一招「陨星乍现」，手中$w疾射$n的$l",
			120, -20,90, 0,},
		{"$N使出「玉隼击空」，双手下沉$w陡的向上飞出直袭$n的$l",
		125,  -20, 50, 10,},
		{"$N一招「暮霭沉沉」，长袖一挥，手中$w从腋下激射$n的$l",
		135, -30,40, 20,},
		{"$N手中$w一式「长电裂空」，$w幻作一道白光直奔$n的$l",
		140, -40,60, 30,},
		{"$N纵身一跃，手中$w一招「苍龙入海」射向$n的$l",
		150, -40, 70, 40,},
		{"$N手扣$w,凭空一指，一招「巴山夜雨」洒向$n的$l",
		160, 20,50, 50,},
		{"$N身形一晃，使一招「彗星横空」$w脱手而出，袭向$n的$l",
		220, -20,60,60,},
		{"$N身形一转手中$w使一招「后弈射日」画出一道光弧袭向$n的$l",
		270, -30,60, 100,},
	};
 
  	int level = me->query_skill("hanxing_bada", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

    if( me->query("max_mp") < 100 )
          return notify_fail("你的内力不够，没有办法练寒星八打。");
    if( !(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
          return notify_fail("你必须先找一些飞镖之类的东西才能练暗器。");
    return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30 || me->query("mp") < 3 )
        return notify_fail("你的内力或气不够，没有办法练习寒星八打。");
    me->receive_damage("hp", 30);
    me->add("mp", -3);
    return 1;
}

static int do_lastrisk(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;
	int skill;

	if( !target || !me->is_fighting(target) )
		return notify_fail("孤注一掷只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("你必须先有暗器。");
		
	skill = me->query_skill("hanxing_bada", 1);
	
	if(skill < 60 )
		return notify_fail("你的寒星八打修为太浅。");
	
	if( me->query("mp") < 100 )
		return notify_fail("你现在内力太弱，不能使用「孤注一掷」。");

	me->add("mp", -50);
			
	msg = "$N孤注一掷，发出所有暗器攻向$n!\n";

    me->start_busy(2);
    if( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
    {
        msg += "结果$p被$P攻了个措手不及！";
        target->receive_wound("hp", random(skill) * 2);
    } 
	else 
        msg += "可是$p躲过了$P的最后一击。";
        
    message_vision(msg.c_str(), me, target);

	//用光所有武器
    weapon->move(me->environment());
        
    return 1;
}

SKILL_END;

