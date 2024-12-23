//zhangfapu.h

//Sample for ITEM: 昊天掌法谱
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIzhangfapu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "昊天掌法谱");	//set item name

 	set_weight(1000);		//set item weight

	set("unit", "本");
 	set("long", "这是一本很破旧的书，书里面好象还有一些小人挥舞拳脚的图形。");
	set("value",  0l );
	set("material", "paper");
	set("skill/name","haotian_zhang");	// name of the skill
	set("skill/exp_required",  10000);	// minimum combat experience required
	set("skill/jing_cost",   30);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  80);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp