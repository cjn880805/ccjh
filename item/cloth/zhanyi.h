//zhanyi.h

//Sample for ITEM: 血棋衣
//coded by Fisho
//data: 2000-10-30

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIzhanyi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "血棋衣");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(200);		//set item weight

	set("unit", "件");
 	set("long", "一件上面绣有血色棋局的衣服。");
	set("value",  7000 );
	set("material", "cloth");
	set("skill/name","xuantian_zhi");	// name of the skill
	set("skill/exp_required",  0l);	// minimum combat experience required
	set("skill/jing_cost",   20 );	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  50);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	 
	set("apply/armor",20);
     

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp