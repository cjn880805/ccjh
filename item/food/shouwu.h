//shouwu.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshouwu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set_weight(100);

	set("unit", "֧");
	set("long", "����һ֧�ѳ����εĺ����ڣ�����������ҩ��");
	set("value", 10000);
 
};
virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("max_hp")<=200) 
	{
		tell_object(me,"�������һ֧�����ڣ�ֻ���þ�����֮����");
		me->add("max_hp",2);
		me->add("hp",100);
	}
	else
	{
		tell_object(me,"�������һ֧�����ڣ����Ǻ���ûʲô�á�");
	}
	destruct(this);
	me->unconcious();
	return 1;

}
/****************
int do_eat(string arg)
{
      if(arg=="shouwu")
        {
                if (me->query("max_jingli")<=200) {
                        write("�������һ֧�����ڣ�ֻ���þ�����֮����\n");
                        me->add("max_jingli",2);
                        me->add("jingli",2);
                }
                else {
                        write("�������һ֧�����ڣ����Ǻ���ûʲô�á�\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp