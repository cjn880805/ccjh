
// tanzhi_shentong.h 弹指神通
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CStanzhi_shentong);

virtual void create()
{
	set_name( "弹指神通");
	set("valid_force", "bibo_shengong");

	set("diff",110);

	Magic_t * magic;

	magic = add_magic("hui", do_hui);
	magic->name = "挥斥方遒";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jinglei", do_jinglei);
	magic->name = "弹指惊雷";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hua", do_hua);
	magic->name = "漫天花雨";
	magic->mp = 350;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N右指划了个半圈，一式「划天裂地」自上而下划向$n的全身", 320, -5, 35, 20,"刺伤",},
		{"$N左掌护胸，一招「我心悠悠」，右指欲举无力指向$n的额头", 280, 20, 20, 0,"刺伤",},
		{"$N双手齐出，一式「千夫所指」，疾指向$n的$l", 190, 15,15 , 0,"刺伤",},
		{"$N仰天一叹，一招「弹指人生」，双手幻出重重指影，点向$n的$l", 380, -5, 40, 50,"刺伤",},
		{"$N一式「笑指天南」，左掌蓄式，右指弹出一缕指风点向$n的$l", 240, 15, 10, 10,"刺伤",},
		{"$N用出「擎天一指」，蓄集全身力气，一指点向$n的$l", 420, -40, 30,80 ,"刺伤",},
	};

	int level = me->query_skill("tanzhi_shentong", 1);
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/
			m_actions.set("force", (me->query("skill_pro/弹指神通/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/弹指神通/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/弹指神通/damage")+100) * action[level].damage/100);
	
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/弹指神通/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/弹指神通/force"));
			if(me->query("skill_pro/弹指神通/force_point")>=level_point)
			{
				me->add("skill_pro/弹指神通/force",1);
				me->set("skill_pro/弹指神通/force_point",1);
				tell_object(me,"\n$HIR你的弹指神通配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/弹指神通/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/弹指神通/dodge"));
			if(me->query("skill_pro/弹指神通/dodge_point")>=level_point)
			{
				me->add("skill_pro/弹指神通/dodge",1);
				me->set("skill_pro/弹指神通/dodge_point",1);
				tell_object(me,"\n$HIR你的弹指神通使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/弹指神通/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/弹指神通/damage"));
			if(me->query("skill_pro/弹指神通/damage_point")>=level_point)
			{
				me->add("skill_pro/弹指神通/damage",1);
				me->set("skill_pro/弹指神通/damage_point",1);
				tell_object(me,"\n$HIR你的弹指神通威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        return notify_fail("练弹指神通必须空手。");
    if ( me->query_skill("bibo_shengong", 1) < 20)
        return notify_fail("你的碧波神功火候不够，无法学弹指神通。");
	if ( me->query("max_mp") < 100)
        return notify_fail("你的内力太弱，无法练弹指神通。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
        return notify_fail("你的体力不够，休息一下再练吧。");
	if ( me->query("mp") < 20)
        return notify_fail("你的内力不够练弹指神通。");
    me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
	
}


//perform 
static int do_hui(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("「挥斥方遒」只能在战斗中使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( me->query_weapon())
		return notify_fail("你使用了武器。");
	
	if( skill < 50)
		return notify_fail("你的弹指神通等级不够, 不能使用「挥斥方遒」！");
	
	if( me->query("mp") < 150 )
		return notify_fail("你的内力不够，无法运用「挥斥方遒」！");
	
	msg =   "$N使出弹指神通之「挥斥方遒」, 顿时眼内精光暴射，\n";
	
	int di = me->query_skill("tanzhi_shentong") / 15;
	int dp = target->query_skill("force") / 10;
	if( di < 1 )
		di = 1;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > (dp - di) )
	{
		me->add("mp",-150);
		msg += "$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！"  ;
		
		int wound = -(skill+random(200)*3);
		if( target->query("mp") < wound)
			wound = target->query("mp");
		target->add("mp", wound);
		target->add("hp", wound / 5);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		msg += "可是$n的看破了$N的企图，立刻采取守势，使$P的「挥斥方遒」没有起到作用。" ;
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

static int do_jinglei(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || !me->is_fighting(target))
		return notify_fail("「弹指惊雷」只能在战斗中使用。");
	
	if ( me->query_weapon())
		return notify_fail("你使用了武器。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( skill < 120)
		return notify_fail("你的弹指神通等级不够, 不能使用「弹指惊雷」！");
	
	if( me->query("mp") < 150 )
		return notify_fail("你的内力不够，无法运用「弹指惊雷」！");
	
	msg =   "$N使出弹指神通之「弹指惊雷」, 顿时眼内精光暴射，\n";
		
	LONG dp = target->query_combat_exp();
	if( dp < 1 )
		dp = 2;
	if( random(me->query_combat_exp()) > dp/2)
	{
		me->add("mp",-150);
		msg += "$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！" ;
		if (  (weapon = target->query_weapon()))
		{
			if(weapon->query("no_duo") && !random(3) )
				msg += "可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。" ;
			else
			{
				msg += "同时手腕一麻，手中";
				msg += weapon->name();
				msg += "脱手而出！"  ;
				weapon->move(me->environment());
			}
		}
		
		int wound = 300 + random(200);
		if( target->query("mp") < wound)
			wound = target->query("mp");
		target->add("mp", -wound);
		target->receive_wound("hp", wound/5);
		target->start_busy(5);
		me->start_busy(2);
	}
	else
	{
		msg += "可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。" ;
		me->start_busy(3);
	}
	message_vision(msg.c_str(), me, target);
	
	//if(!target->is_fighting(me)) 		target->kill_ob(me);
	return 1;
}

static int do_hua(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	int damage, num;

	if(ob && ob->is_character())
		target = (CChar *) ob;

	if (!me->query("门派/thd/hua"))
		return notify_fail("你虽然听说过「漫天花雨」这一招，可是却未获传授。\n");
	
	int skill = me->query_skill("tanzhi_shentong",1);
	
	if( !target || !me->is_fighting(target))
		return notify_fail("「漫天花雨」只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("「漫天花雨」必须装备暗器才能使用。\n。");

	if ((num = weapon->Query_Amount()) < skill / 20) 
		return notify_fail("你掏了掏背囊，发现里面的暗器已经不够使用「漫天花雨」的要求了！\n");
	
	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛"))
		return notify_fail("「漫天花雨」的使用技巧只传授给桃花岛的弟子。");
	
	if( skill < 120)
		return notify_fail("你的弹指神通不够娴熟，无法使用「漫天花雨」！");
	
	if( me->query("mp") < 450 )
		return notify_fail("你的内力不够，无法运用「漫天花雨」！");
	
	char msg[255],tmp[80];
	message_vision(snprintf(msg, 255, "$CYN$N双手在背囊里一抓，抓出%s%s%s来，运用指力漫天地弹了出去，$n只觉眼前似乎在下一场暗器雨！",
		chinese_number(skill/20,tmp),weapon->querystr("base_unit") , weapon->querystr("name")),me,target);
	
	damage = skill * 4 + me->query_skill("bibo_shengong", 1)*2;
	damage += random(damage / 3);
	if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
	{
		message_vision("$HIR$n躲闪不及，“噗噗”地几声，被几道暗器击中！\n", me, target);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage / 3);
	} 
	else
	{
		message_vision("$HIW$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n", me, target);
	}

	me->add("mp", -350);
	me->start_busy(3);
	if (num == skill / 20)
	{
		destruct(weapon);
		tell_object(me, snprintf(msg, 255,"\n你的%s用完了！\n" ,weapon->querystr("name")));
	}

	((CItem *)weapon)->add_amount(-(skill/20));
	
	return 1;
}

int valid_combine(string combo) { return combo=="lanhua_shou"; }

SKILL_END;
