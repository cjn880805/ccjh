//hdjiudai.h

//Sample for ITEM ����ƴ�
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIhdjiudai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ƴ�");	//set item name

	set_weight(700);

	set("long", "һ������װ�߼�����ƵĴ�ƴ���");
	set("unit", "��");
	set("value", 120);
	set("max_liquid", 20);
	set("liquid/type","alcohol" );
	set("liquid/name","�����" );
	set("liquid/remaining", 20);
	set("liquid/drunk_apply", 6);

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp