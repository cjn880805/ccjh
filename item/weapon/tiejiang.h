//tiejiang.h

//Sample for ITEM: 铁桨
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItiejiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁桨");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(3000);		//set item weight

	set("unit", "根");
	set("long", "这是一根铁桨，举可齐眉，看来很是沉重，可攻击大片敌人。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N抽出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");
//	init_club();
	set("apply/damage",30 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp