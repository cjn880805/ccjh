//kuangfeng_jian.h 狂风快剑

SKILL_BEGIN(CSkuangfeng_jian);

virtual void create()
{
	set_name( "狂风快剑");
	set("valid_force", "zixia_shengong");

	Magic_t * magic;

	magic = add_magic("feilong", do_feilong);
	magic->name = "天外飞龙";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  damage, dodge, force, lvl;
	}action[4] = {
		{ "$N纵身跃起手中$w轻挥，斩向$n后颈",
			150, 10, 0, 0,},
		{ "$N手中$w连话三个弧形，向$n的右臂齐肩斩落",
		170, 35, 20, 20,},
		{ "$N轻吁一声，刷刷刷刷四剑，向$n胸，腹，腰，肩四处连刺",
		190, 25, 25, 40,},
		{"$N仰天一声清啸，斜行向前，$w横削直击，迅捷无比，击向$n的$l",
		210, 15, 35, 60,},
	};
 
  	int level = me->query_skill("kuangfeng_jian", 1);
	for(int i = 4; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
    if( DIFFERSTR(me->querystr("family/master_id"), "feng butan"))
		return notify_fail("你无法向此人学习狂风快剑。");
    if (me->query("max_mp") < 300)
        return notify_fail("你的内力不够。");
    if (me->query_skill("force", 1) < 60)
        return notify_fail("你的内功心法火候太浅。");
    if (me->query_skill("dodge", 1) < 60)
        return notify_fail("你的轻功火候太浅。");
    if (me->query_dex() < 25)
        return notify_fail("你的身法还不够灵活。");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("你使用的武器不对。");
    if (me->query("hp") < 30)
        return notify_fail("你的体力不够练狂风快剑。");
    me->receive_damage("hp", 25);
    return 1;
}

static int do_feilong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("「天外飞龙」只能对战斗中的对手使用。");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("装备剑才能使用「天外飞龙」。");
		
	if( me->query_skill("kuangfeng_jian", 1) < 100 )
		return notify_fail("你狂风快剑不够娴熟，使不出「天外飞龙」。");
	                        
	if( me->query_skill("zixia_shengong", 1) < 100 )
		return notify_fail("你紫霞神功火候不够，使不出「天外飞龙」。");
			
	if( me->query("max_mp") < 600 )
		return notify_fail("你内力修为不足，无法运足内力。");

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");

	if (me->query("mp") < 400)
        return notify_fail("你现在内力不够，没能将「天外飞龙」使完！");
			
	 msg = "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n掷了出去，\n";

	 if(target->query_temp("apply/no_天外飞龙")&& (random(2)||target->query("bigboss")))
	 {
		 msg += "可是$n轻轻一笑，侧身伸指，正弹在$N的剑脊上，剑斜飞落地。";
		 me->start_busy(4);
	 }
	 else
	 {
		 if ( random(me->query_combat_exp()) > target->query_combat_exp()/2 )
		 {
			 me->start_busy(2);
			 target->start_busy(random(3));
			 int damage = target->query("hp");
			 if(damage>30000)damage=29000+random(1000);
			 target->receive_damage("hp", damage - 10);
			 target->receive_wound("hp", damage/2);
			 msg += "$n疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！";
			 me->set("mp", 100);
		 } 
		 else
		 {
			 me->start_busy(2);
			 msg += "可是$n轻轻一笑，侧身伸指，正弹在$N的剑脊上，剑斜飞落地。";
		 }
	 }
	 weapon->move(me->environment());
     message_vision(msg.c_str(), me, target);
    
     return 1;
}

SKILL_END;

