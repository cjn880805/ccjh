//xionghuang.h

//Sample for ITEM �ۻ�
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxionghuang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ۻ�");	//set item name

	set("unit", "��");
	set("long", "����һ���ۻ�,��˵�����ٶ���");
	set("value", 1000);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	return notify_fail("���������ۻƲ��ܳ�.");
}
/***********
int do_eat(string arg)
{
	return notify_fail("���������ۻƲ��ܳ�.\n");
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp