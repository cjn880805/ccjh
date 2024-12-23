//mizong_book.h

//Sample for ITEM: 密宗心经
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CImizong_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "密宗心经");	//set item name


	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是一册密宗心经,记载着佛学的要旨。");
	set("value",  0l );
	set("material", "paper");
	set("skill/name","mizong_xinfa");	// name of the skill
	set("skill/exp_required",  0l);	// minimum combat experience required
	set("skill/jing_cost",   30+random(20));	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  99);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp