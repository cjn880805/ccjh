//baiyunwan.h

//Sample for ITEM �����ܵ���
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbaiyunwan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����ܵ���");	//set item name
	
	set("unit", "��");
	set("long", "����һ��������ʿ�������������ʥҩ��");
	set("value", 3000);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->receive_curing("hp", 100);
	message_vision("$N����һ�Ű����ܵ��裬ֻ��������������ɫ��á�", me);
	destruct(this);
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp