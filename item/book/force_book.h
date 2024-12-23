//force_book.h

//Sample for ITEM: 内功心法
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIforce_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "太极十三势");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "本");
	set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐的姿势。");
	set("value", 500);
	set("material", "paper");
	set("skill/name","force");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",30);	// jing cost every time study this
	set("skill/difficulty",10);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",10);  // the maximum level you can learn


 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp