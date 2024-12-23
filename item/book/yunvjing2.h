//yunvjing2.h

//Sample for ITEM: 玉女心经下册
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIyunvjing2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "玉女心经下册");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "本");
 	set("long", "这是一本写在薄绢上的书。封面上写着 玉女心经「下」。");
	set("value",  0l );
	set("material", "silk");
	set("skill/name","yunv_xinfa");	// name of the skill
	set("skill/exp_required",  65000);	// minimum combat experience required
	set("skill/jing_cost",   42);	// jing cost every time study this
	set("skill/difficulty", 32 );	// the base int to learn this skill
	set("skill/max_skill",  100);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp