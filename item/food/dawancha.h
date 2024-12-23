//dawancha.h

//Sample for ITEM �ִŴ���
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIdawancha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ִŴ���");	//set item name

	set_weight(50);
	
	set("long", "һ�����ߴִŴ��롣");
	set("unit", "��");
	set("value", 0l);
	set("max_liquid", 4);
	set("liquid/type", "tea");
	set("liquid/name", "��ˮ");
	set("liquid/remaining",4 );
	set("liquid/drunk_supply", 0l);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp