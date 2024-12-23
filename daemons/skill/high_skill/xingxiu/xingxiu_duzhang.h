//xingxiu_duzhang.h 星宿毒掌
SKILL_BEGIN(CSxingxiu_duzhang);

virtual void create()
{
	set_name( "星宿毒掌");
	set("valid_force", "huagong_dafa");

	Magic_t * magic;

	magic = add_magic("sandu", do_sandu);
	magic->name = "散毒术";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("throw", do_throw);
	magic->name = "施毒术";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int dodge, force;
	}action[] = {
		{ "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
			-10, 160,},
		{"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
		-10, 160,},
		{"$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
		-20, 150,},
		{"$N双掌挟着一股腥臭之气拍向$n的$l",
		10, 160,},
		{"$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
		0, 300},
	};
	
	int level = random(4);
	
	if (random (me->query_skill("unarmed",1)) > 60 &&
		me->query_skill("force",1) > 50 &&
		me->query("mp") > 100 ) 
	{
        me->add("mp", -100);
		level = 4;
	}
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
        return notify_fail("你的体力太低了。");
    if (me->query("mp") < 8)
        return notify_fail("你的内力不够练星宿毒掌。");
    if (me->query_skill("xingxiu_duzhang", 1) < 50)
        me->receive_damage("hp", 20);
    else
        me->receive_damage("hp", 30);
	me->add("mp", -5);
    return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练星宿毒掌必须空手。");
    if (me->query_skill("huagong_dafa", 1) < 10)
		return notify_fail("你的化功大法火候不够，无法练星宿毒掌。");
    if (me->query("max_mp") < 60)
		return notify_fail("你的内力太弱，无法练星宿毒掌。");
    return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="sanyin_wugongzhao"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)

{
	if( random(me->query_skill("poison") + 1) > 50 ) 
	{
		victim->apply_condition("xx_poison", random(me->query_skill("poison")/10) + 1 +
			victim->query("condition/xx_poison"));

	}
	return 0;
}

static int do_sandu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->Query(IS_CHAR))
		target = (CChar *)ob;
	
	if( !me->query("condition/poison_sandu"))
		return notify_fail("你现在没毒可散。");
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("这里不能攻击别人! ");
	
	if(!target || ! userp(target) || wizardp(target) )
		return notify_fail("散毒只能对玩家使用。");
	
	if( target->query_combat_exp() < me->query_combat_exp()/2 )
		return notify_fail("对这人散毒是没用的。");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能散毒。");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("xingxiu_duzhang", 1) < 40 )
		return notify_fail("你的星宿毒掌不够娴熟，不能散毒。");

	if(me->query("mp") < 20)
		return notify_fail("你的内力不足。");
	
	msg = "$HIR只听得$N的骨节格格作响，$N的手猛地长了半尺，居然一把抓住$n手腕，将毒质运于手心，源源不断传入$n体内。\n";
	me->add("mp", -20);

	me->start_busy(1);
	if( random( me->query_skill("xingxiu_duzhang",1))
		> random(target->query_skill("dodge") ) ) 
	{
		msg += "结果$p无力挣扎，$P的本身阴毒不断散入$n体内！";
        target->receive_damage("hp",20);
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("poison_sandu", 1000);
		me->clear_condition();
        target->start_busy(1 + random(2));
	} else 
	{
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。";
		me->start_busy(3);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

static int do_throw(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if( (me->environment())->query("no_fight") )
		return notify_fail("这里不能攻击别人! ");
	
	if( !target || target == me)
		return notify_fail("施毒只能对对手使用。");
	
	if( me->query_skill("huagong_dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能施毒。");
	
	if( me->query_skill("xingxiu_duzhang", 1) < 40 )
		return notify_fail("你的星宿毒掌不够娴熟，不能施毒。");

	if(DIFFERSTR(me->querystr("family/family_name"), "星宿派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if( me->query("mp") < 20)
		return notify_fail("你的内力不足。");
	
	CContainer * env = me->environment();
	CContainer * obj;
	
	if ( ! (obj = env->PresentName("corpse_ob", IS_CORPSE))
		&& ! (obj = me->PresentName("corpse_ob", IS_CORPSE)) )
		return notify_fail("你周围没有尸体。");
	
	msg = "$N顺手抓起尸体，将毒质运于其上，掷向$n。\n";
	me->add("mp", -20);

	me->start_busy(1);
	if( random( me->query_skill("xingxiu_duzhang",1))
		> random(target->query_skill("dodge") - 1) ) 
	{
		msg += "$HIR结果$p被$P掷了个正着，尸体炸开，腐烂的尸液溅得$p满身都是！";
        target->receive_damage("hp", me->query_skill("poison",2)*(1+me->query_temp("apply/施毒术")*random(100)/100));
        target->receive_wound("hp",15 + random(10));
        target->apply_condition("xx_poison", random(me->query_skill("poison",1)/2) + 1 +
			target->query("condition/xx_poison"));
		target->start_busy(1 + random(2));
	} 
	else 
	{
		msg += "可是$p急忙闪在一旁，躲了开去。";
		me->start_busy(1);
	}
	
	message_vision(msg.c_str(), me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	DESTRUCT_OB(obj, "xingxiu_duzhang::do_throw");
	return 1;
}

SKILL_END;