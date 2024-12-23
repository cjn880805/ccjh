// zhemei_shou.h 折梅手
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSzhemei_shou);

virtual void create()
{
	set_name( "折梅手");

	Magic_t * magic;
	set("diff",150);

	magic = add_magic("duo", do_duo);
	magic->name = "空手入白刃";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "bahuang_gong") || EQUALSTR(arg, "beiming_shengong"))
		return 1;

	return notify_fail("折梅手必须与专门的内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「吹梅笛怨」，双手横挥，抓向$n", 130, 20, 0, 0,"瘀伤",},
		{"$N一招「黄昏独自愁」，身子跃然而起，抓向$n的头部", 150, 20, 20, 10,"瘀伤",},
		{"$N一招「寒山一带伤心碧」，双手纷飞，$n只觉眼花缭乱", 150, 30, 30, 30,"瘀伤",},
		{"$N一招「梅花雪落覆白苹」，双手合击，$n只觉无处可避", 150, 30, 45, 40,"瘀伤",},
		{"$N一招「砌下落梅如雪乱」，双手飘然抓向$n", 250, 30, 50, 50,"瘀伤",},
		{"$N双手平举，一招「云破月来花弄影」击向$n", 300, 35, 80, 60,"瘀伤",},
		{"$N一招「花开堪折直须折」，拿向$n，似乎$n的全身都被笼罩", 350, 30, 100, 70,"内伤",},
		{"$N左手虚晃，右手一记「红颜未老恩先绝」击向$n的头部", 350, 30, 150, 80,"瘀伤",},
		{"$N施出「虚妄笑红」，右手横扫$n的$l，左手攻向$n的胸口", 400, -10,150 ,90 ,"瘀伤",},
		{"$N施出「玉石俱焚」，不顾一切扑向$n", 450, -20, 150, 100,"瘀伤",},
	};
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("zhemei_shou", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", (me->query("skill_pro/灵鹫宫/折梅手/force")+100) * action[level].force/100);
			m_actions.set("dodge", (me->query("skill_pro/灵鹫宫/折梅手/dodge")+100) * action[level].dodge/100);
			m_actions.set("damage", (me->query("skill_pro/灵鹫宫/折梅手/damage")+100) * action[level].damage/100);
			break;
		}
	}
	
	return & m_actions;
};


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(!random(10)||wizardp(me))
	{
		int level_point;
		if(victim->query("force")) 
		{
			me->add("skill_pro/灵鹫宫/折梅手/force_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/折梅手/force"));
			if(me->query("skill_pro/灵鹫宫/折梅手/force_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/折梅手/force",1);
				me->set("skill_pro/灵鹫宫/折梅手/force_point",1);
				tell_object(me,"\n$HIR你的折梅手配合内功更能融汇贯通了。\n");
			}
		}
		else if(victim->query("dodge")) 
		{
			me->add("skill_pro/灵鹫宫/折梅手/dodge_point",1);
			
			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/折梅手/dodge"));
			if(me->query("skill_pro/灵鹫宫/折梅手/dodge_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/折梅手/dodge",1);
				me->set("skill_pro/灵鹫宫/折梅手/dodge_point",1);
				tell_object(me,"\n$HIR你的折梅手使用得更加得心应手了。\n");
			}
		}
		else if(victim->query("damage")) 
		{
			me->add("skill_pro/灵鹫宫/折梅手/damage_point",1);

			level_point=(query("diff")+80)*(1+me->query("skill_pro/灵鹫宫/折梅手/damage"));
			if(me->query("skill_pro/灵鹫宫/折梅手/damage_point")>=level_point)
			{
				me->add("skill_pro/灵鹫宫/折梅手/damage",1);
				me->set("skill_pro/灵鹫宫/折梅手/damage_point",1);
				tell_object(me,"\n$HIR你的折梅手威力更大了。\n");
			}
		}
	}
	return "";
}

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "hand" || usage == "parry"; 
}

virtual int valid_combine(string combo) { return combo=="liuyang_zhang"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练天山折梅手必须空手。");
	if ( me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练天山折梅手。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练天山折梅手。");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}
//perform 
static int do_duo(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(  me->query_temp("duo") )
		return notify_fail("你已经在夺敌人的兵刃了。");
	
	int skill = me->query_skill("zhemei_shou",1);
	
	if( !target || ! me->is_fighting(target))
		return notify_fail("空手入白刃只能对战斗中的对手使用。");

	if(DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( me->query_weapon())
		return notify_fail("你必须空手。");
	
	if (! (weapon = target->query_weapon()))
		return notify_fail("对方没有兵刃，你不用担心。");
	
	if( skill < 50)
		return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的内力不够，无法空手入白刃！");
	
	msg =   "$N凝神闭息，打算施展空手入白刃的绝技. \n";
	
	int dp = target->query_skill("parry") * 2 / 3;
	if( dp < 1 )
		dp = 1;
	if( random(skill) > dp )
	{
		me->add("mp",-50);
		if(weapon->query("no_duo") && !random(3))
			msg += "可是$n看破了$N的企图，并没有上当";
		else
		{
			msg += "$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！"  ;
			if(weapon->query("no_duo") )//是否是宝物
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon->object_id()));
			}
			else
			{
				target->start_busy(2);
				//判断是否自制兵器！！ lanwood 2001-04-04
				if(weapon->querystr("owner")[0])
					weapon->move(me->environment());
				else
					weapon->move(me);
			}
		}

		me->start_busy(random(2));
	}
	else
	{
		msg += "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。" ;
		me->start_busy(random(2));
	}
	message_vision(msg.c_str(), me, target);
 	return 1;
}

SKILL_END;




