// jieyubian.h 解語鞭法
//code by Teapot
//date : 2001-04-23

SKILL_BEGIN(CSjieyu_bian);

virtual void create()
{
	set_name( "解語鞭法");

	Magic_t * magic;

	magic = add_magic("rain", do_rain);
	magic->name = "亂紅飛過秋千去";
	magic->mp = 200;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;


}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「比花解語」，$w纏纏綿綿的抖向$n！", 0, -10, 0, "瘀伤",},
		{"$N神光乍斂，一招「柔情似水」，$w如同無邊溫柔，向$n覆去！", 0, -15, 20, "内伤",},
		{"$N縱身爾起，淩空虛踏，自$n身邊掠過，巧笑聲中回身一鞭，正是「竹馬青梅」！", 0, -20, 40, "内伤",},
		{"$N輕輕一嘆，將鞭一抖，一式「兩小無猜」直取$n！", 0, -35, 60, "内伤",},
		{"$N化鞭为劍，一式「情海无涯」綿綿密密的攻出！", 0,-40 , 80, "内伤",},
		{"$N清喝一聲，轉身輕揮$w，好一招「朝朝暮暮」！", 0,-50 , 100, "内伤",},
	 	{"$N使出「两情相悦」，一收$w，$n身不由己的撞向$w！", 0, -60, 120, "内伤",},
		{"$N使出「佳期如梦」，你隻覺得氣為之窒，但見漫天花雨，無所不在、無所不出、無所不向的飛灑爾出！", 600, -80, 150, "劈伤",},
	};

	int level = me->query_skill("jieyu_bian", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}


	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "whip");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("學解語鞭法必須心無雜念。");
	if(me->querymap("couple")) 
		return notify_fail("學解語鞭法必須心無雜念。");
//    if (DIFFERSTR(me->querystr("gender"), "女性")  )
//		return notify_fail("學解語鞭法必須心無雜念。");
    if ( me->query("max_mp") < 5000)
		return notify_fail("你的内力太強，无法练解語鞭法。");
    return 1;
	
}

virtual int practice_skill(CChar * me)
{
    if ( me->query("mp") > 0)
		return notify_fail("你的内力不夠練解語鞭法。");
    me->add("mp", 1);
	return 1;
	
}


//perform 
static int do_rain(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("亂紅飛過秋千去只能對戰鬥中的對手使用。");
	
	if(  me->query_skill("jieyu_bian", 1) < 20+me->query("level")*4 )
		return notify_fail("你的解語鞭法等級不足，不能使出「亂紅飛過秋千去」。");

	if( me->query("mp") < 1000)	
		return notify_fail("你的内力不足。");
	me->add("mp",-1000);	


	message_vision("$HIG$N轉身輕踏數步，一招隨手爾出，只見漫天花影，紛紛揚揚的灑向$n……",me,target);

	if(random(me->query("max_mp"))> random(target->query("mp") +  target->query_skill("dodge") * 10 + 1)) 
	{
		message_vision("$HIY$n沉醉於美景之中，不防閒已然中招！",me,target);
		target->receive_damage("hp", (2*random(me->query("max_mp")/2)+1) );
	}
	else
	{
		message_vision("$HIG$n身形一蕩，慢慢的滑過花雨，好美的配合，好美的「亂紅飛過秋千去」！",me,target);
		me->start_busy(4);
	}

	return 1;
}

SKILL_END;


