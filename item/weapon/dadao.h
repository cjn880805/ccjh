//dadao.h

//Sample for ITEM: 大刀
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdadao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "斩马刀");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一柄亮晃晃的长刀。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声从背后拨出一柄$n。");
	set("unwield_msg", "$N将手中的$n插回背后。");
	set("apply/damage", 40);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp