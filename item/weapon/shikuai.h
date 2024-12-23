//shikuai.h

//Sample for ITEM: 石块
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshikuai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "石块");	//set item name

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "基本");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "块");
	set("long", "这是一平平常常的鹅卵石。");
	set("value", 0l);
	set("material", "stone");
	set("wield_msg", "$N搬起一块$n准备战斗。");
	set("unwield_msg", "$N放下手中的$n。");
//	init_hammer(1);
	set("apply/damage", 1);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp