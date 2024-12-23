//allow_letter.h

//Sample for ITEM: 手谕
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIallow_letter);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "手谕");	//set item name

	set_weight(100);		//set item weight

	set("unit", "封");
	set("long","这是一封由方丈签发的手谕，凭此可自由进入藏经阁二楼研习上乘武功。");
	set("no_drop", "这样东西不能离开你。");
	set("material", "paper");
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp