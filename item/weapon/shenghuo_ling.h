//shenghuo_ling.h

//Sample for ITEM: 圣火令
//coded by Fisho
//data: 2000-10-30

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshenghuo_ling);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("圣火令", "shenghuo ling");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "把");
 	set("long", "这是一柄两尺来长的黑牌，非金非铁。质地坚硬无比，似透明，令中隐隐似有火焰飞腾，实则是令质映光，颜色变幻。令上刻得有不少波斯文字。");
	set("value",  2000 );
	set("material", "steel");
	set("skill_type", "lingfa");			//set the skill applied
	set("skill/name","shenghuo_lingfa");	// name of the skill
	set("skill/exp_required",  50000);	// minimum combat experience required
	set("skill/jing_cost",   40);	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  200);	// the maximum level you can learn
	set("skill/min_skill", 100 );  // the maximum level you can learn   

	set("wield_msg",  "$N“唰”的一声，从腰间抽出一片黑黝的铁牌握在手中。");
    set("unwield_msg",  "$N将圣火令插回腰间。" );
//    init_sword(50);
 	set("apply/damage", 50);					//set the modifiers of attribute
   
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp