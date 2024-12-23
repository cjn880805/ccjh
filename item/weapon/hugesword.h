//hugesword.h

//Sample for ITEM: ¾Þ½£
//coded by Lanwood
//data: 2000-10-26

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIXiangYang_HugeSword);

//npc_name must use "CI-" begin since it belongs item class
//Example: ¾Þ½£ named "CIXiangYang_HugeSword"

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¾Þ½£");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(1500);		//set item weight

	set("value", 500);		//set item value
	set("apply/str", 20);

	set("apply/damage", 35);					//set the modifiers of attribute

};

virtual int Can_Equip(CChar * me)
{
	if(me->query("str") < 28)	//if strength of player less than 20, he can't wield the huge sword
		return 0;

	return 1;
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp