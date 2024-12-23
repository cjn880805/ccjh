//zhubang.h

//Sample for ITEM 竹棒
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIZhuBang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "竹棒");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(3000);		//set item weight


	set("unit", "根");
	set("long", "这是一根发黄的竹棒，入手沉甸甸的，似乎相当结实。");
	set("value", 200);
	set("material", "steel");
	set("wield_msg", "$N抽出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回腰间。");
//    init_staff(25);
	set("apply/damage", 25);					//set the modifiers of attribute
  
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp