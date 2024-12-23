//majia.h

//Sample for ITEM: 小马甲
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CImajia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "小马甲");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1500);		//set item weight
	
	set("long", "这是凌儿的胸甲。粉红色的小马甲上绣着几只鸳鸯，闻起来还有一股淡香。");
	set("unit", "件");
	set("value", 5000);
	set("material", "丝");
	set("apply/armor", 3);
	set("apply/per", 3);
	set("female_only", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp