//rover.h

//Sample for ITEM: Ʈ�ħ��
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIrover);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ʈ�ħ��");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(100);		//set item weight
        set("value", 400);   
	set("long", "һ����ħ�����·�������������һ�ɵ��㣬����ȥ�о���Ʈ翡�");
	set("unit", "��");
	set("material", "cloth");
	set("apply/armor", 1);
	set("apply/per", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp