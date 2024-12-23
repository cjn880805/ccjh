//qinpu.h

//Sample for ITEM: 黄石谱
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqinpu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "黄石谱");	//set item name

	set_weight(600);		//set item weight

	set("unit", "本");
 	set("long", "这是一本琴谱，你读着读着，似乎可以从里面发现一些其他的东西。原来这是一本藏着剑法的琴谱。 ");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","wuyun_jianfa");	// name of the skill
	set("skill/exp_required",  100);	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  80);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp