//guiling.h

//Sample for ITEM ���߸�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIguiling);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���߸�");	//set item name

	set_weight(3000);
	
    set("unit", "��");
    set("long", "����һ�����ڹ�׺��������óɵĹ��߸࣬�����������١�");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("max_mp")<=600) 
	{
		tell_object(me,"�������һ����߸ֻ࣬���þ�����֮��������ֱ�����ڶ�����");
		me->add("max_mp",2);
		me->add("mp",2);
	}
	else 
	{
		tell_object(me,"�������һ����߸࣬���Ǻ���ûʲô�á�");
	}
	destruct(this );
	me->unconcious();
	return 1;
}
/********************

int do_eat(string arg)
{
        object me=this_player();

        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="gao")
        {
                if (me->query("max_jingli")<=300) {
                        write(YEL"�������һ����߸ֻ࣬���þ�����֮��������ֱ
�����ڶ�����\n"NOR);
                        me->add("max_jingli",20);
                        me->add("jingli",20);
                }
                else {
                        write("�������һ����߸࣬���Ǻ���ûʲô�á�\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
***********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp