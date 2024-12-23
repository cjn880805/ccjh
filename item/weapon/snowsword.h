//snowsword.h

//Sample for ITEM: 风回雪舞剑
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIsnowsword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "风回雪舞剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(400);		//set item weight
	
	set("unit",  "把");
	set("value",  700);
	set("material",  "steel");
	set("long",  "这是一把用来练舞的剑，剑身细长，轻巧尤锋利。");
	set("wield_msg",  "$N抽出一把剑身细长的剑，握在手中。");
	set("unequip_msg",  "$N放下手中的$n。");
	set("apply/courage",  4);
	set("apply/damage", 40);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp