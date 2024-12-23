//parry_book.h

//Sample for ITEM: 招架入门
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIparry_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "招架入门");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是一本走江湖武师写的关于趋避招架的书籍。");
	set("value",  1500 );
	set("material", "paper");
	set("skill/name","parry");	// name of the skill
	set("skill/exp_required", 1 );	// minimum combat experience required
	set("skill/jing_cost",   10+random(10));	// jing cost every time study this
	set("skill/difficulty", 10 );	// the base int to learn this skill
	set("skill/max_skill", 19 );	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp