//yangjing.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyangjing);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("unit", "��");
	set("value", 2000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�");
	message_vision("$N����һ��$n", me, this);

	if ((me->query("condition/xx_poison") > 0) ||
		((me->query("eff_hp") / me->query("max_hp")) < 0.9))
	{
		me->receive_curing("hp", me->query("max_hp") / 50);
	}
	me->start_busy(2);
    destruct(this);
	return 1;
}
/******************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	message_vision("$N����һ��" + name() + "��\n", me);
 	if ((me->query_condition("xx_poison") > 0) ||
	((me->query("eff_jing") / me->query("max_jing")) < 0.9))
	{
		me->receive_curing("hp", me->query("max_jing") / 50);
	}
	me->start_busy(2);
	destruct(this_object());
	return 1;
}

**********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp