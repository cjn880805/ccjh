//xuelian2.h

//Sample for ITEM ��ɽѩ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxuelian2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ɽѩ��");	//set item name

	set("unit", "֧");
	set("long","����һֻ֧���ں���ĵط�����������ѩ����.");
	set("value", 100);

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_mp") == me->query("max_mp"))
		return notify_fail("�����ڲ��ó��ⱦ��!");
	me->receive_curing("mp",200);
	message_vision("$NС�ĵس���һ��ѩ��,��ʱ����������ˬ�˲���!",me);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp