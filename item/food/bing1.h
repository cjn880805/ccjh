//bing1.h

//Sample for ITEM һ���
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbing_1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "һ���");	//set item name

	set("unit", "��");
 	set("long", "����һ������һ�����");
	set("value",250000); //add by Fisho
  	
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision( "$N�������ڳ���һ��$n��" , me, this);
	me->add("combat_exp",68);
	destruct(this);
	return 1;
}

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}
/*******************
int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="bing1"||arg=="yixiubing")
	{
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
		me->add("combat_exp",68);
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp