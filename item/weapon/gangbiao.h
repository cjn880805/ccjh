//gangbiao.h

//Sample for ITEM: 钢镖
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CIgangbiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "钢镖");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("long", "这是一把普通的钢镖。");
	set("unit", "些");
	set("value", 1500);
	set("base_value", 1);
	set("material", "steel");
	set("base_unit", "枚");
	set("base_weight", 10); 
	set_amount(80);
	
	set("apply/damage", 20);					//set the modifiers of attribute
	
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp




