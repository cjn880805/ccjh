//fojing201.h

//Sample for ITEM: 佛经
//coded by Fisho
//data: 2000-11-20

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIfojing201);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char titles[][30] = {
//      "般若经",
//      "维摩经",
//      "法华经",
//      "华严经",
        "无量寿经",
        "大般涅磐经",
        "阿含经",
        "金刚经",
        "波罗蜜多心经",
	};

	set_name( titles[random(5)]);	//set item name

	set_weight(200);		//set item weight

	set("unit", "本");
	set("value", 500);
	set("long", "这是一册佛经。");
	set("material", "paper");
	set("skill/name", "buddhism");
	set("skill/exp_required", 0l);
	set("skill/jing_cost", 20);
	set("skill/difficulty", 20);
	set("skill/max_skill",100 );
	
};
/**********************

int do_tear(string arg)
{
	object me, bible;
	object where;

	if ( !arg )
	{
		return notify_fail("什么？\n");
	}

	me = this_player();

	if ( arg == "hp" || arg == "shu" || arg == "book" )
	{
		bible = new(CLASS_D("shaolin")+"/obj/book-jiuyang");
		where = environment(me);
		message_vision("$N轻轻地把书撕掉……，突然从书缝中飘落出几页羊皮纸。\n",
			this_player());
		bible->move(file_name(where));
		destruct(this_object());
	}

	return 1;
}
****************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp