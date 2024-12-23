//qunxing_tu.h

//Sample for ITEM: 群星璀璨图
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqunxing_tu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "群星璀璨图");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "本");
 	set("long", "这是一本描写着天上群星运动的书。但似乎并没有那么简单。");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","array");	// name of the skill
	set("skill/exp_required",  100);	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  120);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp