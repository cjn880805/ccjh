//jingxin_san.h

//Sample for ITEM ���Ŀڷ�Һ
//coded by Cat
//data: 2001-4-3

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjingxin_san);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���Ŀڷ�Һ");	//set item name
	set("long", "Ů������Ҫ���ģ���������ħ���������������");
	set("unit", "ƿ");
	set("value", 2000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N����һƿ$n", me,this);

	if (me->query("condition/bingpo_poison") > 0) 
	{
		me->apply_condition("bingpo_poison", 0);
		message_vision("$N��������ƽ���˲��٣���������Ķ���������ȥ��", me);
	}
	if (me->query("condition/wuduz_poison") > 0) 
	{
		me->apply_condition("wuduz_poison", 0);
		message_vision("$N��������ƽ���˲��٣��嶾���ƵĶ���������ȥ��", me);
	}
	else
		message_vision("$N��������ƽ���˲��٣����Ե�˵������Ů������Ҫ���ģ����Ŀڷ�Һ����", me);

    me->receive_healing("hp", 40);
	me->FlushMyInfo();
	destruct(this);
    return 1;
}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp