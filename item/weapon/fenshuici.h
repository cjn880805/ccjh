//fenshuici.h

//Sample for ITEM: 分水刺
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIfenshuici);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "分水刺");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "柄");
	set("long", "这是一只水中分水峨嵋刺。");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一只$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回袖中。");
	set("apply/damage", 15);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp