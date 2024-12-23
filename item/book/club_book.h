//parry_book.h

//Sample for ITEM: 招架入门
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIclub_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "《剑经》");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这本书是俞大猷所写，书名是剑经，但是记载的却是棍法。");
	set("value",  15000 );
	set("material", "paper");
	set("skill/name","club");	// name of the skill
	set("skill/exp_required", 1 );	// minimum combat experience required
	set("skill/jing_cost",   10+random(10));	// jing cost every time study this
	set("skill/difficulty", 10 );	// the base int to learn this skill
	set("skill/max_skill", 100 );	// the maximum level you can learn
	set("skill/min_skill", 25 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp