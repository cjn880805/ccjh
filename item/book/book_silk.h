//book_silk.h

//Sample for ITEM: 薄绢
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbook_silk);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "薄绢");	//set item name

 	set_weight(50);		//set item weight

	set("unit", "束");
	set("long", "这是小册易筋经修行篇:由一束薄绢钉成，里面密密麻麻的画了不少打坐吐呐的姿势。");
	set("value", 500);
	set("material", "silk");
	set("skill/name","force");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",10);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp