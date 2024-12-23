//sword_book2.h

//Sample for ITEM: 华山剑谱
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIsword_book2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "华山剑谱2");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "本");
 	set("long", "封面上写著「华山剑法 -- 卷二（进阶）」");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","sword");	// name of the skill
	set("skill/exp_required",  50000);	// minimum combat experience required
	set("skill/jing_cost",   30);	// jing cost every time study this
	set("skill/difficulty", 25 );	// the base int to learn this skill
	set("skill/max_skill",  199);	// the maximum level you can learn
	set("skill/min_skill", 101 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp