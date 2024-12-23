//majia.h

//Sample for ITEM: С���
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CImajia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "С���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1500);		//set item weight
	
	set("long", "����������ؼס��ۺ�ɫ��С��������ż�ֻԧ�죬����������һ�ɵ��㡣");
	set("unit", "��");
	set("value", 5000);
	set("material", "˿");
	set("apply/armor", 3);
	set("apply/per", 3);
	set("female_only", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp