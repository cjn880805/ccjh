//qin.h
EQUIP_BEGIN(CIqin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "白玉瑶琴");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "music");
	set("music_type", "qin");

	set_weight(6000);		//set item weight
	
	set("unit", "具");
	set("long", "这是一具用白玉做成的瑶琴。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N从背后将$n拿在手中。");
	set("unwield_msg", "$N将手中的$n放回背后。");
	set("apply/damage", 100);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp