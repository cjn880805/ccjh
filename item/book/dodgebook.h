//dodgebook.h

//Sample for ITEM: 轻功篇
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIdodgebook);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "轻功篇");	//set item name

 	set_weight(100);		//set item weight

	set("unit", "本");
	set("long", "这是一本还施水阁的轻功藏本，书色泛黄，有不少的批注。");
	set("value", 500);
	set("material", "paper");
	set("skill/name","dodge");	// name of the skill
	set("skill/exp_required",10000);	// minimum combat experience required
	set("skill/jing_cost",1);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",100);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp