//liumai_sword.h

//Sample for ITEM: 六脉神剑谱
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIliumai_sword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "六脉神剑谱");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
 	set("long", "这是用来学习六脉神剑的图谱。");
	set("material", "paper");
	set("value",  1000 );
	set("skill/name","liumai_shenjian");	// name of the skill
	set("skill/exp_required",  0l);	// minimum combat experience required
	set("skill/jing_cost",  20+random(20) );	// jing cost every time study this
	set("skill/difficulty",  40);	// the base int to learn this skill
	set("skill/max_skill",  100);	// the maximum level you can learn
	set("skill/min_skill",  0l);  // the maximum level you can learn   
	
	set("no_drop", "这样东西不能离开你。");
    set("no_give", "这样东西不能给人。");

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp