//book_stone.h

//Sample for ITEM: 石板
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbook_stone);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char skills[5][10] = {
		"finger",
		"claw",
		"strike",
		"cuff",
		"hand",};

	int lvl = random(5);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

	set_name( "石板");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "块");
	set("long", "易筋经拳法篇:这是一块园园的石板，似乎用手指刻划了数个指印。");
	set("value", 500);
	set("material", "stone");
	set("skill/name",skills[lvl]);	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",20);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp