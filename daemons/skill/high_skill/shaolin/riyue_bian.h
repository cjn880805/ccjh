//riyue_bian.h 日月鞭法

SKILL_BEGIN(CSriyue_bian);

virtual void create()
{
	set_name( "日月鞭法");

	Magic_t * magic;

	magic = add_magic("chan", do_chan);
	magic->name = "缠绕诀";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge,  damage, lvl;
	}action[8] = {
		{"$N端坐不动，一招「裂石式」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
			-10,100, 0,},
		{"$N身形一转，一招「断川式」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
		-20,200, 60,},
		{"$N力贯鞭梢，一招「破云式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		-40,300,90,},
		{"$N力贯鞭梢，一招「分海式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		-50,400,100,},
		{"$N力贯鞭梢，一招「裂空式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		-60,500, 110,},
		{"$N力贯鞭梢，一招「佛光普照」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		-60,600,120,},
		{"$N力贯鞭梢，一招「金刚伏魔」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		-70,700,130,},
		{"$N力贯鞭梢，一招「佛法无边」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
		100,800,200,},
	};
 
  	int level = me->query_skill("riyue_bian", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if( me->query("max_mp") < 500 )
		return notify_fail("你的内力不足，没有办法练日月鞭法, 多练些内力再来吧。");

	if (me->query_skill("hunyuan_yiqi", 1) < 50)
		return notify_fail("你的混元一气功火候太浅。");

	if ( ! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("你还没达到无鞭胜有鞭的境界，还是老实的用鞭来练习吧。");

	return 1;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("日月鞭必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("你还没达到无鞭胜有鞭的境界，还是老实的用鞭来练习吧。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练日月鞭法。");

	me->receive_damage("hp", 5);
	return 1;
}

static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("你使用的武器不对。");
		
	if( me->query_skill("riyue_bian",1) < 50)
		return notify_fail("你的「日月鞭法」还没学到家，用不了「缠」字诀。");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧。", target->name());

	if(me->query("mp") < 50)
		return notify_fail("你的内力不够。");
	
	me->add("mp", -50);

	msg = "$N使出日月鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp()/2 ) 
	{
		msg += "结果$p被$P攻了个措手不及。";
		target->start_busy( me->query_skill("riyue_bian") / 20 + 2);
		me->start_busy(2);
	} 
	else 
	{
		msg += "可是$p看破了$P的企图，并没有上当。";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;

