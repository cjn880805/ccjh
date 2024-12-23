//liuyang_book1.h

//Sample for ITEM: 天山六阳掌法图上册
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIliuyang_book1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "天山六阳掌法图上册");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是六阳掌法下册，上面画着一些纷繁复杂的招式及修练法门。");
	set("material", "paper");
	set("value",   500);
	set("skill/name","liuyang_zhang");	// name of the skill
	set("skill/exp_required",  100000);	// minimum combat experience required
	set("skill/jing_cost",   20);	// jing cost every time study this
	set("skill/difficulty",  20);	// the base int to learn this skill
	set("skill/max_skill",  49);	// the maximum level you can learn
	set("skill/min_skill",  10);  // the maximum level you can learn   
	
	set("no_put", 1);


};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp