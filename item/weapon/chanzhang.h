//chanzhang.h

//Sample for ITEM: 禅杖
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIchanzhang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "禅杖");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "根");
	set("long", "这是一根黑黝黝的镔铁禅杖，约四十来斤，是件称手的重兵器。");
	set("value", 200);
	set("material", "steel");
	set("wield_msg", "$N抽出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");
	set("shaolin",1);
	set("apply/damage", 25);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp