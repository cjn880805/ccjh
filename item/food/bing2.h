//bing2.h

//Sample for ITEM ���ٱ�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbing_2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ٱ�");	//set item name

	set("unit", "��");
 	set("long", "����һ������Ķ��ٱ���");
	set("value",280000); //add by Fisho
  	
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add("combat_exp",168);
	me->add("potential",6);
	message_vision( "$N�������ڳ���һ��$n��" , me, this );
	destruct(this);
	return 1;
}

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}
/*****************

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="bing2"||arg=="erjubing")
	{
		me->add("combat_exp",168);
		me->add("potential",6);
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
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