// doggiestrike.h 戏花掌
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-03-10


SKILL_BEGIN(CSdoggiestrike);

virtual void create()
{
	set_name( "戏花掌");

	Magic_t * magic;

	magic = add_magic("crazy", do_crazy);
	magic->name = "戏花绝唱";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

/*	magic = add_magic("suicidal", do_suicidal);
	magic->name = "这招";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidalb", do_suicidalb);
	magic->name = "那招";
	magic->mp = 0;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
*/
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[6] = {
		{"$N缓缓伸出手去，在$n的脸上轻轻的摸了一把，唱道：“妹妹一笑似盛放娇花，叫一声宝贝你好吗？", -3000,-100,-100,-3000,0,},
		{"$N轻轻抚着$n的秀发，在$n的耳边唱道：“多一串痴情多一串泪，谁爱上我累了谁……”", -3000,-100,-100,-3000,0,},
		{"$N两指成钳，在$n的大腿上捏了一把，唱道：“何地神仙把剑绕，遗下霜雪知多少……”", -3000,-100,-100,-3000,0,},
		{"$N低低的叹了口气，道：多情自古空余恨，此恨绵绵无绝期……$n，你想的我好苦啊……", -3000,-100,-100,-3000,0,},
		{"$N道：$n在吗？天下最遥远的距离不是生死离别，也不是相隔万里，而是你就在我面前，却不知道我爱你……", -3000,-100,-100,-3000,0,},
		{"$N温柔的亲了一口$n，温柔的又亲了一口$n，温柔的再亲了一口$n……", -3000,-100,-100,-3000,0,},
	};
	int level;
	level=random(6);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);

	if (me->query_temp("teapot/maddog"))
	{
		m_actions.set("action", "$N看着低头坐在床边的$n，漫声唱到：妹妹你坐床头，哥哥在边上瞅，……\n只听得$n一声惨叫！");
		m_actions.set("force", 10000);
		m_actions.set("damage", 10000);
	}
		

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="unarmed" ; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}


static int do_crazy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("戏花绝唱只能对战斗中的对手使用。");

	if( !target->Query(IS_LIVING))
		return notify_fail("现在没有必要使用戏花绝唱，反正也看不见。");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if( me->query("mp") > 500)	
		return notify_fail("你的内力不足以使出戏花绝唱。");

	int i;
	i=me->query("hp")/2;
	me->add("mp",i);
	
	me->set_temp("teapot/maddog",1);

	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_QUICK);

	me->delete_temp("teapot/maddog");
	return 1;
}
/*
static int do_suicidal(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("这招只能对战斗中的对手使用。");

	if( !target->Query(IS_LIVING))
		return notify_fail("现在没有必要使用这招……");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");	// frost blade cast only.


	if( me->query("max_mp") < 5000 && !me->query("env/yesiknow") )
		return notify_fail("你的内力不足以使出这招。");

//	int i;
//	i=me->query("mp")/2;
	if( !me->query("env/yesiknow") )
		me->add("max_mp",-5000);

	message_vision("剑气弥漫中。",me);
	message_vision("两人几乎同时出了手，$n的速度好快，但$N是$N，$N躲开了。",target,me);
	message_vision("但$N不能这样下去了，$N的真气不多了，$N终于使出了这招。",target,me);
	message_vision("$n的一只手掉下了地，脸色都没有变，好汉子！",target,me);
	message_vision("$N于是又出了一刀，砍在了$n的脚上。刀光穿过$n的脚。",target,me);
	message_vision("好汉子！$n依然对$N劈出一刀！$n仿佛不是人！",target,me);
	message_vision("$N再次砍下了$n的一只脚。$n依然飞扑过来一刀。",target,me);
	message_vision("$N没有时间再表扬$n是好汉子。$N砍出了八十一刀。每一刀都把$n分成两半！",target,me);
	message_vision("...",target,me);
	message_vision("$N转身离开，风吹过$N的头发。$N的手提着$n的头。",target,me);
	me->receive_damage("hp",1,target);
	me->die();
	message_vision("忽然间，$N发现$N的头离开了身体，$N半空中回头看了一下，原来半空中$n的一只手还拿着刀。。。",target,me);
	message_vision("靠！！！！！！！！！！！ ",target,me);
	target->receive_damage("hp",1,me);
	target->die();

	return 1;
}

static int do_suicidalb(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("那招只能对战斗中的对手使用。");

	if( !target->Query(IS_LIVING))
		return notify_fail("现在没有必要使用那招……");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");	// frost blade cast only.


	if( me->query("max_mp") < 5000)
		return notify_fail("你的内力不足以使出那招。");

//	int i;
//	i=me->query("mp")/2;
	me->add("max_mp",-5000);

	message_vision("剑气弥漫中。",me);
	message_vision("两人几乎同时出了手，$n的速度好快，但$N是$N，$N躲开了。",me,target);
	message_vision("但$N不能这样下去了，$N的真气不多了，$N终于使出了那招。",me,target);
	message_vision("$n的一只手掉下了地，脸色都没有变，好汉子！",me,target);
	message_vision("$N于是又出了一刀，砍在了$n的脚上。刀光穿过$n的脚。",me,target);
	message_vision("好汉子！$n依然对$N劈出一刀！$n仿佛不是人！",me,target);
	message_vision("$N再次砍下了$n的一只脚。$n依然飞扑过来一刀。",me,target);
	message_vision("$N没有时间再表扬$n是好汉子。$N砍出了八十一刀。每一刀都把$n分成两半！",me,target);
	message_vision("...",me,target);
	message_vision("$N转身离开，风吹过$N的头发。$N的手提着$n的头。",me,target);
	target->receive_damage("hp",1,me);
	target->die();
	message_vision("忽然间，$N发现$N的头离开了身体，$N半空中回头看了一下，原来半空中$n剩下的一只手还拿着刀。。。",me,target);
	message_vision("靠！！！！！！！！！！！ ",me,target);
	me->receive_damage("hp",1,target);
	me->die();

	return 1;
}

*/

SKILL_END;
