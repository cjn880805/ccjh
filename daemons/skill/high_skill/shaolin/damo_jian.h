SKILL_BEGIN(CSdamo_jian);

virtual void create()
{
	set_name( "达摩剑");
	
	Magic_t * magic;

	magic = add_magic("sanjue", do_sanjue);
	magic->name = "达摩三绝剑";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("达摩三绝剑必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N使一式「万事随缘往」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
			120, -10, 15, 0,},
		{"$N错步上前，使出「来去若梦行」，剑意若有若无，$w淡淡地向$n的$l挥去",
		140, -10, 20, 9,},
		{"$N一式「浮世沧桑远」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
		160, 5, 20, 18,},
		{"$N纵身轻轻跃起，一式「轮回法舟轻」，剑光如轮疾转，霍霍斩向$n的$l",
		180, 10, 35, 27,},
		{"$N手中$w中宫直进，一式「水月通禅寂」，无声无息地对准$n的$l刺出一剑",
		220, 15, 40, 36,},
		{"$N手中$w斜指苍天，剑芒吞吐，一式「鱼龙听梵音」，对准$n的$l斜斜击出",
		260, 5, 45, 44,},
		{"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「千里一苇去」刺向$n的$l",
		320, 5, 55, 52,},
		{"$N合掌跌坐，一式「禅心顿自明」，$w自怀中跃出，如疾电般射向$n的胸口",
		380, 5, 60, 60,},
	};

	int level = me->query_skill("damo_jian", 1);
	for(int i = 8; i > 0; i--)
	{
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
				if(! me->query_temp("pfm_damijian"))
				{
					m_actions.set("force", action[level].force);
					m_actions.set("damage", action[level].damage);
				}
				else
				{
					m_actions.set("force", action[level].force*3/2);
					m_actions.set("damage", action[level].damage*2);
				}
				m_actions.set("dodge", action[level].dodge);
			}
			break;
		}
	}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练达摩剑。");

	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "sword" || usage == "parry";}
virtual int valid_combine(string combo) {return combo=="xiuluo_dao";}

static int do_sanjue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
    
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(!target || !me->is_fighting(target) )
	    return notify_fail("「达摩三绝剑」只能在战斗中使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
			return notify_fail("虽然你很想用达摩三绝剑，可是你也得拿一把剑才能用啊？");

	if(me->query_dex() < 30)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技! ");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("你的混元一气功的修为不够, 不能使用这一绝技 !");

	if(me->query_skill("dodge") < 135)
		return notify_fail("你的轻功修为不够, 不能使用达摩三绝剑！");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
 
	if(me->query_skill("sword") < 135)
		return notify_fail("你的剑法修为不够， 目前不能使用达摩三绝剑! ");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "damo_jian"))
		return notify_fail("必须配合达摩剑法使用。");

    if(me->query("mp") < 500 )
		return notify_fail("你的真气不够！");

    message_vision("$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！", me);

	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
	
	me->add("mp", -150);
	me->start_busy(random(2));

    return 1;
}

SKILL_END;