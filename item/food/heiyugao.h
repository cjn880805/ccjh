//heiyugao.h

//Sample for ITEM ���������
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIheiyugao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���������");	//set item name

	set("unit", "��");
	set("long", "����һ��ǧ�꼫�������Ƶĵĺ��������,��˵������������");
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->set_temp("nopoison", 1);
	me->receive_curing("hp", 200);
	tell_object(me,  "��ֻ��һ���������߾�������ѭ����һ�����죬������������ˣ�"  );
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp