//yangxin.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyangxin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("unit", "��");
	set("long", "����һ�Ű��췢���������衣");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
    me->receive_healing("hp", 200);

	char msg[255];
	snprintf(msg, 255, "%s����һ�������裬ֻ������������ԴԴ�������������ơ�", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp