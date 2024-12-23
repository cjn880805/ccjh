//skin.h

//Sample for ITEM: 羊皮书
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIskin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "羊皮书");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是一张羊皮,上面画着舞剑的小人。");
	set("value",  0l );
	set("material", "paper");
	set("skill/name","sword");	// name of the skill
	set("skill/exp_required",  10000);	// minimum combat experience required
	set("skill/jing_cost",   40);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  149);	// the maximum level you can learn
	set("skill/min_skill", 100 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp