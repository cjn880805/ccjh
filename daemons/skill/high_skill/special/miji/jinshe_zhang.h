
// jinshe_zhang.h 金蛇游身掌
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_zhang);

virtual void create()
{
	set_name( "金蛇游身掌");

	Magic_t * magic;

	magic = add_magic("fugu", do_fugu);
	magic->name = "附骨缠身";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg [80]= {"$n使出「粘」字诀，双掌一划，引偏了$N的$w。"};
	
	static char unarmed_parry_msg[80] = {"$n施展出金蛇游身掌，轻描淡写的化解了$N的攻势。"};
	
	if( weapon )
		return parry_msg;
	else
		return unarmed_parry_msg;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,damage;
		char damage_type[5];
	}action[] = {
		{"$N双掌一错，一招「千蛇出洞」幻出漫天掌影拢向$n的$l", 30, 10, 50, "瘀伤",},
		{"$N暴喝一声，双掌连环推出，一招「大沼龙蛇」强劲的掌风直扑$n的$l", 30, 10, 50, "瘀伤",},
		{"$N双掌纷飞，一招「双蛇抢珠」直取$n的$l",10 , 30, 30, "瘀伤",},
		{"$N提气缠身游走，一招「游走式」，森森掌风无孔不入般地击向$n的$l", 10, 50, 70, "瘀伤",},
		{"$N盘身错步，双掌平推，凝神聚气，一招「盘身式」拍向$n的$l", 30, 70, 30, "瘀伤",},
		{"$N左掌立于胸前，右掌推出，一招「金蛇吐衅」击向$n$l", 30,70 , 30, "瘀伤",},
		{"$N使出「金蛇翻身咬」，身形凌空飞起，从空中当头向$n的$l出掌攻击", 30, 70, 30, "瘀伤",},
		{"$N使出一招「杯弓蛇影」，左掌化虚为实击向$n的$l", 30, 70, 30, "瘀伤",},
		{"$N左掌画了个圈圈，右掌推出，一招「金蛇缠丝手」击向$n$l", 30, 70, 30, "瘀伤",},
		{"$N使出「灵蛇游八方」，身形散作八处同时向$n的$l出掌攻击", 30, 70, 30, "瘀伤",},
		{"$N使出金蛇游身掌法「金蛇探头」，如鬼魅般欺至$n身前，一掌拍向$n的$l", 30, 70, 30, "瘀伤",},
		{"$N内气上提，全身拔起，一招「金龙升天」，双掌凌空拍下，$n的全身都被笼罩在掌力之下", 30, 70, 30, "瘀伤",},
	};
 		
	int level = 0;
	
	for(int i=12; i>0; i--)
	{
		if( (i - 1) * 10 < me->query_skill("jinshe_zhang", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
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
	if(me->query_skill("jinshe_zhang", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	if( me->query_weapon() )
		return notify_fail("练金蛇游身掌必须空手。");
	if(  me->query("max_mp" ) < 500)
		return notify_fail("你的内力不足，无法练金蛇游身掌。");
	return notify_fail("金蛇游身掌没法教授。");
}

virtual int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_zhang", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	if(  me->query("hp") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。");
	if(  me->query("mp") < 5 )
		return notify_fail("你的内力不够了，休息一下再练吧。");
	me->receive_damage("hp", 30);
	me->add("force", -5);
	return 1;
}

//perform 
static int do_fugu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("附骨缠身只能对战斗中的对手使用。");
	
    if( me->query_weapon())
		return notify_fail("你不是空手，不能使用附骨缠身。");
	
    if(  me->query_skill("jinshe_zhang", 1) < 100 )
		return notify_fail("你的金蛇掌不够娴熟，不会使用附骨缠身。");

	
	
    if(  me->query("mp" ) < 300 )
		return notify_fail("你现在内力太弱，不能使用附骨缠身。");
	
    msg = "$N大喝一声，缠身而上左手一探刁住$n手腕，右掌猛下杀手！\n";
    	
    //if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("strike")) > target->query_skill("dodge")/2 )
    {
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		g_Combatd.Do_Attack(me, target, CCombatd::TYPE_QUICK);
		
		me->add("mp", -50);
		me->start_busy(random(2));
		msg +=  "结果$n被$N的左手所制，在「附骨缠身」下，竟然无法还手！" ;
    }
    else
    {
		me->start_busy(3);
		msg +=  "可是$p识破了$P这一招，手肘一送，摆脱了对方控制。" ;
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
