//allow_letter.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIallow_letter);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set_weight(100);		//set item weight

	set("unit", "��");
	set("long","����һ���ɷ���ǩ�������ͣ�ƾ�˿����ɽ���ؾ����¥��ϰ�ϳ��书��");
	set("no_drop", "�������������뿪�㡣");
	set("material", "paper");
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp