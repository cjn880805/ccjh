//yaofen.h

//Sample for ITEM ҩ��
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIyaofen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("ҩ��", "yaofen");	//set item name

	set("unit", "��");
	set("long", "����һ��ר�����˵�ҩ�ۡ�");
	set("value", 1000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	return notify_fail("ֻ��ר���ɶԸ����������ơ����书���˲���Ҫ������ҩ��");
}
/*************

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	return notify_fail("ֻ��ר���ɶԸ����������ơ����书���˲���Ҫ������ҩ��\n");
}
**********************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp