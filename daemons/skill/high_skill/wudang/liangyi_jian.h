//liangyi-jian.c 两仪剑法

SKILL_BEGIN(CSliangyi_jian);

virtual void create()
{
	set_name( "两仪剑法");
	set("valid_force", "taiji_shengong");

	
	Magic_t * magic;

	magic = add_magic("ren", do_ren);
	magic->name = "天地同仁";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge, damage, lvl;
	}action[] = {
		{"$N剑尖剑芒暴长，一招「法分玄素」，手中$w自左下大开大阖，一剑斜上刺向$n的$l",
			20, 180, 0, },
		{"$N剑势圈转，手中$w如粘带连，平平展展挥出，一招「道尽阴阳」轻轻划过$n的$l", 
			20, 190, 10, },
		{"$N长剑轻灵跳动，剑随身长，右手$w使出一式「渊临深浅」刺向$n的$l", 
			15, 200, 20, },
		{"$N长剑下指，剑意流转，一招「水泛青黄」直取$n的$l", 
			15, 230, 30, },
		{"$N剑芒吞吐，幻若灵蛇，右手$w使出一式「云含吞吐」，剑势极尽曼妙，刺向$n的$l", 
			25, 250, 40, },
		{"$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式「梦醒蝶庄」跃跃洒洒飘向$n的$l", 
			25, 260, 50, },
		{"$N挥剑分击，剑势自胸前跃出，右手$w一式「人在遐迩」，毫无留恋之势，刺向$n的$", 
			15, 270, 60, },
		{"$N退步，左手剑指划转，腰部一扭，右手$w一记「情系短长」自下而上刺向$n的$l", 
			35, 280, 80, },
	};

	int level = me->query_skill("liangyi_jian", 1);

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage=="sword" ||  usage=="parry"; 
}

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	if (me->query("max_mp") < 200)
		return notify_fail("你的内力不够。");
	if (me->query_skill("taiji_shengong", 1) < 50)
		return notify_fail("你的太极神功火候太浅。");
	if (me->query_skill("sword", 1) < me->query_skill("liangyi_jian", 1) )
		return notify_fail("你的基本剑法火候太浅。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练两仪剑法。");
	me->receive_damage("hp", 10);
	return 1;
}

//perform 
static int do_ren(CChar * me, CContainer * ob)
{
	string msg;
	CChar * target = NULL;
	CContainer * weapon;
	int damage;

	if(ob && ob->is_character())
		target = (CChar * )ob;

	if( !target || ! me->is_fighting(target) )
		return notify_fail("「天地同仁」只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("开什么玩笑，没装备剑就想使「天地同仁」？");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if (me->query_skill("liangyi_jian", 1) < 60 )
		return notify_fail("你两仪剑法不够娴熟，使不出「天地同仁」。");
	
	if (me->query_skill("taiji_shengong", 1) < 90 )
		return notify_fail("你太极神功火候不够，使不出「天地同仁」。");
	
	if (me->query("max_mp")<400)
		return notify_fail("你内力修为不足，无法运足内力。");
	
	if (me->query("mp")<200)
		return notify_fail("你现在内力不够，没能将「天地同仁」使完！");

    msg = "$N手中长剑剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n，$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！\n";

    if (random(me->query_skill("force")) > target->query_skill("force")/2 || 
		random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = me->query_skill("liangyi_jian", 1) + me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/3);
		msg += "$n疾忙左转，却发现$N的剑根本没有右偏，一式「天地同仁」在$n左胸留下一个血洞！$n一低头，看到胸口鲜血涌泉喷出！";
        me->add("mp", -damage/5);
    }
	else
    {
        me->start_busy(2);
		msg += "可是$n轻轻一笑，侧身右转，果然$N的剑式突然左展，在$n身前划过，仅差半寸。一根毫毛都没伤到。";
    }
	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
