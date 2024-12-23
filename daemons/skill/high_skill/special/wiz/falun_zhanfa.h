// hualun_zhanfa.h 转法轮掌法
//code by Teapot
//date : 2001-02-06

SKILL_BEGIN(CSfalun_zhanfa);

virtual void create()
{
	set_name( "转齿轮掌法");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "真";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("shan", do_shan);
	magic->name = "善";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ren", do_ren);
	magic->name = "忍";
	magic->mp = 600;
	magic->target = CAST_TO_OTHER;
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
		{"$N双掌一错，一招「齿轮旋转式」幻出漫天掌影拢向$n的$l", 200, 10, 0, "瘀伤",},
		{"$N双掌纷飞，一招「齿轮翻飞式」直取$n的$l", 210, 15, 10, "内伤",},
		{"$N暴喝一声，双掌连环推出，一招「齿轮震天式」强劲的掌风直扑$n的$l", 220, 20, 20, "内伤",},
		{"$N使出转齿轮掌法中的「齿轮无边式」，完全将$n的$l笼罩在双掌之下", 235, 35, 30, "内伤",},
		{"$N化掌为刀，一招「齿轮乾坤式」，左右掌分砍$n的两处要害", 250,30 , 40, "内伤",},
		{"$N内气上提，全身拔起，一招「齿轮玄妙式」，双掌凌空拍下", 325,35 , 50, "内伤",},
		{"$N提气游走，一招「齿轮洪志式」，森森掌风无孔不入般地击向$n的$l", 375, 20, 60, "内伤",},
		{"$N使出转齿轮掌法中的「齿轮寰宇式」双掌携天地齿轮之威击向$n的$l", 400, 35, 70, "劈伤",},
	};

	int level = me->query_skill("falun_zhanfa", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
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
	return (usage == "strike") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("练转齿轮掌法必须空手。");
    if ( me->query_skill("falun_gong", 1) < 10)
		return notify_fail("你的齿轮大法火候不够，无法学转齿轮掌法。");
    if ( me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练转齿轮掌法。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("mp") < 4)
		return notify_fail("你的内力不够练转齿轮掌法。");
    me->add("mp", -4);
	return 1;
	
}


//perform 
static int do_zhen(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("真字诀只能对战斗中的对手使用。");
	
	if( !me->query("falun/know") || me->query("falun/know")<30)
		return notify_fail("你尚未领悟齿轮大法的「真」字。");
	
	if(  me->query_skill("falun_gong", 1) < 30 )
		return notify_fail("你的齿轮大法不够娴熟，不会使用「真」字诀。");
	
	if(  me->query_skill("falun_zhanfa", 1) < 30 )
		return notify_fail("你的转齿轮掌法不够高，不能使出「真」字诀。");

	if( me->query("mp") < 200)	
		return notify_fail("你的内力不足。");
	
	msg =   "$N默运转齿轮心法，使出齿轮「真」字诀，唧唧歪歪的说出一大篇歪理。\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage = damage/2 + random(damage);
		
		target->receive_wound("hp", damage);
		me->add("mp", -200);

		msg +=  "$n听得$N说法说得一头雾水，越听越晕，望空大喝一声喷出一口鲜血！" ;
	} 
	else
	{
		me->add("mp", -200);
		msg +=  "可是$p冷笑一声，将$P置之不理，自顾进攻。" ;
	}
	message_vision(msg.c_str(), me, target);
	me->start_busy(2);
	return 1;
}

static int do_shan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("善字诀只能对战斗中的对手使用。");
	
	if( !me->query("falun/know") || me->query("falun/know")<60)
		return notify_fail("你尚未领悟齿轮大法的「善」字。");
	
	if(  me->query_skill("falun_gong", 1) < 60 )
		return notify_fail("你的齿轮大法不够娴熟，不会使用「善」字诀。");
	
	if(  me->query_skill("falun_zhanfa", 1) < 60 )
		return notify_fail("你的转齿轮掌法不够高，不能使出「善」字诀。");

	if( me->query("mp") < 400)	
		return notify_fail("你的内力不足。");
	
	msg =   "$N默运转齿轮心法，使出齿轮「善」字诀，一个耳光便“善”向$n！\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage = damage/2 + random(damage);
		
//		target->apply_condition("sanxiao_poison", 20);
		target->apply_condition("bingpo_poison", 20);
		target->receive_wound("hp", damage);
		me->add("mp", -400);

		msg +=  "$n一不小心被$N善中，只觉得脸颊一阵剧痛，又渐渐转麻，原来掌中带了一根有毒银针！" ;
	} 
	else
	{
		me->add("mp", -400);
		msg +=  "可是$p轻轻飘开，$P一掌打在自己脸上，惨叫一声：原来掌中夹着一根银针！" ;
		me->receive_wound("hp", random(200));
		me->apply_condition("bingpo_poison", 20);
	}
	message_vision(msg.c_str(), me, target);
	me->start_busy(2);
	return 1;
}


static int do_ren(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("忍字诀只能对战斗中的对手使用。");
	
	if( !me->query("falun/know") || me->query("falun/know")<90)
		return notify_fail("你尚未领悟齿轮大法的「忍」字。");
	
	if(  me->query_skill("falun_gong", 1) < 90 )
		return notify_fail("你的齿轮大法不够娴熟，不会使用「忍」字诀。");
	
	if(  me->query_skill("falun_zhanfa", 1) < 90 )
		return notify_fail("你的转齿轮掌法不够高，不能使出「忍」字诀。");

	if( me->query("mp") < 600)	
		return notify_fail("你的内力不足。");
	
	msg =   "$N默运转齿轮心法，使出齿轮「忍」字诀，诡异的冲$n一笑！\n" ;
	
	if (random(me->query_skill("strike")) > random(target->query_skill("force")) )
	{
	me->start_busy(2);
		
		int damage =  me->query_skill("falun_zhanfa", 1); 
		damage += me->query_skill("strike");
		damage = damage/2 + random(damage);
		
		target->apply_condition("sanxiao_poison", 10);
		target->receive_wound("hp", damage);
		me->add("mp", -600);

		msg +=  "$n莫名其妙，突然竟然不由自主的也跟着一笑，然后顿时觉得腹中有如一个齿轮在绞！" ;
	} 
	else
	{
	me->start_busy(3);
		me->add("mp", -600);
		msg +=  "可是$p并不上当，轻松躲开，闹得$P自己手忙脚乱。" ;
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}


SKILL_END;


