//yuxiao.h

//Sample for ITEM: 玉萧
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyuxiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "玉箫");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	
	set("skill_type", "sword");
	set("music_type", "xiao");

	set_weight(500);		//set item weight

	set("unit", "支");
	set("long", "一支白玉做成的长箫，看上去晶莹温润。武林中人经常以箫代剑，不过好像并不结实。");
	set("value", 1000);
	set("material", "bamboo");
	set("wield_msg", "$N大袖一挥，手中已多了一支晶莹温润的玉箫。");
	set("unwield_msg", "$N手中玉箫一转，眨眼间玉萧已然不见影踪。");
//	init_sword();
	set("apply/damage", 20);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp