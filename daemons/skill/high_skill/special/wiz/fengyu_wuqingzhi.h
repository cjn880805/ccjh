// fengyu_wuqingzhi.h 風雨無情指
//code by Teapot
//date : 2001-04-20

SKILL_BEGIN(CSfengyu_wuqingzhi);

virtual void create()
{
	set_name( "風雨無情指");

	Magic_t * magic;

	magic = add_magic("rain", do_rain);
	magic->name = "風雨如晦";
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
		{"$N使一招「春风乍起」，一指不知所來，不知所去的攻出！", 100, 10, 0, "瘀伤",},
		{"$N神光乍斂，一招「细雨绵绵」，指風無孔不入的攻向$n！", 150, 15, 20, "内伤",},
		{"$N縱身爾起，淩空虛踏，隻見漫天指影覆下，正是「疾風驟雨」！", 200, 20, 40, "内伤",},
		{"$N輕輕一嘆，二指連彈，一式「風雨流星」直取$n！", 250, 35, 60, "内伤",},
		{"$N化指为劍，一式「清風細雨溫柔劍」綿綿密密的攻出！", 300,30 , 80, "内伤",},
		{"$N清喝一聲，轉身輕彈一指，好一招「垂簾臥聽風吹雨」！", 350,35 , 100, "内伤",},
	 	{"$N使出風雨無情指中的「常怨風雨總無邊」，十指連綿不絕彈出，完全将$n笼罩在指風之下！", 400, 20, 120, "内伤",},
		{"$N使出「秋風秋雨總無情」，你隻覺得氣為之窒，但見漫天風雨，無所不在、無所不出、無所不向的飛灑爾出！", 700, -80, 150, "劈伤",},
	};

	int level = me->query_skill("fengyu_wuqingzhi", 1);
	
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

	if (me->query_temp("teapot/perform_fengyuruhui"))
	{
			me->delete_temp("teapot/perform_fengyuruhui");
			m_actions.set("action", "$N收心斂意，風雨無情指絕學驟然發出!\n只見天地陰沉，狂風怒卷，大雨如注，轉瞬蓋住了整個世界，突然驚雷乍起，一指如電襲向$n，好一招「風雨如晦」！！！");
			m_actions.set("force", 1200);
			m_actions.set("damage", 0l);
	}

	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
		return notify_fail("學風雨無情指必須空手。");

    if (DIFFERSTR(me->querystr("gender"), "女性")  )
		return notify_fail("學風雨無情指必須女性。");

    if ( me->query("max_mp") > 1000)
		return notify_fail("你的内力太强，无法练風雨無情指。");

    return 1;
	
}

int practice_skill(CChar * me)
{
    if ( me->query("mp") > 0)
		return notify_fail("你的内力太强不能練風雨無情指。");

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
		return notify_fail("風雨如晦只能對戰鬥中的對手使用。");
	
	if(  me->query_skill("fengyu_wuqingzhi", 1) < 160 )
		return notify_fail("你的風雨無情指等級不足，不能使出「風雨如晦」。");

	if( me->query("mp") < 1000)	
		return notify_fail("你的内力不足。");
	me->add("mp",-1000);	
	me->set_temp("teapot/perform_fengyuruhui",1);
	g_Combatd.Do_Attack(me,target, g_Combatd.TYPE_REGULAR);
	me->start_busy(3);
	return 1;
}



SKILL_END;


