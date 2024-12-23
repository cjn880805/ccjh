//shuozhuo.h

//Sample for ITEM: 手镯
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshouzhuo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "手镯");	//set item name

	set("wield_position", WIELD_WRIST);		//set the position of wield
 	set_weight(300);		//set item weight

	set("unit", "对");
	set("value", 10000);
	set("material", "玉");
	set("apply/armor", 2);
	set("apply/per", 1);
	set("female_only", 1);
	set("long", "这是一对玉镯，莹滑温润，光洁无瑕，真是稀世罕有。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp