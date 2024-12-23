//jjunfu.h

//Sample for ITEM: 锦衣军服
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjjunfu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "锦衣军服");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
          
	set("long", "这是一件颜色鲜亮的锦衣军服。");
	set("material", "cloth");
	set("unit", "件");
	set("value", 1200);
	set("apply/per", 4);
	set("apply/armor", 15);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp