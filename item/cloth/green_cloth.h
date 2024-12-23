//green_cloth.h

//Sample for ITEM: 翠绿绸衫
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIgreen_cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "翠绿绸衫");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(3000);		//set item weight

	set("long", "这件翠绿色的绸衫上面绣着几只黄鹊，闻起来还有一股淡香。");
	set("unit", "件");
	set("value", 600);
	set("material", "cloth");
	set("apply/armor", 1);
	set("apply/per", 3);
	set("female_only", 1);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp