
// meinv_quan.h 美女拳
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSmeinv_quan);

virtual void create()
{
	set_name( "美女拳");

	Magic_t * magic;

	magic = add_magic("you", do_you);
	magic->name = "古墓幽居";
	magic->mp = 150;
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
		{"$N使一招「红玉击鼓」 ，双臂交互快击", 180, 5, 5,0 ,"内伤",},
		{"$N突然变为「红拂夜奔」，出其不意的叩关直入，令$n大吃一惊", 200, 5,10 ,10 ,"内伤",},
		{"$N招式一变成「绿珠坠楼」，扑地攻敌下盘，委实难测", 230,15 ,15 , 22,"内伤",},
		{"$N双掌连拍数下，接著连绵不断拍出，原来是「文姬归汉」，共胡笳十八拍", 270, 5,30 ,34 ,"内伤",},
		{"$N使出「红线盗盒」，以空手入白刃之技向$n手中兵刃夺去", 320, 10, 40, 48,"内伤",},
		{"$N一式「木兰弯弓」，左手如抱满月，右手疾挥而过，令$n目瞪口呆", 380, 25, 52, 60,"内伤",},
		{"$N忽然昂首如吟明月，双掌从不可思议的角度攻了过来，原来是一招「班姬赋诗」", 350, 15,64 , 71,"内伤",},
		{"$N使招「蛮腰纤纤」，腰肢轻摆避开，紧跟着挥掌攻击$n的前胸",330 ,20 ,80 , 82,"内伤",},
		{"$N五指在自己头发上一梳，跟著软软的挥了出去，脸上微微一笑，却是一招「丽华梳装」。",330 ,20 ,95 , 95,"内伤",},
		{"$N见$n呆住，伸指戳出，却是一招「萍姬针神」。", 330, 20, 111,109 ,"内伤",},
		{"$N突然间蹙起眉头，宛如「西子捧心」，双掌自自己胸口攻出", 330, 20, 124, 129,"内伤",},
		{"$N脚下翩若惊鸦、矫若游龙，犹如在水上漂行一般，却是一招「洛神微步」", 330, 20, 150, 149,"内伤",},
		{"$N使招「曹令割鼻」，挥手在自己脸上斜削一掌，左掌削过，右掌又削，连绵不断",330 , 20, 180,179 ,"内伤",},
	};
	
	int level = 0;
	
	for(int i=13; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("meinv_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "yunv_xinfa") || EQUALSTR(arg, "seaforce")|| EQUALSTR(arg, "yunv_xinjing"))
		return 1;

	return 0;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练美女拳必须空手。");
	if (me->query_skill("yunv_xinfa", 1) < 10)
		return notify_fail("你的玉女心法火候不够，无法学美女拳。");
	if (me->query("max_mp") < 30)
		return notify_fail("你的内力太弱，无法学习美女拳。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太差了，不能练习美女拳。");
	me->receive_damage("hp", 25);
	return 1;
}

//perform 
static int do_you(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("古墓幽居只能对战斗中的对手使用。");
	
    if( me->query_weapon() )
		return notify_fail("你必须先放下手中的兵器！");
	
    if( me->query_skill("meinv_quan", 1) < 50 )
		return notify_fail("你的美女拳级别不够，不会使用古墓幽居。");
	
    if( me->query_skill("yunv_xinfa", 1) < 40 )
		return notify_fail("你的玉女心法还未娴熟，不能利用神功伤敌。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( me->query("mp") < 150 )
		return notify_fail("你现在内力太弱，不能使用古墓幽居。");
	
    msg =  "$N右手支颐，左袖轻轻挥出，长叹一声，使出「古墓幽居」，脸现寂寥之意。\n";
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(random(3));
		int damage = me->query_skill("yunv_xinfa", 1) + me->query_skill("meinv_quan",1);
		//(玉女心法+美女拳级别)/2
		damage=damage/2;
		damage = damage/2 + random(damage/2) + random(damage/4);
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		target->start_busy(3);
		me->add("mp", -100);
		
		if( damage < 30 )
			msg += "结果$n被$N袍袖一拂，闷哼一声。";
		else if( damage < 55 )
			msg += "结果$n被$N以袍袖一拂，「腾腾」地退出几步。";
		else if( damage < 80 )
			msg += "结果$n被$N以袍袖一拂，胸口有如受到一记重锤，气血为之一窒！";
		else
			msg += "结果$n被$N的袍袖一拂，眼前一黑，浑身气血翻腾，竟如身入洪炉一般！";
    }
    else
    {
		me->start_busy(3);
		msg += "可是$p看破了$P的企图，依然稳如泰山，抬手一架格开。";
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
