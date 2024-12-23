//dujing_2.h

//Sample for ITEM: ¡ºÐÇËÞ¶¾¾­¡¼ÏÂ²á¡½¡»
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIdujing_2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¡ºÐÇËÞ¶¾¾­¡¼ÏÂ²á¡½¡»");	//set item name

 	set_weight(10);		//set item weight

	set("unit", "±¾");
	set("long", "¡ºÐÇËÞ¶¾¾­¡¼ÏÂ²á¡½¡»");
	set("value", 50);
	set("material", "paper");
	set("skill/name","poison");	// name of the skill
	set("skill/exp_required",50000);	// minimum combat experience required
	set("skill/jing_cost",20);	// jing cost every time study this
	set("skill/difficulty",25);	// the base int to learn this skill
	set("skill/max_skill",199);	// the maximum level you can learn
	set("skill/min_skill",99);  // the maximum level you can learn


 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp