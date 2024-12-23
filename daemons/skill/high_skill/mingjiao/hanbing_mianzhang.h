
// hanbing_mianzhang.h 寒冰绵掌
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShanbing_mianzhang);

virtual void create()
{
	set_name( "寒冰绵掌");

	set("valid_force", "shenghuo_shengong");

	Magic_t * magic;

	magic = add_magic("xixue", do_xixue);
	magic->name = "吸血青蝠";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force,lvl;
		char damage_type[5];
	}action[] = {
		{"$N双掌疾伦，一式「如罩寒霜」，又臂突然划起一道半孤，罩向$n的全身。", 10, 150,0,"瘀伤",},
		{"$N双腿合并，呼的向上纵起，一式「如寒冰头」，二掌直下，攻向$n的头部。", 5, 160,10,"瘀伤",},
		{"$N左掌护胸，一式「白露为霜」，右掌直线击出，疾拍$n的胸前大穴。",5 , 170,20,"瘀伤",},
		{"$N使一式「寒梅纷飞」，双掌绵绵不绝的拍出，似朵朵雪中红梅罩向$n。", -5, 185,50,"瘀伤",},
		{"$N深吸一口气，右拳凝劲后发，一式「天寒地冻」，一股寒流缓缓推向$n的$l。", 10, 200,100,"瘀伤",},
		{"$N使一式「冰天雪地」，双掌突的变成雪白，一前一后，猛地拍向$n的$l。", 5, 220,200,"瘀伤",},
		{"$N双目微张，一式「雪花纷飞」，双掌化作片片雪花疾拍向$n的$l。", 5, 220,250,"瘀伤",},
		{"$N向上高高跃起，一式「满天冰雨」，居高临下，掌力似冰似雨笼罩$n的全身。", 20, 240,300,"瘀伤",},
	};
	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("hanbing_mianzhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练寒冰绵掌必须空手。");
	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("你的圣火神功火候不够，无法练寒冰绵掌。");
	if ( me->query("max_mp") < 300)
		return notify_fail("你的内力太弱，无法练寒冰绵掌");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 8)
		return notify_fail("你的内力不够练寒冰绵掌。");
	if (me->query_skill("hanbing_mianzhang", 1) < 50)
		me->receive_damage("hp", 20);
	else
		me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
	
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage )
{
	if( random(me->query_skill("shenghuo_shengong")) > 10 ) 
	{
		victim->apply_condition("ice_poison", random(me->query_skill("shenghuo_shengong")/10) + 1 +
			victim->query("condition/ice_poison"));
	}
	return "";
}

//perform 
static int do_xixue(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	int skill = me->query_skill("hanbing_mianzhang",1);

	if(ob && ob->is_character())
		target = (CChar *) ob;
	
	if(!target || ! me->is_fighting(target))
		return notify_fail("「吸血青蝠」只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( me->query_weapon())
		return notify_fail("你使用了武器。");
	
	if( skill < 60)
		return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「吸血青蝠」！");

	if(me->query("mp") < 100)		//add by Lanwood 2000-12-26
		return notify_fail("你的内力不足。");
	
	if( me->query_skill("dodge",1) < 150 )
		return notify_fail("你的轻功不够，无法运用「吸血青蝠」！");
	
	msg =  "\n$HIR$N突然如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的咽喉咬去。\n";
		
	LONG ap = me->query_combat_exp() + skill * 400;
	LONG dp = target->query_combat_exp() / 2;
	if( dp < 1 )
		dp = 1;		
	if( random(ap) > dp )
	{
		me->add("mp",-100);
		
		msg +=  "$HIR$n只觉得咽喉一阵剧痛，$N正在狂吸$n的鲜血！";
		int neili_wound = 100 + random(skill);
		if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
		
		int qi_wound = neili_wound * 5;
		if(qi_wound > target->query("hp"))
			qi_wound = target->query("hp");
		
		target->add("mp", -neili_wound);
		target->add("hp", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg +=  "只见$n不慌不忙，轻轻一闪，躲过了$N的利齿！";
		me->add("mp",-100);
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;
