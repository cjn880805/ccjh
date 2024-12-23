//jinchuang_yao.h

//Sample for ITEM 金创药
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjinchuang_yao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金创药");	//set item name

	set("unit", "包");
	set("long", "这是一包别具灵效的少林金创药，专治内外伤等。");
	set("value", 2000);
	set("no_drop", "这样东西不能离开你。");

	set("shaolin",1);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("你现在不需要用金创药。");
		
	if ( me->query_condition("bonze_drug") > 0 )
	{
		me->add("eff_hp", -50);
		message_vision("$N吃下一包金创药，只觉胸口烦恶欲呕，四肢乏力，原来服食太急太多，药效适得其反！", me);
	}
	else
	{
		me->receive_curing("hp", 50);
		message_vision("$N吃下一包金创药，只觉精神振作，气色看起来好多了。", me);
	}
	me->apply_condition("bonze_drug", 15);
    destruct(this);

    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp