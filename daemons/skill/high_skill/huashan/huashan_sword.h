// huashan_sword.h 华山剑法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_sword);

virtual void create()
{
	set_name( "华山剑法");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;
/*
	magic = add_magic("feilong", do_feilong);
	magic->name = "天外飞龙";
	magic->mp = 400;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
	magic = add_magic("jianzhang", do_jianzhang);
	magic->name = "剑掌五连环";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「有凤来仪」，手中$w剑光暴长，向$n的$l刺去", 100, 170,0,"刺伤",},
		{"$N剑随身转，一招「无边落木」罩向$n的$l", -70, 40,20,"刺伤",},
		{"$N舞动$w，一招「鸿飞冥冥」挟著无数剑光刺向$n的$l", -40, 180,40,"刺伤",},
		{"$N手中$w龙吟一声，祭出「平沙落雁」往$n的$l刺出数剑", -40, 80,60,"刺伤",},
		{"$N手中$w剑光暴长，一招「金玉满堂」往$n$l刺去", 60, 240, 80,"刺伤",},
		{"$N手中$w化成一道光弧，直指$n$l，一招「白虹贯日」发出虎哮龙吟刺去", -60, 300, 100,"刺伤",},
	};
 	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_sword", 1))
		{
			int level = random(i);
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
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    CContainer * ob;
    if(  me->query("max_mp") < 50 )
        return notify_fail("你的内力不够，没有办法练华山剑法。");
	if(  DIFFERSTR(me->query_skill_mapped("force"), "zixia_shengong"))
        return notify_fail("华山剑法必须配合紫霞神功才能练。");
    if( !(ob = me->query_weapon())
		||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("你确认你拿的是剑？你拿的难道真的是剑吗？");
	
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30  ||  me->query("mp") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"你按著所学练了一遍华山剑法。", "practice");
    return 1;
}

//perform 
/*
static int do_feilong(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("装备剑才能使用「天外飞龙」？" );

	if (!target || !me->is_fighting(target) )
		return notify_fail("「天外飞龙」只能对战斗中的对手使用。");
	
	if ( me->query_skill("huashan_sword", 1) < 150 )
		return notify_fail("你华山剑法不够娴熟，使不出「天外飞龙」。" );
	
	if ( me->query_skill("huashan_neigong", 1) < 100 )
		return notify_fail("你华山内功火候不够，使不出「天外飞龙」。" );
	
	if ( me->query_skill("zixia_shengong", 1) < 100 )
		return notify_fail("你紫霞神功火候不够，使不出「天外飞龙」。" );

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if ( me->query("max_mp") < 600)
		return notify_fail("你内力修为不足，无法运足内力。" );
	
	if ( me->query("mp") < 400)
	{
		return notify_fail( "你现在内力不够，没能将「天外飞龙」使完！" );
	}
	msg =  "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n掷了出去，\n" ;
	if ( random(me->query_combat_exp()) >  target->query_combat_exp()/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		int damage = target->query("hp");
		target->receive_damage("hp", damage-10);
		target->receive_wound("hp", damage/2);
		msg +=  "$n疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！" ;
		me->set("mp", 100);
	} else
	{
		me->start_busy(2);
		msg += "可是$n轻轻一笑，侧身伸指，正弹在$N的剑脊上，剑斜飞落地。" ;
		me->add("mp", -200);
	}
	weapon->move(me->environment());
	message_vision(msg.c_str(), me, target);
//	if(!target->is_fighting(me)) target->kill_ob(me);
	return 1;
	
}*/

static int do_jianzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	string msg;
	char msg1[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(!target || !me->is_fighting(target) )
		return notify_fail("「剑掌五连环」只能在战斗中使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你拿的是剑吗？你确认你拿的是剑？难道你拿的真的是剑？");

	if( DIFFERSTR(me->query_skill_mapped("sword"), "huashan_sword"))
		return notify_fail("必须配合华山剑法使用。");
	
	if(  me->query("mp") < 150 )
		return notify_fail("你的真气不够！");

	if(DIFFERSTR(me->querystr("family/family_name"), "华山派") && me->querymap_temp("biwu"))
	return notify_fail("师傅交代过，在此次比武中不能使用非本门武功。");
	
	if(  me->query_skill("zixia_shengong",1) < 50 )
		return notify_fail("你的紫霞神功不够！");
	
	if(  me->query_skill("sword",1) < 50 ||
		DIFFERSTR(me->query_skill_mapped("sword"), "huashan_sword"))
		return notify_fail("你的华山剑法还不到家，无法使用剑掌五连环！");
	
	me->add("mp", -150);

	message_vision("\n\n$HIY$N使出华山派绝技「剑掌五连环」，身法陡然加快！", me);

	if(target->query_temp("apply/no_剑掌五连环")&& !random(2))
	{
		return notify_fail(snprintf(msg1, 255,"可是%s看破了%s的企图，抢先下手制住了%s的连续后招。\n",target->name(),me->name(),me->name()));
	}
	else
	{
		me->call_out(lianhuan, 1, target->object_id(), 1);
	}
		return 10;

}

static void lianhuan(CContainer * ob, LONG param1, LONG time)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);

	if(! target || ! me->is_fighting(target)) return;
	
	g_Combatd.Do_Attack(me, target, CCombatd::TYPE_REGULAR);
	
	if(time < 5) 
		me->call_out(lianhuan, 1, param1, time + 1);
	else
		me->start_busy(3 + random(3));
}

SKILL_END;




