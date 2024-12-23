//pink_cloth.h

//Sample for ITEM: �ۺ����
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIpink_cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ۺ����", "pink cloth");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1000);		//set item weight
         
	set("long", "����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣");
	set("unit", "��");
	set("value", 600);
	set("material", "cloth");
	set("apply/armor", 1);
	set("apply/per", 3);
	set("female_only", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp