//jiudai.h

//Sample for ITEM ţƤ�ƴ�
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIjiudai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ţƤ�ƴ�");	//set item name

	set_weight(2000);
	
	set("long", "һ������װ�׾ƵĴ�ƴ������װ�ðˡ������ľơ�");
	set("unit", "��");
	set("value", 20);
	set("max_liquid", 15);
 	
	set("liquid/type", "alcohol");
	set("liquid/name", "�׾�");
	set("liquid/remaining", 15);
	set("liquid/drunk_supply", 6);

};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp



