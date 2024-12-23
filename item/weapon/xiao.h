//xiao.h

//Sample for ITEM: 绿玉洞箫
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "绿玉洞箫", "xiao");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	
	set("skill_type", "music");
	set("music_type", "xiao");

	set_weight(4000);		//set item weight

	set("unit", "根");
	set("long", "这是一根用绿玉做成的洞箫。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声从怀中掏出一根$n握在手中。");
	set("unwield_msg", "$N将手中的$n揣回怀里。");
//	init_dagger(70);
	set("apply/damage", 35);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp