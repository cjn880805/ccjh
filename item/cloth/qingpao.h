//qingpao.h

//Sample for ITEM: 青色丝袍
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIqingpao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青色丝袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("female_only", 1);
	set("unit", "件");
	set("long", "这是件质地轻柔的青色镂花丝袍，特别受女性青睐。");
	set("material", "cloth");
	set("value",70);
	set("apply/armor", 4);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp