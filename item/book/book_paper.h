//book_paper.h

//Sample for ITEM: 易筋经文学篇
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbook_paper);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "易筋经文学篇");	//set item name

 	set_weight(50);		//set item weight

	set("unit", "本");
	set("long", "这是一本薄薄的小册，上面密密麻麻的写满了蝇头小楷，八股文章。");
	set("value", 500);
	set("material", "silk");
	set("skill/name","literate");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",20);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",19);	// the maximum level you can learn
	set("skill/min_skill",10);  // the maximum level you can learn


};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp