//zhitao.h

//Sample for ITEM ָ��
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIzhitao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ָ��");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "finger");			//set the skill applied
	set_weight(500);		//set item weight
	
	set("unit", "��");
	set("long", "�������������������ָ�ף�ǰ�˷������У��ȿɰ����������ˣ��ֿɱ���ָ�ؽڡ�");
	set("value", 600);
	set("material", "steel");
	set("apply/armor", 5);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp