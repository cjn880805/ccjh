
// duoming_jinhua.h 夺命金花
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSduoming_jinhua);

virtual void create()
{
	set_name( "夺命银花");

	Magic_t * magic;

	magic = add_magic("huayu", do_muye);
	magic->name = "满天花雨";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenghuo_shengong") || EQUALSTR(arg, "jiuyang_shengong"))
		return 1;

	return notify_fail("夺命银花必须与圣火神功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N虚步提腰，一招「银光灿烂」，手中$w射向$n的$l", 60, 20, 10, 45, 0, "挫伤",},
		{"$N向前跨上一步，左手虚晃，右手$w使出一式「满天花雨」直设$n的$l", 70, 25, 20, 60, 10, "挫伤",},
		{"$N身形往右一挫，左手显然多了一把$w，使出一式「满天星」射向$n的$l", 80, 30, 30,70 , 20, "刺伤",},
		{"$N双膝下沉，右手$w使出一式「风花雪月」，由下而上疾射$n的$l", 90, 45, 40, 80, 30, "刺伤",},
		{"$N一招「香飘万里」，$w自空中划出一个大弧，平平地向$n的$l直射过去", 100, 55, 55, 90, 40, "挫伤",},
		{"$N纵身一跃，离地两丈，一招「天女散花」，手中$w化作点点寒星$n的$l疾射过去", 110, 65, 75,100 ,50 , "刺伤",},
		{"$N两个转身，手中$w一闪，一招「断肠花」射向$n的$l", 130, 100, 100, 120,80 , "刺伤",},
		{"$N一招「夺命银花」，$w化作满天飞雨，罩地挥向$n的全身", 200, 200, 200,150 ,100 , "刺伤",},
	};
  		
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("duoming_jinhua", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
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
	return (usage == "throwing") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( me->query("max_mp") < 200)
		return notify_fail("你的内力不够。");
	if ( me->query_skill("throwing", 1) < 20)
		return notify_fail("你的暗器功夫火候太浅。");
	if ( me->query_skill("shenghuo_shengong", 1) < 50)
		return notify_fail("你的圣火神功火候太浅。");
	return 1;

}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
	||  DIFFERSTR(weapon->querystr("skill_type"), "throwing"))
		return notify_fail("你使用的武器不对。");
	if ( me->query("hp") < 50)
		return notify_fail("你的体力不够练夺命银花。");
	me->receive_damage("hp", 30);
	return 1;

}
//perform 
static int do_muye(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");
	
	if( me->query_skill("throwing",1) < 100)
		return notify_fail("你的暗器功夫太差，无法同时放出多件暗器。");

	if( !( weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "throwing") )
		return notify_fail("没有暗器，怎么使得出满天花雨。");

	if( me->query_skill("duoming_jinhua",1) < 120)
		return notify_fail("你的夺命银花功修为不够,目前还不能使用满天花雨！");

	if(DIFFERSTR(me->querystr("family/family_name"), "明教") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if( me->query("mp") < 500)
		return notify_fail("你内力现在不够, 不能使用满天花雨！");
	
	if( target->is_busy() )
		return notify_fail( "%s目前正自顾不暇，放胆攻击吧 ",target->name());
	
	msg =  "$N使出夺命银花绝技「满天花雨」，$n只觉眼前银光灿烂，把$n裹了个严严实实。\n";

	me->add("mp", -150);

	if( random(me->query_combat_exp()) >  target->query_combat_exp() / 4 ) 
	{
		msg += "结果$p被$P攻了个措手不及，立时动弹不得！"  ;
		if(EQUALSTR(weapon->querystr("name"), "夺命银花"))
			target->start_busy(  me->query_skill("duoming_jinhua",1) / 30 + 2);
		else
			target->start_busy(  me->query_skill("duoming_jinhua",1) / 40 + 2);
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
