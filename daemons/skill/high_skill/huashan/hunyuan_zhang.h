// hunyuan_zhang.h 混元掌
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShunyuan_zhang);

virtual void create()
{
	set_name( "混元掌");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;

	magic = add_magic("wuji", do_wuji);
	magic->name = "混元无极";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一式「白云出岫」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l", 180,5 , 20, 10, 0,"瘀伤",},
		{"$N并指如剑，一式「白虹贯日」，疾向$n的$l戳去", 220, 10,15 , 20, 10,"瘀伤",},
		{"$N使一式「云断秦岭」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l", 260, 15, 20, 30, 20,"瘀伤",},
		{"$N双掌隐隐泛出青气，一式「青松翠翠」，幻成漫天碧绿的松针，雨点般向$n击去", 300, 20,30 , 40,30 ,"瘀伤",},
		{"$N身形往上一纵，使出一式「天绅倒悬」，双掌并拢，笔直地向$n的$l插去", 340, 25, 20,50 , 40,"瘀伤",},
		{"$N身形一变，使一式「无边落木」，双掌带着萧刹的劲气，猛地击往$n的$l",380 , 25, 25, 60, 50,"瘀伤",},
		{"$N使一式「高山流水」，左掌凝重，右掌轻盈，同时向$n的$l击去", 420, 30, 30, 70, 60,"瘀伤",},
		{"$N突地一招「金玉满堂」，双掌挟着一阵风雷之势，猛地劈往$n的$l",460 ,30 , 35,80 ,70 ,"瘀伤",},
		{"$N一式「风伴流云」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上", 500, 40, 45, 90, 80,"瘀伤",},
		{"$N一式「烟雨飘渺」，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪", 540,45 , 50, 110,90 ,"瘀伤",},
	};
 		
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("hunyuan_zhang", 1))
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

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry")|| (usage=="strike");
}

virtual int valid_combine(string combo) { return combo=="poyu_quan"; }


virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练混元掌必须空手。");
	if ( me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("你的紫霞神功火候不够，无法学混元掌。");
	if ( me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练混元掌。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 40)
		return notify_fail("你的内力不够练混元掌。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//perform 
static int do_wuji(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	int skill = me->query_skill("hunyuan_zhang",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("「混元无极」只能对战斗中的对手使用。");
	
	if ( me->query_weapon())
		return notify_fail("你使用了武器。");

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( skill < 60)
		return notify_fail("你的「混元掌」等级不够, 不能使用「混元无极」！");
	
	if( me->query("mp") < 150 )
		return notify_fail("你的内力不够，无法运用「混元无极」！");
	
	msg =   "$N潜运「混元无极」，双拳挟着隐隐的风雷之声向$n击去。\n" ;
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=  "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！" ;
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound * 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		target->UpdateMe();
		me->start_busy(random(2));
	}
	else
	{
		msg +=  "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！" ;
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;
