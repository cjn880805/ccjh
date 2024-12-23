//yljian.h

//Sample for ITEM: ÔÆÁú½£Æ×
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIyljian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ÔÆÁú½£Æ×");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "±¾");
 	set("long", "ÕâÊÇÒ»±¾½£Æ××Ü¾÷¡£");
	set("value",  5000 );
	set("material", "paper");
	set("skill/name","yunlong_jian");	// name of the skill
	set("skill/exp_required",  10000);	// minimum combat experience required
	set("skill/jing_cost",   20+random(30));	// jing cost every time study this
	set("skill/difficulty", 25 );	// the base int to learn this skill
	set("skill/max_skill",  119);	// the maximum level you can learn
	set("skill/min_skill", 80 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp