// wuwen_zhua.h 五文爪
//code by oho
//date : 2001-3-20

SKILL_BEGIN(CSwuwen_zhua);

virtual void create()
{
	set_name( "五文爪");

	Magic_t * magic;

	magic = add_magic("nv", do_zhua);
	magic->name = "八稚女";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int  lvl;
	}action[] = {
		{"$N运火劲在爪，一招“暗钩手”由下往上拂出，四道火光旋转地贴地卷向$n的双脚", 10,10 ,"内伤", 0,},
		{"$N全身起火，猛然突进，双爪上下交袭，一招“琴月阴”要将$n按倒在地",12 , 20,"内伤", 10,},
		{"$N飞身跃起，半空转身一招“抓节”，带着绿色的火虹抓向$n的额头", 15, 20,"内伤", 10,},
		{"$N手中带火,上前一步，左肘撞向$n胸口，身体顺势跃起一转，一招“鬼烧”在周围带起几圈绿色火光。", 29, 25,"内伤", 11,},
		{"$N高高抬起左脚，猛地一招“轰斧阴”，足跟直劈$n的肩膀。", 20,20 ,"内伤", 13,},
		{"$N突然飞身跃过$n的头顶，半空中回身一招“百合折”踢向$n的后脑", 24, 25,"内伤", 16,},
		{"$N使出“屑风”，蓦然游身而上，和$n擦身而过，$n正想回头，$N的爪已经在身后，将$n顺势一拉。", 20,20 ,"内伤",21 ,},
		{"$N使出绝招“八酒杯”，面露狞笑，良久猛地将火劲往半空一丢，半空顿时散开落下无数火球，迅猛无比地袭向$n", 5, 30,"内伤", 27,},
		{"$N左右手连环打向$n下巴，紧接着飞身跃起,手足并用，攻向$n头部，正是五文派绝招“葵花”", 10, 20,"内伤", 50,},
	};
	
	int level = 0;
	
	for(int i=9; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuwen_zhua", 1))
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
	return (usage == "unarmed") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon())
		return notify_fail("练五文爪必须空手。");
	
    if (me->query_skill("force", 1) < 20)
		return notify_fail("你的内功心法火候不够，练五文爪会被自己烧死。");
		if (me->query("max_mp") < 100)
			return notify_fail("你的内力太弱，无法练五文爪。");
		return 1;
}

virtual int practice_skill(CChar * me)
{
    if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if (me->query("mp") < 8)
		return notify_fail("你的内力不够练五文爪。");
    if (me->query_skill("wuwen_zhua", 1) < 60)
		me->receive_damage("hp", 15);
    else
		me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;
}
virtual char * hit_ob(CChar *me, CChar *victim, LONG &damage)
{
    if( random(me->query_skill("wuwen_zhua",1)) > 50) 
	{
		victim->apply_condition("wuwen_poison", random(2)+1+victim->query_condition("wuwen_poison"));
    }

	return 0;
}

//perform 
static int do_zhua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("「八稚女」只能对战斗中的对手使用。");
	
    if( me->query("repute") > 0)
        return notify_fail("你是侠义道人士，怎麽能用「八稚女」这种阴毒武功。");
	
    if( me->query_skill("wuwen_zhua", 1) < 15 )
        return notify_fail("你的五文爪不够娴熟，还使不出「八稚女」。");
	
    if( me->query_skill("force", 1) < 35 )
        return notify_fail("你的内功心法火候不够，使用「八稚女」会弄断自己指甲。");

	if(me->query("mp") < 100)
		return notify_fail("你的内力不足。");
	
    msg = "$N突然将高举双抓，然后象风一般突进，施展出「八稚女」，双爪疯狂乱抓，随后抓住$n胸部，掌心火劲如炮般连环吐出。\n";
	
    if (random(me->query_skill("force") + 1) > target->query_skill("force")/2||
        random(me->query_combat_exp() + 1) > target->query_combat_exp()/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
		
        int damage = me->query_skill("wuwen_zhua", 1);
		
		damage = damage + random(damage);
		
        target->receive_damage("hp", damage/2);
        target->receive_wound("hp", damage/4);
        me->add("mp", -damage/3);
		
		msg += "$n全身着火，连伤口中射出的血都烧了起来，胸前更穿了两个焦洞.";
    } 
	else
    {
        me->start_busy(5);
        msg += "可是$p看破了$P的企图，闪身护胸躲在了一边。";
    }
    message_vision(msg.c_str(), me, target);
	
    //if(userp(target)) target->kill_ob(me);
    //else
	
	if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
	
}

SKILL_END;
