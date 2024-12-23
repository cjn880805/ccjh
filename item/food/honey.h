//honey_san.h

//Sample for ITEM ��佬
//coded by Cat
//data: 2001-4-3

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhoney);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��佬");	//set item name
	set("long", "�ɼ����ʽ��������ɣ�����ɿڡ�");
	set("unit", "ƿ");
	set("value", 2000);
	set_weight(30000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N����һƿ$n", me,this);

	if (me->query("condition/yufeng_poison") > 0) 
	{
		me->apply_condition("yufeng_poison", 0);
		message_vision("$N��һ�����������ķΣ����ϵ���䶾���ڲ���������ʡ�", me);
	}
	else
		message_vision("$N��һ�����������ķΣ���ɫ���˲��١�", me);

	me->receive_healing("hp", 50);
	me->FlushMyInfo();
	destruct(this);
    return 1;
}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp