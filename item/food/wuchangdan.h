//wuchangdan.h

//Sample for ITEM �޳���
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIwuchangdan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�޳���");	//set item name

	set("unit", "��");
	set("long", "����һ�ž�Ө�����޳��������һ������������ƣ�����������֮����");
	set("value", 5000);
 	
};

virtual int do_use(CChar * me, CContainer * target)
{
    me->set("hp", me->query("max_hp"));
    me->set("mp", me->query("max_mp"));
    me->set("eff_hp", me->query("max_hp"));
	me->set("eff_mp", me->query("max_mp"));

	char msg[255];
	snprintf(msg, 255, "%s����һ���޳�������ʱȫ�����������", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp