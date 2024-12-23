//huoqiang.h

//Sample for ITEM: 荷兰火枪
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIhuoqiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "荷兰火枪");	//set item name
	
        set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(5000);		//set item weight
	
	set("unit", "支");
	set("long", "一支荷兰火枪。可惜只能放一枪。");
	set("value", 800);
	set("material", "bamboo");
	set("wield_msg", "$N抽出一支乌油的木柄火枪握在手中。");
	set("unwield_msg", "$N把手中的火枪背回背上。");
	set("apply/damage", 50);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp