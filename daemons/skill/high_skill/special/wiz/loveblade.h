// lovesword.h 情深刀
// Coded by Teapot
// Create @ 2001-02-20
// Last Modify @ 2001-03-10


SKILL_BEGIN(CSloveblade);

virtual void create()
{
	set_name( "情深刀");

/*	Magic_t * magic;

	magic = add_magic("crazy", do_crazy);
	magic->name = "威喝斩";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("suicidal", do_suicidal);
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
	}action[4] = {
		{"$n低头向$N幽幽的道：难道……你到现在还不明白我的心意？", -3000,-100,-100,-3000,0,},
		{"$n泪流满面扑向$N,悲声道：你……终于回来了……", -3000,-100,-100,-3000,0,},
		{"$n羞红着脸对$N说：你要你就说嘛……你不说人家怎么知道你要……", -3000,-100,-100,-3000,0,},
		{"$n对$N道：我这一去，只怕从此不再相见，只盼咱们死了以后能够葬在一起…… ", -3000,-100,-100,-3000,0,},
	};
	int level;
	level=random(4);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("damage", action[level].damage);

	return & m_actions;
};

const char * query_parry_msg(CContainer *weapon)
{
	static char parry_msg[6][255] ={
		"$n脸上突然浮现出一片哀怜，看得$N不忍再下手。",
		"$n低头轻叹一声，不闪不避，$N一愣，默默停手。",
		"$n慢慢向$N怀中倒去，$N只能停手来接。",
		"$n道：好，好，你……你欺负我！，说话间眼圈已经红了，$N一愣，停手不攻。",
		"$n轻轻吟道：一夜夫妻百日恩，百夜夫妻海样深……$N听得心中一阵伤感，不由停下招式。",
		"$n什么也不说，两道清澈如水的目光看着$N，$N心中千回百转，念起$n过去的好来。",
	};

	return parry_msg[random(6)];
}

virtual int valid_enable(string usage) { return usage=="blade" || usage == "parry" ; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return 0;
}

/*
static int do_crazy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target ||! me->is_fighting(target) )
		return notify_fail("威喝斩只能对战斗中的对手使用。");

	if( !target->Query(IS_LIVING))
		return notify_fail("现在没有必要使用威喝斩，反正也看不见。");

	 if (me->is_busy() || me->query_temp("pending/exercising"))
	   return notify_fail("你现在正忙着呢。");

	if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");	// frost blade cast only.


	if( me->query("mp") < 500)	
		return notify_fail("你的内力不足以使出威喝斩。");

	int i;
	i=me->query("mp")/2;
	me->add("mp",-i);
	
	message_vision("$N微微一笑，突然间将掌中剑猛然挥出，剑中带着雷鸣之声，登时$n四面八方剑气乱流，地面也划出无数纵横的浅沟！",me,target);

	return 1;
}

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
