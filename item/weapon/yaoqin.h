//yaoqin.h

//Sample for ITEM: 瑶琴
//coded by Fisho
//data: 2000-11-16
EQUIP_BEGIN(CIyaoqin);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "瑶琴");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield

	set("skill_type", "music");
	set("music_type", "qin");

	set_weight(5000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把歌女用的瑶琴，制做得相当精巧细腻。");
	set("value", 300);
	set("material", "iron");
	set("wield_msg", "$N从背上解下一把$n，然後横在手中。");
	set("unwield_msg", "$N放下手中的$n。");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp