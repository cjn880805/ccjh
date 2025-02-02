//zhemei_book2.h

//Sample for ITEM: 天山折梅手法图下卷
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIzhemei_book2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "天山折梅手法图下卷");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "幅");
 	set("long", "这是一幅天山折梅手法图，上面画着一些纷繁复杂的招式。");
	set("value",  500 );
	set("material", "paper");
	set("skill/name","zhemei_shou");	// name of the skill
	set("skill/exp_required",  100000);	// minimum combat experience required
	set("skill/jing_cost",   30);	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  149);	// the maximum level you can learn
	set("skill/min_skill", 100 );  // the maximum level you can learn   

	set("no_put", 1);
		

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp