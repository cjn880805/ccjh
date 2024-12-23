//gaoyao.h

//Sample for ITEM ��Ƥ��ҩ
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIgaoyao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ƥ��ҩ");	//set item name

	set("unit", "��");
	set("long", "����һ��������ʿ����(tie)�Ĺ�Ƥ��ҩ��");
	set("value", 2000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("������û������Ƥ��ҩ�ˡ�");
	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("�����ڲ���Ҫ�ù�Ƥ��ҩ��");
	else
	{
		me->receive_curing("hp", 50);
		message_vision("$Nž��һ�����˿�������һ����Ƥ��ҩ����ɫ�������ö��ˡ�", me);
		me->start_busy(2);
		destruct(this);
		return 1;
	}
	
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp