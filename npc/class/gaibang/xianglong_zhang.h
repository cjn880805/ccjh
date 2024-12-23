
// xianglong_zhang.c 降龙十八掌
//code by Fisho
//date : 2000-12-05


SKILL_BEGIN(CSxianglong_zhang);

virtual void create()
{
	set_name("降龙十八掌");

	Magic_t * magic;

	magic = add_magic("leiting", do_leiting);
	magic->name = "雷霆一击";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("xianglong", do_xianglong);
	magic->name = "降龙大法";
	magic->mp = 300;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",0 ,10 , 130,"瘀伤",},
		{"$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l", -10, -10, 150,"瘀伤",},
		{"$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l", -15, -10,170 ,"瘀伤",},
		{"$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l", -10,20 , 190,"瘀伤",},
		{"$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l", -15,-20 , 210,"瘀伤",},
		{"$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l", -10, 10, 220,"瘀伤",},
		{"$N使出「羝羊触蕃」，双掌由下往上击向$n的$l", -15, 40, 230,"瘀伤",},
		{"$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l", -15,20 , 240,"瘀伤",},
		{"$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l", -10, 40, 250,"瘀伤",},
		{"$N使出「或跃在渊」，向$n的$l连拍数掌", -20, -20, 260,"瘀伤",},
		{"$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l", -10, 20, 270,"瘀伤",},
		{"$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下", -20, 30,280 ,"瘀伤",},
		{"$N双掌立起，使出「时乘六龙」向$n连砍六下", -20, 20, 300,"瘀伤",},
		{"$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n", -25, -10, 330,"瘀伤",},
		{"$N门户大开，一招「履霜冰至」向$n的$l劈去", -25, 1,350 ,"瘀伤",},
		{"$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l", -20, 40, 360,"瘀伤",},
		{"$N使出「损则有孚」，双掌软绵绵地拍向$n的$l", -25, 10, 380,"瘀伤",},
		{"$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l", -30, 10, 450,"瘀伤",},
	};
	
	int level = 0;
	
	if( me->query_temp("xianglong") 
		&& ( me->query("mp") > 20 ) )
	{
		me->add_temp("apply/str", me->query_temp("str_count"));
		me->add("mp", -20);
		me->add_temp("str_no", 1);
		me->add_temp("display_no", 1);
		if( me->query_temp("display_no") == 2 )
		{
			message_vision( "$HIY$N深吸了一口气，越战越勇！", me);
			me->set_temp("display_no", 0);
		}
	}
	
	level = random(18);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	
	return &m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "strike") || usage == "unarmed" || (usage == "parry");

}

//virtual int valid_combine(string combo) { return combo=="jiuyin_baiguzhao"; }	

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练降龙十八掌必须空手。");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("你的混天气功火候不够，无法练降龙十八掌。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练降龙十八掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 40)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 10)
		return notify_fail("你的内力不够练降龙十八掌。");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_leiting(CChar * me, CContainer * ob)
{
	int damage;
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("「雷霆一击」只能对战斗中的对手使用。");
	
	if( me->query_skill("huntian_qigong", 1) < 100 )
		return notify_fail("你的混天气功火候不够，使不出「雷霆一击」。");
	
	if( me->query_skill("xianglong_zhang", 1) < 100 )
		return notify_fail("你的降龙十八掌不够熟练，不会使用「雷霆一击」。");
	
	if( me->query("mp") < 500 )
		return notify_fail("你的内力修为还不够高。");
	
	msg =  "$N默运混天气功，施展出「雷霆一击」，全身急速转动起来，越来越快，就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。\n";  
	
	if(random(me->query_combat_exp()) > target->query_combat_exp()/3) 
	{ 
		me->start_busy(3);
		target->start_busy(random(3));
		me->add("mp", -500);
		damage = me->query_skill("xianglong_zhang", 1)*4+me->query_skill("huntian_qigong",1);
		
		damage = damage + random(damage);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		msg += "$n只见一阵旋风影中陡然现出$N的双拳，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！";
	}
	else
	{
		me->add("mp", -50);
		me->start_busy(1);
		msg += "可是$p看破了$P的企图，闪在了一边。";
	}

	
	message_vision(msg.c_str(), me, target);
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}

static int do_xianglong(CChar * me, CContainer * ob)
{
	int skill, count;
	
	if( me->query_temp("xianglong") ) 
		return notify_fail("你已经在运功中了。");
	if( !me->is_fighting() )
		return notify_fail("降龙大法只能在战斗中使用。");
	if( me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。");
	
	count = me->query_str();
	skill = me->query_skill("xianglong_zhang",1);
	me->add("mp", -100);
	message_vision(  "$N深吸一口气，运起降龙大法，结果越战越勇！" , me);
	me->set_temp("xianglong", 1);
	me->set_temp("str_count", count/5);
	me->set_temp("str_no", 0);
	me->set_temp("display_no", 0);
	me->call_out(remove_effect, skill / 2 );
	return 1;
}

static void remove_effect(CContainer *ob, LONG amount, LONG param)
{
	CChar *me =(CChar *) ob;
	
	LONG dmount = me->query_temp("str_no") * me->query_temp("str_count");
	me->add_temp("apply/str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");

	tell_object(me, "你的降龙大法运行完毕，将内力收回丹田。");
}

SKILL_END;
