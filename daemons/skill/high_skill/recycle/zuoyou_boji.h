
// zuoyou_boji.h 左右搏击之术
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSzuoyou_boji);

virtual void create()
{
	set_name( "左右搏击之术");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N突然将右手握拳向天一举，仿佛被人捏住了一样，$n看得正纳闷，却突然发现一个拳头夹着劲风击向自己的心窝", 300, 15, 0,"内伤",},
		{"$N身形忽然一矮，左手已经变掌，斜向上方八步赶蝉般地疾拍$n的小腹", 325,55 ,10 ,"内伤",},
		{"$N伸出右拳往左掌心一拍，随即直捣黄龙般地攻向$n的头部", 350, 10, 20,"内伤",},
		{"$N突然伸出左掌猛拍自己的右肘，接着五指张开，反手迅速地挥向$n的左脸，看来想在$n的脸上留下一座五指山", 375, 45, 30,"内伤",},
		{"$N双掌一拍，随即右掌攻向$n的左肩，$n急忙招架，$N的右掌却已变拳猛地捣向$n的胸口", 400, 30, 40,"内伤",},
		{"$N左掌下，右掌上地前后一揉，随即一翻，左掌从右掌上滑出，推出一股阳刚之劲袭向$n的胸口", 425, 15, 50,"内伤",},
		{"$N双手在胸前一格，然后左手变拳击向$n的头部，$n勉力刚格开，却发现$N的右掌已拍向自己的左肋下，不由大惊",450 , 50, 60,"内伤",},
		{"$N右手猛地抓住自己的左臂，但左手一转，便已变掌，并带着右手的力量向前急冲而出劈向$n的$l", 500, 40,70 ,"劈伤",},
		{"$N突然左臂前右臂后，呈十字形架在胸前，然后右臂骤然从左臂下滑出，握拳向上斜勾而出，猛击$n的下颌骨！", 550, 5, 80,"内伤",},
		{"$N忽然原地滴溜溜地一转，$n眼前就失去了$N的踪影。$n正左顾右盼间，却见$N突然出现在眼前，笑嘻嘻地挥拳直打$n的小腹！！", 600,80 , 90,"内伤",},
	};
  		
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zuoyou_boji", 1))
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
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("练左右搏击之术必须空手。");
    if ( me->query_skill("force", 1) < 30)
		return notify_fail("你的内功心法火候不够，无法练左右搏击之术。");
    if ( me->query("max_mp") < 200)
		return notify_fail("你的内力太弱，无法练左右搏击之术。");
    if( me->query_skill("zuoyou_boji",1)>1)
		return notify_fail("左右搏击之术无法通过请教来获得进步。");
	if( me->query("int") > 25 ) 
		return  notify_fail("你的天性不适合学习双手互博之术!") ;
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 40)
		return notify_fail("你的体力太低了。");
    if ( me->query("mp") < 30)
		return notify_fail("你的内力不够练左右搏击之术。");
/*    if ( me->query_skill("zuoyou_boji",1) < 20)
		return notify_fail("以你目前的功力尚不够自己练习。");*/
    me->receive_damage("hp", 30);
    switch( random(3) ) 
	{
    case 0:
		me->add("combat_exp", -5);
		tell_object(me,   "你只觉得心绪一阵烦乱，头一阵发晕，你的经验降低了！", "practice");
		break;
    case 1:
		me->add("sk_exp", - random( me->query_con() +  me->query_skill("zuoyou_boji",1) )/20);
		me->add("combat_exp", random( me->query_con() +  me->query_skill("zuoyou_boji",1) )/10);
		tell_object(me, "你将左手和右手打来打去，练习左右搏击之术，增长不少实战经验，也有所感悟，潜能获得了提高。", "practice");
		break;
    case 2:
		me->add("sk_exp", 3);
		tell_object(me,   "你心有杂念，未能潜心练习，你可用的潜能减少了！", "practice");
		break;
	}
	return 1;
}

SKILL_END;
