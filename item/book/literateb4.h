//literateb4.h

//Sample for ITEM: 论语
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIliterateb4);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "论语", "lun yu");	//set item name

	set_weight(300);		//set item weight

	set("unit", "本");
 	set("long", "一本孔夫子的《论语》。");
	set("value",  400 );
	set("material", "paper");
	set("skill/name","literate");	// name of the skill
	set("skill/exp_required", 10 );	// minimum combat experience required
	set("skill/jing_cost",  10 );	// jing cost every time study this
	set("skill/difficulty",  25);	// the base int to learn this skill
	set("skill/max_skill",  120);	// the maximum level you can learn
	set("skill/min_skill",  110);  // the maximum level you can learn   
	
  
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp