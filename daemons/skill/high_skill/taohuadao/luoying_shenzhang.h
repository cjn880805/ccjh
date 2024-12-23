
// luoying_shenzhang.h 落英神掌
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSluoying_shenzhang);

virtual void create()
{
	set_name( "落英神掌");
	set("valid_force", "bibo_shengong");

	set("diff",100);

	Magic_t * magic;

	magic = add_magic("xuan", do_xuan);
	magic->name = "玄字诀";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pikong", do_pikong);
	magic->name = "劈空掌";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhong", do_zhong);
	magic->name = "种附骨针";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("ba", do_ba);
	magic->name = "拔附骨针";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N右手五指缓缓一收，一式「春风拂面」，五指忽然遥遥拂向$n，$n只觉得五股疾风袭向自己五处大穴", 200, 10, 0, "瘀伤",},
		{"$N突然纵身跃入半空，一式「落花无情」，双掌向下，疾扑$n的头顶", 210, 15, 10, "内伤",},
		{"$N伸出右手并拢食指中指，捻个剑决，一式「寻花探柳」，直指$n的中盘", 220, 20, 20, "内伤",},
		{"$N突然抽身而退，接着一式「随风而逝」，平身飞起，双掌向$n的$l连拍数掌", 235, 35, 30, "内伤",},
		{"$N使一式「狂风卷叶」，全身突然飞速旋转，双掌忽前忽后，猛地拍向$n的胸口", 250,30 , 40, "内伤",},
		{"$N前后一揉，一式「寸草不生」，双掌推出一股阴柔之力袭向$n的$l", 325,35 , 50, "内伤",},
		{"$N双手食指和中指迅速和在一起，一式「摧花断叶」，一股强烈的气流涌向$n的全身", 375, 20, 60, "内伤",},
		{"$N使一式「天女散花」，双掌舞出无数圈劲气，一环环向$n的$l斫去", 400, 35, 70, "劈伤",},
		{"$N两掌在胸前合什，施展出「推波助澜」，双掌骤然分开，祭出两团光球飞速攻向$n", 450, 10, 84, "内伤",},
		{"$N一式「落英缤纷」，双掌在胸前疾转数圈，不急不缓地推向$n。$n只见漫天掌花逼向自己，早已为此招所折服，根本不知躲避。", 510, -15, 99, "内伤",},
	};

	int level = me->query_skill("luoying_shenzhang", 1);
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
*/
			m_actions.set("force", (me->query("skill_pro/桃花岛/落英神掌/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/桃花岛/落英神掌/dodge")+100) * action[level].dodge/100);

			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "parry" || usage == "strike";	//lanwood 可装备到基本掌法
}

virtual int valid_combine(string combo) { return combo=="xuanfeng_leg"; }	//add by lanwood 可与旋风腿组合

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/桃花岛/落英神掌/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/落英神掌/force"));
			if(me->query("skill_pro/桃花岛/落英神掌/force_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/落英神掌/force",1);
				me->set("skill_pro/桃花岛/落英神掌/force_point",1);
				tell_object(me,"\n$HIR你的落英神掌配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/桃花岛/落英神掌/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/桃花岛/落英神掌/dodge"));
			if(me->query("skill_pro/桃花岛/落英神掌/dodge_point")>=level_point)
			{
				me->add("skill_pro/桃花岛/落英神掌/dodge",1);
				me->set("skill_pro/桃花岛/落英神掌/dodge_point",1);
				tell_object(me,"\n$HIR你的落英神掌使用得更加得心应手了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("练落英神掌必须空手。");
    if ( me->query_skill("bibo_shengong", 1) < 15)
		return notify_fail("你的碧波神功火候不够，无法学落英神掌。");
    if ( me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练落英神掌。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
    if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练落英神掌。");
	me->receive_damage("hp", 20);
    me->add("mp", -1);
	return 1;
	
}

//perform 
static int do_xuan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("神掌袭敌只能对战斗中的对手使用。");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 30 )
		return notify_fail("你的落英神掌不够娴熟，不会使用「玄」字诀。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query_skill("bibo_shengong", 1) < 30 )
		return notify_fail("你的碧波神功不够高，不能用来袭击敌人。");

	if( me->query("mp") < 300)		//add by Lanwood 2000-12-26
		return notify_fail("你的内力不足。");
	
	msg =   "$N默运落英心法，使出落英神掌「玄」字诀，从半空中撒出一片掌影逼向$n。\n" ;
	
	if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		
		int damage =  me->query_skill("bibo_shengong", 1); 
		damage = damage/2 + random(damage);
		
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/5);
		
		if ( damage < 40 ) 
			msg +=  "结果$N受到$n的内力反震，虽然击中$N，自己却闷哼一声向后退了两步。" ;
		
		else if( damage < 80 ) 
			msg +=  "结果$N被$n以内力反震，胸口有如受到一记重锤，连退了五六步！" ;
		
		else
			msg +=  "$n茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！" ;
	} 
	else
	{
		me->add("mp", -50);	
		me->start_busy(1);
		msg +=  "可是$p看破了$P的企图，早就闪在了一边。" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_pikong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("「劈空掌」绝技只能对战斗中的对手使用。\n");

	if (me->query_weapon())
		return notify_fail("你拿着武器怎么能使用「劈空掌」？");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 120 )
		return notify_fail("你的落英神掌不够娴熟，无法打出「劈空掌」。\n");

	if(  me->query_skill("bibo_shengong", 1) < 150 )
		return notify_fail("你的碧波神功修为未到，无法打出「劈空掌」。\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。\n");
	
	if( me->query("mp") < 400)		
		return notify_fail("你现在内力太弱，不能打出「劈空掌」。\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )
		return notify_fail("你虽然听说过「劈空掌」这一招，可是却未获传授。\n");
	
	msg =   "$HIB$N长啸一声，一式「劈空掌」向$n击到，挟带著澎湃汹涌的碧波神功，其势殊不可挡！" ;
	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge")/2 )
	{
		me->start_busy(1);
		target->start_busy(2);              
		int damage = me->query_skill("bibo_shengong", 1) +me->query_skill("luoying_shenzhang", 1);
		damage = damage*3-random(damage/2);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/2);
		me->add("mp", -400);

		msg += "\n$HIG$n被这凌空掌力一撞，如受大浪冲击，口中鲜血狂喷，身子如同断线风筝般飞出！\n";
	}
	else
	{
		me->start_busy(2);
		me->add("mp",-250);
		msg += "\n$CYN$n见掌势猛烈，急忙向旁一让，$N这一掌便即落空。\n";
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_zhong(CChar * me, CContainer * ob)
{
	if((me->environment())->query("no_fight"))
		return notify_fail("这里禁止战斗！无法使用「附骨钉」！");

	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target)
		return notify_fail("你要攻击谁？\n");

	if (me->query_weapon())
		return notify_fail("你拿着武器怎么能种「附骨钉」？");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 150 )
		return notify_fail("你的落英神掌不够娴熟，无法使用「附骨钉」。\n");

	if(  me->query_skill("bibo_shengong", 1) < 190 )
		return notify_fail("你的碧波神功修为未到，无法使用「附骨钉」。\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。\n");
	
	if( me->query("mp") < 1000)		
		return notify_fail("你现在内力太弱，不能使用「附骨钉」。\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )
		return notify_fail("你虽然听说过「种附骨针」这一招，可是却未获传授。\n");
	
	msg ="$HIY$N慢慢的走到$n身後，伸出手来。\n" ;
	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge")/2 )
	{
		target->add("门派/thd/fugu",1);
        msg+= "$HIR$N突然手轻轻的在$n背後拍了一下，$n觉得好像被什么刺了一下。\n";
		me->start_busy(3);
	}
	else
	{
		me->start_busy(5);
		msg += "$CYN$n看$N神色诡异，快步走了开去。\n";
	}
	me->add("mp",-1000);
	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_ba(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target)
		return notify_fail("这里没有这个人。\n");
	
	if(!target->query("门派/thd/fugu"))
		return notify_fail("这个人没有中附骨钉。\n");

	if (me->query_weapon())
		return notify_fail("你拿着武器怎么能拔除「附骨钉」？");
	
	if(  me->query_skill("luoying_shenzhang", 1) < 180 )
		return notify_fail("你的落英神掌不够娴熟，无法拔除「附骨钉」。\n");

	if(  me->query_skill("bibo_shengong", 1) < 200 )
		return notify_fail("你的碧波神功修为未到，无法拔除「附骨钉」。\n");
	
	if( me->query("mp") < 1000)		
		return notify_fail("你现在内力太弱，不能拔除「附骨钉」。\n");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )
		return notify_fail("你虽然听说过「拔附骨针」这一招，可是却未获传授。\n");
	
	me->add("mp",-1000);

	msg ="$HIY$N走到$n身後，伸出手来。\n" ;
	msg+="$HIW$N运起碧波神功，缓缓的将$n所中附骨钉拔出。\n";
	msg+= "$HIR$n惨叫一声，晕了过去。\n";
	target->add("门派/thd/fugu",-1);
	
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
