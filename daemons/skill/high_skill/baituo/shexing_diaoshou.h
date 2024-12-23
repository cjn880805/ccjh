//shexing_diaoshou.h 蛇形刁手

//coded by Fisho
//date : 2000-11-29

SKILL_BEGIN(CSshexing_diaoshou);

virtual void create()
{
	set_name( "蛇形刁手");

	set("valid_force", "hamagong");

	Magic_t * magic;

	magic = add_magic("wugu", do_wugu);
	magic->name = "灵蛇拳";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge, damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一式「灵蛇出洞」，右手虚晃，左手扬起，突然拍向$n的背后二穴", 200, 10, 30, 0, "瘀伤",},
		{"$N侧身一晃，一式「虎头蛇尾」，左手拿向$n的肩头，右拳打向$n的胸口", 220, 10, 42 , 10, "瘀伤",},
		{"$N一式「画蛇添足」，右手环拢成爪，一出手就向扣$n的咽喉要害",230 , 20, 45,20 ,"瘀伤",},
		{"$N左手虚招，右掌直立，一式「杯弓蛇影」，错步飘出，疾拍$n的面门", 260 , 20, 40,30 ,"瘀伤",},
		{"$N使一式「蛇行鼠窜」，左拳上格，右手探底突出，抓向$n的裆部", 300, 10, 45, 38, "瘀伤",},
		{"$N一式「蛇磐青竹」，十指伸缩，虚虚实实地袭向$n的全身要穴", 310, 10, 55, 51,"内伤",},
		{"$N双手抱拳，一式「万蛇汹涌」，掌影翻飞，同时向$n施出九九八十一招", 380, 10, 60, 56, "内伤",},
		{"$N一式「白蛇吐信」，拳招若隐若现，若有若无，急急地拍向$n的丹田", 460, 20, 70, 60, "内伤",},
	};
  		
 	for(int i = 8; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("shexing_diaoshou", 1))
		{
			int level = random(i);

			m_actions.set("action", action[level].action);
/*			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
*/			m_actions.set("lvl", action[level].lvl);
			m_actions.set("damage_type", action[level].damage_type);
			
			m_actions.set("force", (me->query("skill_pro/白驼山派/蛇形刁手/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/白驼山派/蛇形刁手/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/白驼山派/蛇形刁手/damage")+100) * action[level].damage/100);
			
			break;
		}
	}

	return & m_actions;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/白驼山派/蛇形刁手/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/蛇形刁手/force"));
			if(me->query("skill_pro/白驼山派/蛇形刁手/force_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/蛇形刁手/force",1);
				me->set("skill_pro/白驼山派/蛇形刁手/force_point",1);
				tell_object(me,"\n$HIR你的蛇形刁手配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/白驼山派/蛇形刁手/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/蛇形刁手/dodge"));
			if(me->query("skill_pro/白驼山派/蛇形刁手/dodge_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/蛇形刁手/dodge",1);
				me->set("skill_pro/白驼山派/蛇形刁手/dodge_point",1);
				tell_object(me,"\n$HIR你的蛇形刁手使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/白驼山派/蛇形刁手/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/白驼山派/蛇形刁手/damage"));
			if(me->query("skill_pro/白驼山派/蛇形刁手/damage_point")>=level_point)
			{
				me->add("skill_pro/白驼山派/蛇形刁手/damage",1);
				me->set("skill_pro/白驼山派/蛇形刁手/damage_point",1);
				tell_object(me,"\n$HIR你的蛇形刁手威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage)
{ 
	return (usage == "unarmed") || (usage == "hand") || (usage == "parry"); 
}

virtual int valid_learn(CChar * me)
{
	if ( me->query_weapon() )
		return notify_fail("蛇形刁手其实是一种空手的技能。");
	
	if (me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不够，无法学蛇形刁手。");
	
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练蛇形刁手。");

 	return 1;
}

virtual int practice_skill(CChar * me)
{

	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");

	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练蛇形刁手。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

static int do_wugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || !me->is_fighting(target))		//add by Lanwood 2000-12-26
		return notify_fail("只能对战斗中的敌人使用。");

	if( me->query_dex() < 25)
		return notify_fail("你敏捷不够,不能使用这一绝技!");
	
	if( me->query_skill("hamagong",1) < 100)
		return notify_fail("你蛤蟆功的功力不够不能使用灵蛇拳!");
	
	if( me->query_skill("shexing_diaoshou") < 120)
		return notify_fail("你的蛇形刁手修为不够,目前还不能使用灵蛇拳!");
	
	if( me->query("mp") < 200)
		return notify_fail("你内力现在不够, 不能使用灵蛇拳! ");
		
	if(DIFFERSTR(me->querystr("family/family_name"), "白驼山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( target->is_busy() )
		return notify_fail("%s目前正自顾不暇，放胆攻击吧 ",target->name() );
	
	msg =   "$N右手往外一打，突然间手臂如同没有了骨头一般回转过来，啪的一声打在$n的后脑上。\n";
	
	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 3 )
	{
		msg +=    "结果$p被$P打个正着，顿时一阵头昏眼花，耳朵里满是小鸡的叫声! "  ;
		target->start_busy(  me->query_skill("shexing_diaoshou",1) / 40 );
		me->add("mp", -50);
	}
	else
	{
		msg +=   "可是$p看破了$P的企图，轻轻一跃，跳了开去。"  ;
		me->start_busy(2);
		me->add("mp", -50);		
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

