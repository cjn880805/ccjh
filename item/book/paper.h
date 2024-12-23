//paper.h

//Sample for ITEM: 信纸
//coded by Fisho
//data: 2000-11-14

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIpaper);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "信纸");	//set item name

	set_weight(100);		//set item weight

	set("unit", "张");
	set("long", "这是张普通的信纸，上面是岳不群写给朋友的家常信，信已写好，而且盖上了私印，大概走的匆忙忘记带上了。 ");
	set("value", 5000);
	set("material", "paper");

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp