// huashan_jianfa.h 华山剑法
//code by Fisho
//date : 2000-12-06
SKILL_BEGIN(CShuashan_jianfa);

virtual void create()
{
	set_name( "华山剑法");

	Magic_t * magic;

	magic = add_magic("jianzhang", do_jianzhang);
	magic->name = "剑掌五连环";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

/*	magic = add_magic("wushuang", do_wushuang);
	magic->name = "无双无对";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「白云出岫」，手中$w点向$n的$l", 20, 0,"刺伤",},
		{"$N使出「有凤来仪」，$w闪烁不定，刺向$n的$l", 25, 10,"刺伤",},
		{"$N一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去", 30, 20,"刺伤",},
		{"$N向前跨上一步，手中$w使出「白虹贯日」直刺$n的$l", 35, 30,"刺伤",},
		{"$N手中的$w一晃，使出「苍松迎客」直刺$n的$l", 50, 40,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_jianfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
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
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("你的华山内功火候太浅。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练华山剑法。");
	me->receive_damage("hp", 30);
	return 1;
	
}

//perform 
static int do_jianzhang(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("「剑掌五连环」只能在战斗中使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("「剑掌五连环」开始时必须拿着一把剑！");
	
	if( me->query("mp") < 100 )
		return notify_fail("你的真气不够！");
	
	if( me->query_skill("sword") < 50 ||
		DIFFERSTR(me->query_skill_mapped("sword"), "huashan_jianfa"))
		return notify_fail("你的华山剑法还不到家，无法使用剑掌五连环！");
	
	snprintf(msg ,255,"$N使出华山派绝技「剑掌五连环」，身法陡然加快！"  );
	message_vision(msg, me);
	
	
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	Do_Attack(me, target,  TYPE_QUICK);
	
	me->add("mp", -100);
	me->start_busy(random(5));
	
	return 1;
	
}
/*
static int do_wushuang(CChar * me, CContainer * ob)
{
	int skill;
	CChar * target = NULL;
	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。");
	
	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");
	
	if( me->query_skill("huashan_jianfa", 1) < 40 )
		return notify_fail("你的华山剑法不够娴熟，不会使用「无双无对」。");
	
	
	if( me->query("mp") < 300  ) 
		return notify_fail("你的内力不够。");
	
	if(  me->query_temp("hsj_wu") ) 
		return notify_fail("你已经在运功中了。");
	
	snprintf(msg ,255,"$N双手握起%s，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$P冲刺！" ,weapon->name() );
	message_vision(msg, me, target);
	
	skill =  me->query_skill("huashan_jianfa",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);
	
	me->call_out( remove_effect, 2, skill/3, skill/4);
	
	me->add("mp", -100);
 	return 1;
}

static void remove_effect(CContainer *ob, LONG a_amount, LONG d_amount)
{
	CChar *me = (CChar *)ob;
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("hsj_wu");

	me->SendState(me);
	me->start_busy(4);
}
*/
SKILL_END;
