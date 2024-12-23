
// sougu.h 搜骨鹰爪功
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSsougu);

virtual void create()
{
	set_name( "搜骨鹰爪功");

	Magic_t * magic;

	magic = add_magic("muye", do_muye);
	magic->name = "牧野鹰扬";
	magic->mp = 800;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("搜骨鹰爪功必须与圣火神功配合使用。");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge;
		char damage_type[5];
		int lvl,damage;
	}action[] = {
		{"$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「推爪式」", 170, 5,"抓伤", 0, 15,},
		{"$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「盖爪式」双爪疾向$n脑后击下", 190, 20,"抓伤", 25, 5,},
		{"$N就地一滚，突然到了$n身前，使一招「掏爪式」，右爪直奔$n小腹", 215, 20,"抓伤", 35, 10,},
		{"$N左爪护胸，右爪凝劲后发，一招「托爪式」，缓缓托向$n的$l", 245, 5,"抓伤", 45, 20,},
		{"$N身形诡异，疾速前扑，使一招「撩爪式」，直撩$n裆部", 280, 25,"抓伤", 55, 35,},
		{"$N身形飘忽，陡然转到$n身后，一招「锁爪式」，双爪直向$n咽喉插下", 320, 35,"抓伤", 65, 60,},
		{"$N一声厉啸，身形拔起，使出「千爪式」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴", 365, 40,"抓伤", 95, 85,},
	};
  		
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("sougu", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "claw") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练搜骨鹰爪功必须空手。");
 	if ( me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法学搜骨鹰爪功。");
	if ( me->query_str() < 27)
		return notify_fail("你的臂力太差，无法学搜骨鹰爪功。");
	if ( me->query_skill("claw", 1) < 50)
		return notify_fail("你的爪功根基不稳，无法学搜骨鹰爪功。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练鹰爪功。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

//perform 
static int do_muye(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");
	
	if( me->query_str() < 30)
		return notify_fail("你臂力不够,不能使用牧野鹰扬！");

	if( me->query_weapon())		//add by lanwood 2000-12-26
		return notify_fail("你不是空手。");

	if( me->query_skill("sougu",1) < 150)
		return notify_fail("你的搜骨鹰爪功修为不够,目前还不能使用牧野鹰扬！");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
		return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 800)
		return notify_fail("你内力现在不够, 不能使用牧野鹰扬！");
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧 ",target->name());
	
	msg =  "$N使出搜骨鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n的全身要穴。\n";

	me->add("mp", -150);

	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 2 ) 
	{
		msg += "结果$p被$P攻了个措手不及，立时动弹不得！"  ;
		target->start_busy(  me->query_skill("sougu",1) / 20 + 1);
	} 
	else 
	{
		msg +=   "可是$p看破了$P的企图，并没有上当。"  ;
		me->start_busy(4);
	}
	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;
