//dan.h

//Sample for ITEM �ɵ�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIdan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ɵ�");	//set item name

	set_weight(20);
	
	set("no_get", "�ٺ٣����ΰ�! ");
	set("no_drop","��ô������ɵ�����������! ");
	set("unit", "ö");
	set("long","����һö�ɵ�������ȥ����һֻСС�Ľ��«��");
	set("value", 100000);

};

virtual int do_use(CChar * me, CContainer * target)
{
//	me->set("water", me->max_water_capacity());
//	me->set("food", me->max_food_capacity());
	message_vision("$N����һ���ɵ���ֻ���þ���������Ѫ��ӯ����ˬ��̫ˬ��! ", me);
	destruct(this);
	return 1;
}

/*****************

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        me->set("water", me->max_water_capacity());
        me->set("food", me->max_food_capacity());
        message_vision(HIG
 "$N����һ���ɵ���ֻ���þ���������Ѫ��ӯ����ˬ��̫ˬ��! \n"NOR, me);

        destruct(this_object());
        return 1;
}
**********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp