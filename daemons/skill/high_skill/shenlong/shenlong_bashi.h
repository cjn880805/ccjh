// shenlong_bashi.h 神龙八式
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshenlong_bashi);

virtual void create()
{
	set_name( "神龙八式");
	set("valid_force", "shenlong_xinfa");

	Magic_t * magic;
	
	magic = add_magic("bada", do_bada);
	magic->name = "龙形八打";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("tuzhu", do_tuzhu);
	magic->name = "神龙吐珠";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("yingxiong", do_yingxiong);
	magic->name = "英雄三式";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("meiren", do_meiren);
	magic->name = "美人三招";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
/*
	magic = add_magic("flower", do_flower);
	magic->name = "彩蝶念花";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  damage,dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$N使一招「疏影横斜」,左手轻轻一抹，向$n的$l拍去", 20, 0, 10, 100,"瘀伤",},		
		{"$N鼓气大喝,双掌使一招「五丁开山」，推向$n的$l", 30,0 , 30,0 ,"瘀伤",},		
		{"$N顺势使一招「风行草偃」，移肩转身,左掌护面,右掌直击$n", 40, 80, 20, 200,"瘀伤",},		
		{"$N退后几步,突然反手一掌,一招「神龙摆尾」，无比怪异地击向$n", 50, 80, 20, 250,"瘀伤",},		
		{"$N使一式「风卷残云」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口", 50, 10, 30,250 ,"瘀伤",},		
		{"$N忽的使出「乾坤倒旋」,以手支地,双腿翻飞踢向$n", 60, -20 ,-20 , 250,"瘀伤",},		
		{"$N大吼一声，使出「同归于尽」，不顾一切般扑向$n", -25, -10, 60, 400,"内伤",},		
		{"$N深吸一口气,身体涨成球状,猛然流星赶月般直撞向$n", 80, 70,-10 , 400,"内伤",},		
	};
		
	int level = 0;
	
	level = random(8);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
//	if( DIFFERSTR(me->querystr("family/family_name"), "神龙教"))
//		return	notify_fail("必须是神龙教弟子方可以学习");

	if ( me->query_weapon()  )
		return notify_fail("练神龙八式必须空手。");
	
	if ( me->query_skill("shenlong_xinfa", 1) < 50)
		return notify_fail("你的神龙心法火候不够，无法学神龙八式.");
	
	if ( me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学神龙八式。");
	
	if ( me->query("max_mp") < 350)
		return notify_fail("你的内力太弱，无法练神龙八式。");
	
	if ( 2* me->query_skill("shenlong_xinfa",1) < me->query_skill("shenlong_bashi",1))
		return notify_fail("你的神龙心法火候不够，无法继续学神龙八式。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( DIFFERSTR(me->querystr("family/family_name"), "神龙教"))
		return	notify_fail("必须是神龙教弟子方可以练习");

	if ( me->query("hp") < 50)
		return notify_fail("你的体力太低了。");

	if ( me->query("mp") < 30)
		return notify_fail("你的内力不够练神龙八式。");

	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;	
}

int valid_combine(string combo) { return combo=="huagu_mianzhang"; }		//可以和化骨绵掌组合

// bada 龙形八打
static int do_bada(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	CContainer * weapon2;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target	||	!me->is_fighting(target))
		return notify_fail("$HIR龙形八打$COM只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( me->query_weapon())
		return notify_fail("只有空手才能使出$HIR龙形八打。$COM");
	
	if (! (weapon2 = target->query_weapon()))
		return notify_fail("对方没有兵刃，你用不上龙形八打。");
	
	if (me->query_skill("shenlong_bashi", 1) < 60 )
		return notify_fail("你的神龙八式等级不够, 不能用此绝招！");
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED你神龙心法火候不够，使不出「龙形八打」。$COM");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的内力不够，无法使用此绝招！");
	
	msg = "$HIY$N突然纵身上前，使出神龙八式中的绝招神龙八打。只见$N的一双手勾、挑、撩、切、捺、推、带、摔，舞出漫天手影！$COM\n";
	
	me->add("mp",-50);

	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(!weapon2->query("no_duo") || random(3))
		{
			if(userp(me))
				msg += "$HIR结果$n大吃一惊，手中兵器不由得脱手飞出。$COM\n";
			
			if(weapon2->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon2->object_id()));
			}
			else
			{
				weapon2->move(me->environment());
				if ( EQUALSTR(weapon2->querystr("owner"), target->id(1)) )
				{
					weapon2->move(target);
					msg += "$HIG那可是$n的随身家伙！$n手一伸将它捡回来。$COM\n";
				}
			}
		}
		me->start_busy(1);
	}
	if( random(me->query("combat_exp")) > (target->query("combat_exp") / 2) )
	{
		if(userp(me))
			msg += "$HIC结果$n大吃一惊，一阵忙乱不知所措!$COM\n";
		target->start_busy(random(6));
	}	
	else
	{
		msg += "$HIR可惜$n经验丰富，不为所动，$N自己却乱了阵脚。$COM\n";
		me->start_busy(4);
	}
	
	if(!target->is_fighting(me)) target->fight_ob(me);
	message_vision(msg.c_str(), me, target);
	return 1;
}

//	tuzhu	神龙吐珠
static int do_tuzhu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	int skill;
	int damage;

	skill = me->query_skill("shenlong_bashi", 1);

	if( !target	||	!me->is_fighting(target))
		return notify_fail("神龙吐珠只能在战斗中使用。");
	
	if ( me->query_weapon())
		return notify_fail("你必须空手才能使用神龙吐珠！");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
//	if( me->query_skill("zhaosheshu", 1) < 150 )
//		return notify_fail("你的招蛇术不够娴熟，不会使用神龙吐珠。");
	
	if( me->query_skill("shenlong_bashi", 1) < 150 )
		return notify_fail("你的神龙八式不够娴熟，不会使用神龙吐珠。");
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED你神龙心法火候不够。$COM");
	
	if( me->query("mp") < 300 )
		return notify_fail("你内力不够了。");

	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧！", target->name());

	me->add("mp", -200);
	target->receive_damage("hp", skill/ 3);
	message_vision("$HIW只听一阵狂风扫叶般的声响中，$N吹一下口哨，附近全是蛇群发出的怪叫声。$COM\n",me,target);
	if (random(me->query_skill("force")) > target->query_skill("force")/3
		&& random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
		message_vision("$HIW迷雾中一条巨蟒像$n扑了上去，神龙吐珠”！$n除了眼前一重重的雾气外，$n啥也看不见了！$COM\n", me, target);
		target->set_temp("block_msg/all",1);
		damage = me->query_skill("zhaosheshu", 1);
		damage = damage + random(damage);
		target->receive_damage("hp", damage/2);
		target->receive_damage("hp", damage/2);
//		me->call_out(tuzhu_end,  skill/30, me, target);
		me->call_out(tuzhu_end,  skill/30);
		target->start_busy(me->query_skill("shenlong_bashi",1)/40 + 2 );
		me->start_busy(2);
//		return 1;
	} 
	else
	{
		message_vision("$HIW迷雾中一条巨蟒像$n扑了上去，神龙吐珠”！$n除了眼前一重重的雾气外，$n啥也看不见了！$COM\n", me, target);
			msg = "$HIY$p情急智生，用气功迫开了$P的雾气。$COM\n";
		me->start_busy(2);
		message_vision(msg.c_str(), me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

static void tuzhu_end(CContainer * ob, LONG nTarget, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(nTarget);

	if(! target) return;
	
	target->enable_player();
	message_vision("$N抹了抹满脸的$HIR鲜血$COM，终于睁开了眼。", target);
	target->set_temp("block_msg/all", 0l);
	tell_object(me,"$HIR你终于抹掉了满脸的鲜血，看到了周围的情景。$COM");
	
	return;
}

//	yingxiong	英雄三式
static int do_yingxiong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	int extra;
	CContainer * weapon;

	extra = me->query_skill("shenlong_bashi",1);

	if(me->is_busy())
		return notify_fail("你现在没空！！");

	if( !target	||	!me->is_fighting(target))
		return notify_fail("「英雄三式」只能在战斗中使用。");
	
	if( DIFFERSTR(me->querystr("gender"), "男性"))
		return notify_fail("你不是纯阳之体，不能用英雄三式！");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (me->query_weapon())
//	if( (weapon = me->query_weapon()) || (me->query_weapon())->querystr("base_name"), "secondary_weapon")
		return notify_fail("「英雄三式」只能空手使用。");		
	
	if( me->query("mp") < 200 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("shenlong_bashi",1) < 70 )
		return notify_fail("你的神龙八式火候不够，无法使用「英雄三式」！");
	
	if( me->query_skill("shenlong_xinfa", 1) < 60 )
		return notify_fail("$RED你神龙心法火候不够。$COM");
	
	if( me->query_skill("force",1) < 60 )
		return notify_fail("你的内功修为不够，无法使用「英雄三式」！");

	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
//	me->add_temp("apply/dexerity",extra);
//	me->add_temp("apply/dodge",extra);
	weapon = me->query_weapon();
	
	message_vision("$CYN$N深吸一口气，朝$n大叫一声$HIY[英雄三式]$CYN！$COM\n" ,me,target);
	if(target->query_temp("apply/no_英雄三式") && random(me->query_combat_exp()) < target->query_combat_exp()/3 )
	{
		message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
	}
	else
	{
		message_vision("$RED-------------狄龙降龙！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
		{                
			message_vision("$HIW第一道毒气$HIR击中$n右身！$COM\n" ,me,target);
			target->apply_condition("snake_poison",10);
		}
		message_vision("$GRN-------------------子胥举鼎！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (me->query("combat_exp")> target->query("combat_exp")/2 )
		{                
			message_vision("$HIC第二道毒气$HIM扫中$n的左身！$COM\n" ,me,target);
		    target->apply_condition("wugong_poison",10);
		}
		message_vision("$MAG-------------------------鲁达拔柳！\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("force")) > target->query_skill("force") / 2)
		{                
			message_vision("$MAG最后一道毒气$HIB扫中$n的上身!$COM\n" ,me,target);
			target->apply_condition("chanchu_poison",10);
		}
	}
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
//	me->add_temp("apply/dexerity",-extra);
//	me->add_temp("apply/dodge",-extra);
	me->add("mp", -150);
	me->start_busy(3);
	
	return 1;
}

//	meiren	美人三招
static int do_meiren(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
		
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
//	CContainer * weapon;

	if(me->is_busy())
		return notify_fail("你现在没空！！");

	int extra = me->query_skill("shenlong_bashi", 1);

	if( !target	||	!me->is_fighting(target))
		return notify_fail("「美人三招」只能在战斗中使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if (DIFFERSTR(me->querystr("gender"), "女性"))
		return notify_fail("你不是纯阴之体，不能用美人三招！");

	if (me->query_weapon())
//	if ( (weapon = me->query_weapon()) )
		return notify_fail("「美人三招」只能空手使用。");		
	
	if (me->query_skill("shenlong_xinfa", 1) < 60 )
        return notify_fail("$RED你神龙心法火候不够。$COM");
	
	if( me->query("mp") < 200 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("shenlong_bashi",1) < 70 )
		return notify_fail("你的神龙八式火候不够，无法使用「美人三招」！");
	
	if( me->query_skill("force",1) < 60 )
		return notify_fail("你的内功修为不够，无法使用「美人三招」！");

	me->add_temp("apply/attack",  extra);
	me->add_temp("apply/damage", extra);
//	me->add_temp("apply/dex", extra);
//	me->add_temp("apply/dodge", extra);
	
	message_vision("$CYN$N动作抚媚，朝$n微微一笑$HIY[美人三招]$CYN！$COM\n" ,me,target);
	if(target->query_temp("apply/no_美人三招") && !random(2))
	{
		message_vision("可是$n看破了$N的企图，并没有上当。\n" ,me,target); 
	}
	else
	{
		message_vision("$RED-------------贵妃回眸！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
		{                
			message_vision("$HIW第一道毒气$HIR击中$n右身，！$COM\n" ,me,target);
			target->apply_condition("snake_poison", 10);
		}
		message_vision("$GRN-------------------飞燕回翔！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (me->query("combat_exp")> target->query("combat_exp")/2 )
		{                
			message_vision("$HIC第二道毒气$HIM扫中$n的左身！$COM\n" ,me,target);
		    target->apply_condition("wugong_poison", 10);
		}
		message_vision("$MAG-------------------------小怜横陈！$COM\n" ,me,target);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		if (random(me->query_skill("force")) > target->query_skill("force") / 2)
		{                
			message_vision("$MAG最后一道毒气$HIB扫中$n的上身!$COM\n" ,me,target);
			target->apply_condition("chanchu_poison", 10);
		}
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
//	me->add_temp("apply/dex", - extra);
//	me->add_temp("apply/dodge", - extra);
	me->add("mp", -150);
	me->start_busy(3);
	
	return 1;
}
/*
//	flower	彩蝶念花
static int do_flower(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	static char style_siqi[4][255] = {
		"$HIG小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！$COM",
			"$HIG长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！$COM",
			"$HIG眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！$COM",
			"$HIG翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！$COM" 
	};

//	static char style_qiusheng[3][255] = {
//		$HIR "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！\n" $COM,
//			$HIR "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！\n" $COM,
//			$HIR "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！\n" $COM
//	};

	static char style_mix[7][255] = {
		"$HIG小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！$COM" ,
			"$HIR江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！$COM",
			"$HIG长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！$COM",
			"$HIR余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！$COM",
			"$HIG眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！$COM",
			"$HIR声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！$COM",
			"$HIG翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！$COM",
	};
	
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	CContainer * weapon;

	if( !target	||	!me->is_fighting(target))
		return notify_fail("$HIM［彩蝶念花］只能对战斗中的对手使用。$COM");
	
	if( !(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不是刀。");
	
	if( me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("你的招蛇术不够娴熟。");
	
	if( me->query_skill("shenlong_bashi", 1) < 250 )
		return notify_fail("你的神龙八式不够娴熟。");

	if(DIFFERSTR(me->querystr("family/family_name"), "神龙教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query_skill("shedao_qigong", 1) < 150 )
		return notify_fail("你的本门内功不够娴熟。");
	
	if( me->query("mp") < 300 )
		return notify_fail("你内力不够了。");
	
	
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0; continue;}
			if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
			if(!obs[i]->query_skill("shenlong_bashi")) {FLAG=0; continue;}
			if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
			if(ob->query("skill_type") != "parry"){FLAG=0; continue;}
			if(obs[i]->query_skill_mapped("parry") != "shenlong_bashi") {FLAG=0; continue;}
		}	
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=me->query_skill("parry");
	extra_me=me->query_temp("apply/damage")+me->query_str()*me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
		skl_you=you->query_skill("parry",1);
		extra_you=you->query_temp("apply/damage")+you->query_str()*you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/4);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/4);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
		for(i=0;i<sizeof(style_mix);i++)
			if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
			else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
			me->add_temp("apply/attack",-(skl_you+skl_me)/4);
			me->add_temp("apply/damage",-(extra_you+extra_me)/2);
			you->add_temp("apply/attack",-(skl_you+skl_me)/4);
			you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/10);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_siqi);i++)
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_siqi[i]);
        me->add_temp("apply/attack",-skl_me/10);
        me->add_temp("apply/damage",-extra_me/3);
	}	
	if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
	{                
        msg = "$HIW第一道毒气$HIR击中$n右身，！$COM\n";   
        message_vision(msg.c_str(), me, target);
        target->apply_condition("snake_poison",10);
	}
	if (me->query("combat_exp")> target->query("combat_exp")/2 )
	{                
        msg += "$HIC第二道毒气$HIM扫中$n的左身！$COM\n";   
		message_vision(msg.c_str(), me, target);
        target->apply_condition("wugong_poison",10);
	}
	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{                
        msg += "$MAG最后一道毒气$HIB扫中$n的上身!$COM\n";   
        message_vision(msg.c_str(), me, target);
        target->apply_condition("chanchu_poison",10);
	}
	me->start_busy(2);
	return 1;
}
*/

SKILL_END;




