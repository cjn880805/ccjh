//tianqi.h

//Sample for ITEM ����
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItianqi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set_weight(800);

	set("unit", "��");
	set("long", "����һ�����ߣ�����������ҩ��");

};
virtual int do_use(CChar * me, CContainer * target)
{
	tell_object(me,"���������ڰ����߳�����ȥ��");
	destruct(this);
	return 1;
}
/******************
int do_eat(string arg)
{
        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="tianqi")
        {
                write("���������ڰ����߳�����ȥ��\n");
                destruct(this_object());
        }
        return 1;
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp