//changqiang.h

//Sample for ITEM 长枪
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIChangQiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "长枪");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "杆");
	set("long", "这是一根白缨长钢枪，长可丈二，枪头隐隐透出寒光。");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N掣出一杆根$n握在手中。");
	set("unwield_msg", "$N将手中的$n反别身后。");

	set("apply/damage", 25);					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp