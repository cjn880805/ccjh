//xuelian.h

//Sample for ITEM ѩ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxuelian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ѩ��");	//set item name

	set("unit", "��");
	set("long","����һ���ɽѩ��.");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
    me->add("eff_hp", 200);
//    me->add("max_hp", 200);

	char msg[255];
	snprintf(msg, 255, "%s����һ��ѩ�����پ������ٱ�", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}
/*****************
int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	this_player()->add("eff_qi", 200);
    message_vision("$N����һ��ѩ�����پ������ٱ�!\n", this_player());
	destruct(this_object());
	return 1;
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp