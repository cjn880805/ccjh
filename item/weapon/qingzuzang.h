//qingzuzang.h

//Sample for ITEM: 青竹杖
//coded by wolfman
//data: 2001-7-23

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIqingzuzang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青竹杖");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(5000);		//set item weight

	set("long", "一根竹子做成的杖。");
	set("unit", "根");
	set("material", "bamboo");
	set("wield_msg", "$N抽出一根青竹杖抓在手中。");
	set("unwield_msg", "$N把手中的青竹杖插回腰中。");

	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
