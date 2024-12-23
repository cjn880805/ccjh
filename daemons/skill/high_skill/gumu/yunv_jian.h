// yunv_jian.h 玉女剑
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_jian);

virtual void create()
{
	set_name( "玉女剑");

	Magic_t * magic;

	magic = add_magic("he", do_he);
	magic->name = "双剑合璧";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「雁行斜击」，身形斜飞，手中$w轻轻点向$n的$l", 60, 20, 10, 35, 0, "刺伤",},
		{"$N长跃而起，「白虹经天」，$w猛然下刺", 70, 15, 10, 40, 4, "刺伤",},
		{"$N使出「浪迹天涯」，挥剑直劈，威不可当", 80, 15, 10, 45,9 , "内伤",},
		{"$N使「花前月下」一招自上而下搏击，模拟冰轮横空、清光铺地的光景", 90, 15, 10, 50, 14, "刺伤",},
		{"$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从何攻来", 100, 15, 15, 55, 19, "内伤",},
		{"$N使出「清饮小酌」剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l", 110, 15, 15, 60,24 , "刺伤",},
		{"$N手中$w由内自外一刺，左手如斟茶壶，使出「扫雪烹茶」来", 120, 10, 15, 65, 29, "刺伤",},
		{"$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招「抚琴按萧」", 130, 15, 15, 70, 34, "刺伤",},
		{"$N一招「松下对弈」，$w自右向左挥一个大弧，刺向$n的$l", 140, 15, 15, 75, 39, "刺伤",},
		{"$N左手如拂五弦，竟以掌为剑攻向$n，却是一招「池边调鹤」", 150, 10, 20, 80, 44, "刺伤",},
		{"$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，向$n的$l挥去", 160, 15, 20, 85, 49, "刺伤",},
		{"$N一招「小园艺菊」，手中$w迅疾向$n的下盘连点三点", 170, 15, 20, 90, 54, "刺伤",},
		{"$N使出「西窗夜话」，手中$w中宫直入，攻向$n的$l", 180, 15, 20, 95, 59, "刺伤",},
		{"$N脚下左高右低，一招「柳荫联句」，$w在空中化成一道光环，急攻$n", 190, 5, 20, 100, 64, "内伤",},
		{"$N手中$w由下而上卷起，犹如打起竹帘一般，却是「竹帘临池」", 200, 15, 20, 105, 70, "刺伤",},
		{"$N做搭弓射箭状，一招「木兰射雁」，右手$w直刺$n的$l", 210, 20, 20, 110, 76, "刺伤",},
		{"$N左手剑诀一领，右手$w平平刺向$n的$l，是一招「双蝶迷回」", 220, 40, 20, 115, 82, "刺伤",},
		{"$N手中$w合身疾刺，一招「孤云出釉」，直指$n的$l", 220, 30, 20, 120, 88, "刺伤",},
		{"$N一招「幽兰空谷」，$w看似随意地一挥，从$n不可思议的角度攻入", 220, 20,25 , 125, 94, "刺伤",},
		{"$N使出「茶花满路」，一时间空中尽是$w的影子，令$n不知如何抵挡", 220, 45, 25, 130, 100, "刺伤",},
		{"$N一招「陌路采桑」，$w连点数点，疾刺$n的$l", 220, 35, 25, 135, 99, "刺伤",},
		{"$N突然盘蹲下来，一招「秋雨萧萧」，$w自下而上刺向$n", 220, 25, 25, 140, 106, "刺伤",},
		{"$N错开脚步，手中$w突然从自己的肋下刺出，却是一招「琴心剑胆」", 220, 35, 25, 145, 112, "刺伤",},
		{"$N犹如在水面滑行一般，一招「池塘秋夜」，平平地向$n的$l挥去", 220, 40, 25, 150, 118, "刺伤",},
		{"$N一招「皓腕玉镯」，手中$w刺点$n的手腕", 220, 45, 25, 155,124 , "刺伤",},
		{"$N一招「牡丹含泪」，$w绕出数个银圈，平平地向$n的$l卷去", 220,45 , 25, 160, 131, "刺伤",},
		{"$N左脚轻点地面，身形往前一扑，一招「芍药蕴珠」，$w向$n的$l刺去", 220, 45, 30, 165, 138, "刺伤",},
		{"$N一招「檐前飞燕」，身形跃起，手中$w扫向$n的$l", 220, 45, 30, 165, 145, "刺伤",},
		{"$N脸现黯然之色，随意一招「蒹葭苍苍」，$w刺向$n的$l", 280, 35, 30,175 , 159, "刺伤",},
	};
	
	int level = 0;
	
	for(int i=29; i > 0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yunv_jian", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("yunv_xinfa", 1) < 15)
		return notify_fail("你的玉女心法火候不到，无法学习玉女剑法。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon()) 
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 45)
		return notify_fail("你的体力不够练玉女剑法。");
	if (me->query("mp") < 15)
		return notify_fail("你的内力不足以练玉女剑法。");
	me->receive_damage("hp", 26);
	return 1;
}

//perform 
static int do_he(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

    if( !target || !me->is_fighting(target) )
		return notify_fail("双剑合璧只能对战斗中的对手使用。");
	
    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if(DIFFERSTR(me->querystr("family/family_name"), "古墓派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
    if( me->query_skill("yunv_xinfa", 1) < 80 )
		return notify_fail("你的玉女心法不够娴熟，不能使用双剑合璧。");
	
    if( me->query_skill("yunv_jian", 1) < 80 )
		return notify_fail("你的玉女剑法不够娴熟，不能使用双剑合璧。");
	
    if( me->query_skill("quanzhen_jian", 1) < 50 )
		return notify_fail("你的全真剑法不够娴熟，不能使用双剑合璧。");
	
    if( me->query("mp") < 400 )
		return notify_fail("你现在内力太弱，不能使用双剑合璧。");
	
    msg =  "$N左手以全真剑法剑意，右手化玉女剑法剑招，双剑合璧同时刺出。\n";
	
    if( !target->is_fighting(me) ) target->kill_ob(me);
	
    if (random(me->query_skill("force")) > target->query_skill("force")/2 )
    {
		me->start_busy(2);
		int damage = me->query_skill("yunv_jian", 1) + me->query_skill("quanzhen_jian",1);
		damage = damage + me->query_skill("force",1) ;
		//(玉女剑法+全真剑法级别+基本内功)
		damage = damage/2 + random(damage);
		target->receive_damage("hp", damage);
		target->start_busy(4);
		me->add("mp", -350);
		msg += "$n看到$N双剑飞舞，招式中所有破绽都为另一剑补去，竟不知如何是好！\n";
        msg += "一呆之下，$N的剑招已经破式而入！";
    }
    else
    {
		me->start_busy(4);
		msg += "可是$p看破了$P的企图，将自己的全身上下护得密不透风，令$P无计可施。";
    }

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
