//duanchang.h

//Sample for ITEM �ϳ���
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIduanchang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ϳ���");	//set item name

	set("unit", "��");
	set("long", "����һ��ϳ���,ͨ��ͨ��,��������,�����쳣��");
	set("no_get", "��������ҽ�ǰ.");
};

virtual int do_use(CChar * me, CContainer * target)
{
	if(random(2)==0)
		me->unconcious();
	else 
		me->die();
	destruct(this);

    return 1;
}

/*************************
int do_eat(string arg)
{
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="duanchang") 
	{
		if(random(2)==0) this_player()->unconcious();
		else this_player()->die();
		destruct(this_object());
	}
	return 1;
}

**********************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp