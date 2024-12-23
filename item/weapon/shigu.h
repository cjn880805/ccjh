//shigu.h

//Sample for ITEM: 尸骨
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshigu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "尸骨");	//set item name

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(200);		//set item weight
  
	set("unit", "只");
	set("value", 50);
	set("material", "wood");
	set("long", "这是一根白森森的尸骨。");
	set("wield_msg","$N手中握住一把$n，眼中露出阴邪的笑意。");
	set("unwield_msg", "$N将$n插回腰间，脸色顿时也恢复了正常。");
//	init_hammer(100);
	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp