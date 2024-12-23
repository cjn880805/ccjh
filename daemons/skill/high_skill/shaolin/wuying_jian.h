SKILL_BEGIN(CSwuying_jian);

virtual void create()
{
	set_name( "无影剑");

	Magic_t * magic;

	magic = add_magic("wuying", do_wuying);
	magic->name = "分身无影";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("无影剑必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[9] = {
		{"$N握紧手中$w一招「来去自如」点向$n的$l",
			50, 80, 20, 0,},
		{ "$N一招「日月无光」，无数$w上下刺出，直向$n逼去",
        70, 20, 30, 20,},
		{ "$N向前跨上一步，手中$w使出「剑气封喉」直刺$n的喉部",
		90, 80, 50, 40,},
		{"$N虚恍一步，使出「心境如水」手中$w直刺$n的要害",
		90, 60, 80, 60,},
		{ "只见$N抡起手中的$w，使出「佛光普照」万点金光直射$n",
        90, 50, 110, 80,},
		{"$N抡起手中的$w，使出「风行叶落」无数剑光直射$n",
        120, 100, 120, 100,},
		{ "$N使出「声东击西」，手中$w如刮起狂风一般闪烁不定，刺向$n",
        200, 120, 140, 120,},
		{ "$N随手使出剑法之奥义「无影无踪」，手中$w如鬼魅一般铺天盖地的刺向$n",
		300, 150, 250, 150,},
		{"$HIY$N使出无影剑法之最终绝技$HIC「蛟龙出水」$HIY手中$w犹如蛟龙一般刺向$n.$COM",
		400, 250, 700, 220,},
	};

	int level = me->query_skill("wuying_jian", 1);
	for(int i = 9; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);		
			
			if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
			{
				m_actions.set("action", "$N握紧手中$w，胡乱挥舞着点向$n的$l");
				m_actions.set("dodge", 1);
				m_actions.set("damage", 1);
				m_actions.set("force", 1);
			}
			else
			{
				m_actions.set("action", action[level].action);
				if(! me->query_temp("pfm_wuying"))
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage);
				}
				else
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage*3/2);
				}
				m_actions.set("dodge", action[level].dodge);
			}
			
			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("你必须向无名老僧请教!");

	 CContainer * weapon;

     if (! (weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
            return notify_fail("你使用的武器不对。");
     if (me->query("hp") < 50)
            return notify_fail("你的体力不够练「无影剑法」。");
     if ((int)me->query("mp") < 50)
            return notify_fail("你的内力不够练「无影剑法」。");
     me->receive_damage("hp", 40);
     me->add("mp",-15);
     return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("hunyuan_yiqi", 1) < 150)
           return notify_fail("你的「混元一气」火候不够，无法学「无影剑法」。");
    if (me->query("max_mp") < 300)
           return notify_fail("你的内力太弱，无法练「无影剑法」。");
    return 1;
}

virtual int valid_enable(string usage) {return (usage == "sword") || (usage == "parry");}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage <= 100 ) return 0;

    if( random(damage/3) > victim->query_str() ) 
	{
//                victim->add("hp", 1 - damage_bonus - 100 * 3 );
		victim->receive_wound("hp", (damage - 100) / 2);
		return "$HIR你听到「哧」一声轻响一道霸气扑天而来，忽然间$n血冒三丈，被$N剑气所伤！$COM";		
    }

	return 0;
}

static int do_wuying(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (DIFFERSTR(me->querystr("family/family_name"), "少林派"))
		return notify_fail("你怎么也想不出来怎么做");

    if( !target ||! me->is_fighting(target) )
          return notify_fail("「分身无影」只能在战斗中使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
          return notify_fail("「分身无影」必须用剑才能施展。");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "wuying_jian"))
		return notify_fail("必须配合无影剑使用。");

    if( me->query_skill("wuying_jian", 1) < 150 )
          return notify_fail("你的「少林无影剑」不够娴熟，不会使用「分身无影」。");

    if( me->query("mp") < 300  ) 
          return notify_fail("你的内力不够。");

    //int skill = me->query_skill("wuying_jian");
    message_vision("$HIG$N身行突变，瞬间犹如分出无数身影闪电般的向$n攻去！$COM", me, target);
    me->add("mp", -200);

    //me->clean_up_enemy();
    //ob = me->select_opponent();
	me->set_temp("pfm_wuying", 1);

    message_vision("\n$HIR来字决！", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
    
	message_vision("\n$HIY去字决！", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIG若字决！", me, target);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIB无字决！", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
        
	message_vision("\n$HIW形字决！", me, target);
    g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);

	me->delete_temp("pfm_wuying");

    if( me->is_fighting() ) me->start_busy(5);

	return 1;
}

SKILL_END;