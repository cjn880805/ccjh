//mini_dress.h

//Sample for ITEM 彩缎紧身袄
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImini_dress);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "彩缎紧身袄");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(700);		//set item weight

	set("unit", "件");
	set("value", 2000);
	set("material", "cloth");
	set("armor_type", "cloth");
	set("apply/per", 2);
	set("apply/armor", 3);
	set("female_only", 1);
	set("wear_msg","$N穿上一件$n。");
	set("remove_msg","$将$n脱了下来。");
       	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp