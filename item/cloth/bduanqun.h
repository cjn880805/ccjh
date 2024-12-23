//bduanqun.h

//Sample for ITEM: °ÚÒÄ¶ÌÈ¹
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIbduanqun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "°ÚÒÄ¶ÌÈ¹");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight

	set("long", "ÕâÊÇÒ»¼ş°ÚÒÄ¶ÌÈ¹¡£");
	set("material", "cloth");
	set("unit", "¼ş");
	set("value", 250);
	set("apply/armor", 3);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp