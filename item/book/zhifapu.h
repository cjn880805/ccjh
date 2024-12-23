//zhifapu.h

//Sample for ITEM: 一阳指法谱
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIzhifapu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "一阳指法谱");	//set item name

 	set_weight(1000);		//set item weight

	set("unit", "本");
 	set("long", "这是一本写在丝上的书，封面上有一位中年秀士右手中指指向天空的背影。");
	set("value",  0l );
	set("material", "silk");
	set("skill/name","sun_finger");	// name of the skill
	set("skill/exp_required",  150000);	// minimum combat experience required
	set("skill/jing_cost",   35);	// jing cost every time study this
	set("skill/difficulty", 25 );	// the base int to learn this skill
	set("skill/max_skill",  150);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
 
	set("no_give", "这样东西不能随便给人。");
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp