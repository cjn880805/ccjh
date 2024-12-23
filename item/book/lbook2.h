//lbook2.h

//Sample for ITEM: 百家姓
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlbook2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "百家姓");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "本");
 	set("long", "读书人必读的百家姓。");
	set("value",   100000);
	set("material", "paper");
	set("skill/name","literate");	// name of the skill
	set("skill/exp_required", 100 );	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty", 15 );	// the base int to learn this skill
	set("skill/max_skill",  79);	// the maximum level you can learn
	set("skill/min_skill",  50);  // the maximum level you can learn   
	
 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp