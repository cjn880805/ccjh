//throw_book.h

//Sample for ITEM: 天山器法
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIthrow_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "天山器法");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是一本星宿派武功密籍。");
	set("value",  500 );
	set("material", "paper");
	set("skill/name","feixing_shu");	// name of the skill
	set("skill/exp_required",  1000);	// minimum combat experience required
	set("skill/jing_cost",   20+random(20));	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  99);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp