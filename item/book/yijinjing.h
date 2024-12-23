//yijinjing.h

//Sample for ITEM: 易筋经
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIyijinjing);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "易筋经");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "卷");
 	set("long", "易筋经:这是一卷古朴丝织经轴，看来很有年月了，上面文字坚深，不知你识也不识。易筋经是少林镇寺之宝，一直妥藏此处。");
	set("value",  10 );
	set("material", "silk");
	set("skill/name","yijinjing");	// name of the skill
	set("skill/exp_required",  100000);	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  200);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp