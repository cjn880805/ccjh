//zaisheng.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzaisheng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("unit", "��");
	set("long", "����һ�Ž������������衣");
	set("value", 2000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if ((me->query("potential") - 100) >=  me->query("learned_points") )
		return notify_fail("�����ڲ���Ҫ�������衣");
	else
	{
		me->add("potential", 1);
		char msg[255];
		snprintf(msg, 255, "%s����һ�������裬�е������������һ��΢��ı仯", me->name());
		MessageVision(me, "chat", msg);
		destruct(this);
		return 1;
	}
}

/**************************
	if ((this_player()->query("potential") - 100) >=
	     this_player()->query("learned_points") )
		return notify_fail("�����ڲ���Ҫ�������衣\n");
	else {
	        this_player()->add("potential", 1);
	        message_vision("$N����һ�������裬�е������������һ��΢��ı仯 !\n", this_player());
	        destruct(this_object());
	        return 1;
	}
}
***********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp