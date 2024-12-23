SKILL_BEGIN(CSnianhua_zhi);

virtual void create()
{
	set_name( "拈花指");

	Magic_t * magic;

	magic = add_magic("foxue", do_foxue);
	magic->name = "拈花拂穴";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("拈花指必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[10] = {
		{"$N侧身抬臂，右指划了个半圈，一式「瓶花落砚」击向$n的$l",
			60, -5, 10, 0},
		{"$N左掌虚托，一式「寒梅吐蕊」，右指穿腋疾出，指向$n的胸前",
		70, -5, 15, 0},
		{"$N俯身斜倚，左手半推，右手一式「初杏问酒」，向$n的$l划过",
		90, 5, 30, 0},
		{ "$N双目微睁，一式「露草斜阳」，双手幻化出千百个指影，拂向$n的$l",
		120, 5, 40, 9,},
		{"$N一式「仰月承霖」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
		160, 15, 80, 18,},
		{ "$N双掌平托胸前，十指叉开，一式「叶底留莲」，指向$n的周身大穴",
		210, 20, 120, 27,},
		{ "$N双掌翻飞，一式「清风拂桂」，指端迸出无数道劲气，射向$n的全身",
		270, 25, 160, 36,},
		{ "$N一式「菊圃秋霜」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
		340, 30, 200, 45,},
		{ "$N一式「伽叶微笑」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
		420, 35, 240, 55,},
		{ "$N左掌竖立胸前，一式「佛祖拈花」，右手食指扣住拇指，轻轻对着$n一弹",
		510, 50, 450, 62,},
	};

	int level = me->query_skill("nianhua_zhi", 1);
	for(int i = 10; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ((int)me->query("mp") < 20)
		return notify_fail("你的内力不够练拈花指。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练拈花指必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学拈花指。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练拈花指。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry";  }
virtual int valid_combine(string combo) {return combo=="sanhua_zhang";  }

static int do_foxue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))		//add by lanwood 2000-12-26
		return notify_fail("只能对战斗中的敌人使用！");

	if(me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!");

	if(me->query_skill("hunyuan_yiqi",1) < 100)
		return notify_fail("你混元一气功的功力不够不能使用拈花拂穴!");

	if(DIFFERSTR(me->querystr("family/family_name"), "少林派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (me->query_weapon())
			return notify_fail("你不能使用武器！");

	if(me->query_skill("finger") < 120)
		return notify_fail("你的指法修为不够,目前还不能使用拈花拂穴绝技!");

	if(me->query("mp") < 300)
		return notify_fail("你内力现在不够, 不能使用拈花拂穴! ");

	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());

	msg = "$HIY$N使出拈花指绝技「拈花拂穴」，罩住了$n的全身要穴, 使$n动弹不得。\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp() / 3 )
	{
		msg +=  "$HIG结果$p被$P攻了个措手不及! $COM";
		target->start_busy( me->query_skill("nianhua_zhi",1) / 20);
		me->add("mp", -100);
	}
	else
	{
		msg += "$HIM可是$p看破了$P的企图，并没有上当。$COM";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;