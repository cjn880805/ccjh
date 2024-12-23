//langyabang.h

//Sample for ITEM: 狼牙棒
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIlangyabang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "狼牙棒");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(30000);		//set item weight

	set("unit", "根");
	set("long", "这是一根两头狼牙棒，约两百来斤，是件称手的重兵器。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N抽出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");
	set("shaolin",1);
//	init_staff(200);
	set("apply/damage", 200);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp