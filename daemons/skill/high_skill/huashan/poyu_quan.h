// poyu_quan.h 劈石破玉拳
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSpoyu_quan);

virtual void create()
{
	set_name( "劈石破玉拳");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("leidong", do_leidong);
	magic->name = "雷动九天";
	magic->mp = 500;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N右脚立定、左脚虚点，一式「起手式」，左右手一高一低，击向$n的$l",180 , 5, 0,"瘀伤",},
		{"$N左脚虚踏，全身右转，一招「石破天惊」，右拳猛地击向$n的$l", 200, 10, 10,"瘀伤",},
		{"$N双手大开大阖，宽打高举，使一招「铁闩横门」，双拳向$n的$l打去",220 , 15, 20,"瘀伤",},
		{"$N左掌圈花扬起，屈肘当胸，右手虎口朝上，一招「千斤坠地」打向$n的$l", 260, 20, 30,"瘀伤",},
		{"$N使一招「傍花拂柳」，上身前探，双拳划了个半圈，击向$n的$l", 300,25 , 40,"瘀伤",},
		{"$N双拳划弧，一记「金刚挚尾」，掌出如电，一下子切到$n的手上", 360, 0, 50,"瘀伤",},
		{"$N施出「封闭手」，双拳拳出如风，同时打向$n头，胸，腹三处要害", 420, 35, 60,"瘀伤",},
		{"$N左脚内扣，右腿曲坐，一式「粉石碎玉」，双拳齐齐捶向$n的胸口", 540, 40, 80,"瘀伤",},
	};
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("poyu_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "cuff") || (usage == "parry");
}

virtual int valid_combine(string combo) { return combo=="hunyuan_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练「劈石破玉拳」必须空手。");
	if ( me->query_skill("zixia_shengong", 1) < 10)
		return notify_fail("你的「紫霞神功」火候不够，无法学「劈石破玉拳」。");
	if ( me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练「劈石破玉拳」。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练「劈石破玉拳」。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leidong(CChar * me, CContainer * ob)
{
	int skill, count, count1;
	
	if(  me->query_temp("leidong") ) 
		return notify_fail("你已经在运功中了。");
	if( !me->is_fighting() )
		return notify_fail("雷动九天只能在战斗中使用。");
	if(  me->query("mp") < 500  ) 
		return notify_fail("你的内力不够。");
	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	count = me->query_str();
	skill = me->query_skill("cuff");
	if( skill < 135  ) 
		return notify_fail("你的破玉拳修为还不够。");
	
	me->add("mp", -400);
	message_vision( "$N深深吸了一口气，脸上顿时紫气大盛，出手越来越重！" , me);
	
	count = me->query("str") +  (skill/10);
	count1 = me->query("dex") +  (skill/10);
	
	me->add_temp("apply/str", count);
	me->add_temp("apply/dex", count1);
	me->set_temp("leidong", 1);
	me->call_out( remove_effect, skill/3, count, count1);
 	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG amount1)
{
	CChar *me=(CChar *)ob;
	me->add_temp("apply/str", -amount);
	me->add_temp("apply/dex", -amount1);
	me->delete_temp("leidong");

	me->SendState();
	tell_object(me, "你的雷动九天运行完毕，将内力收回丹田。");
	me->start_busy(4);
}

SKILL_END;
