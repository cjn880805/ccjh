//leizhendang.h

//Sample for ITEM: 雷震挡
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIleizhendang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "雷震挡");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(8000);		//set item weight

	set("unit", "杆");
	set("long", "一杆十分沉重的雷震挡。");
	set("value", 10000);
	set("material", "bamboo");
	set("wield_msg", "$N回手从身后抽出一杆雷震挡。");
	set("unwield_msg", "$N手往后一扣，把雷震挡放在身后。");
//	init_staff(50);
	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp