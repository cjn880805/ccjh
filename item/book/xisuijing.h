//xisuijing.h

//Sample for ITEM: 洗髓经
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIxisuijing);

//under, we will custom our item
virtual void create(int nFlag = 0)		//Call it when the item is created
{

	set_name( "洗髓经");	//set item name

 	set_weight(100);		//set item weight

	set("unit", "卷");
 	set("long", "这本破纸筒就是少林最高武学典籍，是达摩老祖面壁九年与易筋经一起参悟(canwu)出来的绝世典籍。");
	set("value",  10 );
	set("material", "paper");

};

virtual int do_look(CChar * me)
{
	CItem::do_look(me);
	
	AddMenuItem("参悟", "$9canwu $1", me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "canwu") == 0)
		return do_study(me);

	return 0;
}

int do_study(CChar * me)
{
	char skill[][10] = {
		"whip",
		"finger",
		"hand",
		"cuff",
		"claw",
		"strike",};

	CContainer * where;
	int myskill, cost, i, exp;

	cost=50;
	where = me->environment();
	if (DIFFERSTR(where->querystr("base_name"), "少林寺达摩院二楼"))
		return notify_fail("洗髓经只能在达摩院二楼里参悟！");

	if (!me->query_skill("literate",1)||me->query_skill("literate",1)<100)
	{
		return notify_fail("你把纸筒翻来翻去，就是什么都读不懂。");		
	}
//	if (!me->query_skill("yijinjing",1)||me->query_skill("yijinjing",1)<100)
//	{
//		write("也许是没有融会贯通易筋经，你觉得这洗髓经莫名其妙。\n");
//		return 1;
//	}
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。");
	if (me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！");
	exp = me->query_combat_exp();
	if (exp < 300000)
	{
		return notify_fail("你的等级不够，不能参悟洗髓经。");		
	}

	set("book_verb", "canwu");

	if (me->query("hp")>cost)
	{
		for ( i=6; i>0; i-- )
		{
			myskill=me->query_skill(skill[i-1], 1);
			if ( myskill<180 && myskill>1 && myskill < CChar::level2skill(me->query("level")))
			{
			    me->improve_skill(skill[i-1],(me->query_skill("literate",1)+me->query("int"))/2);
			}
		}
		tell_object(me, "你参悟洗髓经上的经文，似乎有点心得。", "study");
		me->receive_damage("hp", cost );
	}
	else
	{
		return notify_fail("你现在过于疲倦，无法专心下来参悟洗髓经。");
	}

	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp