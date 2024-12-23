//yupei.h

//Sample for ITEM: 玉佩
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIyupei);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "玉佩");	//set item name

	set("wield_position", WIELD_WAIST);		//set the position of wield
 	set_weight(300);		//set item weight

	set("unit", "枚");
	set("value", 10000);
	set("material", "玉");
	set("apply/armor", 2);
	set("female_only", 1);
	set("long", "这是一块淡兰色的宝玉，莹滑温润，光洁无瑕，真是稀世罕有。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp