// riyue_lun.c 日月轮法
SKILL_BEGIN(CSriyue_lun);

virtual void create()
{
	set_name( "日月轮法");

	Magic_t * magic;
	magic = add_magic("feilun", do_feilun);
	magic->name = "飞轮术";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("日月轮法必须与雪山内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, lvl, damage;
	}action[] = {
		{"$N使一招「破竹势」，抡起手中的$w向$n的$l砸去", 220, -10, 10, 0, 90,},
		{"$N使一招「隐山谷势」，双肩一沉，舞动手中$w向$n的$l横扫", 260, -20, 20, 8, 95,},
		{"$N使一招「隐微势」，就地一滚，手中自下而上撩向$n的$l", 300, -20, 10, 16, 90,},
		{"$N使一招「擒纵势」，身形起伏之际$w扫向$n的$l", 340, 5, 15, 24, 95,},
		{"$N使一招「圆满势」，$w如离弦之箭般直捣$n的$l", 380, -10, 10, 32, 90,},

		{"$N跃入半空，使一招「月重辉势」，高举$w敲向$n的$l", 320, 10, 10, 40, 95,},
		{"$N使一招「捉月势」，斜举手中$w击向$n的$l", 360, -15, 15, 48, 90,},
		{"$N提一口真气，使出「显吉祥」，$w扫向$n的头部", 440, -20, 15, 56, 100,},
	};
	
	int level = me->query_skill("riyue_lun", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
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

virtual int valid_enable(string usage) { return usage=="hammer" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练不了日月轮法。。");
	me->receive_damage("hp", 30);
	return 1;
}

static int do_feilun(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
    CContainer * weapon;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if( !target || ! me->is_fighting(target) )
        return notify_fail("我佛慈悲，只在战斗中才出招伤人。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "hammer"))
		return notify_fail("你想用什么武器来使飞轮术？那样是不可以的！");	

    if( me->query_skill("riyue_lun", 1) < 100 )
        return notify_fail("你的日月轮法不够娴熟，不会使用飞轮术。");

	if(DIFFERSTR(me->querystr("family/family_name"), "雪山寺") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( me->query("mp") < 100 )
        return notify_fail("你内力不够，不能使出飞轮术。");
	
    int skill = me->query_skill("riyue_lun", 1);
	
    me->add("mp", -50);
    target->receive_damage("hp", skill/ 3);
	
    msg = "只见$N手中的";
	msg += weapon->name();
	msg += "如流星般向$n飞旋过去！";
	
    me->start_busy(1);
	if( random( me->query_skill("riyue_lun", 1))
		> random(target->query_skill("dodge") + 1) ) 
	{
		msg = "$HIR结果$p被$P的绝招打中了要害部位，痛得大声惨呼。\n";
		target->receive_wound("hp", random(skill) * 8);

	} 
	else 
	{
		msg += "可是$p躲过了$P的必杀一击。\n";
	}

	if(userp(me))
		weapon->move(me->environment());
	else
	{
		msg += weapon->name();
		msg += "旋转半圈后又飞回$N手中！";
	}
	message_vision(msg.c_str(), me, target);
		
	//use out all throwing
	
	return 1;
}

SKILL_END;
