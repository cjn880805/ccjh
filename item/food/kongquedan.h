//kongquedan.h

//Sample for ITEM ��ȸ��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIkongquedan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ȸ��");	//set item name

	set("long", "һƿ�綾�Ķ�ҩ, ��������������м�Ѫ���֮Ч. ");
	set("unit", "��");
	set("value", 20000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N��ͷ�ſ�����һ��%n", me,this);
	me->die();
	destruct(this );
	return 1;
}
/**********************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="hong" || arg=="heding hong") 
	{
		message_vision("$N��ͷ�ſ�����һ��" + name() + "��\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
*****************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp