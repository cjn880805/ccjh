
// jinshe_zhui.h 金蛇锥法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSjinshe_zhui);

virtual void create()
{
	set_name( "金蛇锥法");
	
	Magic_t * magic;
	
	magic = add_magic("tuwu", do_tuwu);
	magic->name = "金蛇吐雾";
	magic->mp = 300;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)		//2001-07-23	sound降低一次攻击力
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force,damage;
		char damage_type[5];
	}action[] = {
		{"$N双手一晃，一招「千变万化」，手中的$w幻出万道金光，如一条金龙般飞向$n的$l", -20, 200, 250, "刺伤",},
		{"$N右手一抖，一道金光冒出，只一刹那间，左手$w迅雷般越过右手的$w，正是一招「奇诡莫测」，抢先飞向$n的$l", -40, 200, 300, "刺伤",},
	};
	
	int	level = random(2);
	m_actions.set("action", action[level].action);
	m_actions.set("damage", action[level].damage);
	m_actions.set("force", action[level].force);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "throwing")  ;
}

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("jinshe_zhui", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	CContainer * ob;
	
	if(  me->query("max_mp") < 500 )
		return notify_fail("你的内力不够，没有办法练金蛇锥法。");
	
	if( !(ob = me->query_weapon())
        ||       DIFFERSTR(ob->querystr("skill_type"), "throwing") )
		return notify_fail("你必须先找一些暗器才能练金蛇锥法。");
	
	return notify_fail("金蛇锥法没法教授。");
}

virtual int practice_skill(CChar * me)
{
	if(me->query_skill("jinshe_zhui", 1) < 200)
		return notify_fail("你的修为太浅,无法领会其中奥义!");

	if(  me->query("hp") < 30
        ||       me->query("mp") < 500 )
		return 	notify_fail("你的内力或气不够，没有办法练习金蛇锥法。");
	me->receive_damage("hp", 30);
	me->add("mp", -30);
	tell_object(me,"你按著所学练了一遍金蛇锥法。", "practice");
	return 1;
}

//perform 
static int do_tuwu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	CContainer * weapon;
	int skill;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;
	
	if (me->query_temp("jinshe/tuwu"))
		return notify_fail("你才用的金蛇吐雾，没法接着就出招。");
	
	if( !target	||	!me->is_fighting(target) )
		return notify_fail("金蛇吐雾只能在战斗中使用。");
	
    if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("id"), "jinshe_zhui"))
		return notify_fail("你没用金蛇锥，不能使用绝招！");
	
	if(  me->query_skill("jinshe_zhui", 1) < 100 )
		return notify_fail("你的金蛇锥法不够娴熟，不会使用金蛇吐雾。");
	
	if(  me->query("mp") < 300 )
		return notify_fail("你内力不够了。");
	
	skill = me->query_skill("jinshe_zhui", 1);
	
	me->add("mp", -200);
	target->receive_damage("hp",  skill/ 3);
	
	message_vision(	"只听一阵狂风扫叶般的声响中，$N手中的金蛇锥闪出夺目的光芒，闪耀得$n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！"  , me, target);
	me->set_temp("jinshe/tuwu", 1);
	target->set_temp("block_msg/all",1);
	me->call_out(tuwu_end, skill/30, target->object_id() );
	
//	call_out("tuwu_end",   skill/30, me, target);
	
	return 1;
}

static void tuwu_end(CContainer * ob, LONG nTarget, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(nTarget);
	
	if(! target) return;
	
	target->enable_player();
	message_vision("$N抹了抹满脸的鲜血，终于睁开了眼。", target);
	target->set_temp("block_msg/all", 0l);
	tell_object( me,"你终于抹掉了满脸的鲜血，看到了周围的情景。" );
	me->delete_temp("jinshe/tuwu");
	return;
}

SKILL_END;
