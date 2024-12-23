//jiuhua.h

//Sample for ITEM �Ż���¶��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIjiuhua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�Ż���¶��");	//set item name

	set("unit", "��");
	set("long", "����һ�ž�Ө���̵ľŻ���¶�裬���һ������������ƣ�����������֮����");
	set("value", 5000);

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�");
	
	me->set("eff_hp",me->query("max_hp"));
	me->set("hp",me->query("max_hp"));
	me->set("mp",me->query("max_mp"));
	message_vision("$N����һ�žŻ���¶�裬һ��������ˬ�ӵ���������ȫ����ɢ��",me);
	me->start_busy(1);
	destruct(this);
	return 1;
	
}
virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp