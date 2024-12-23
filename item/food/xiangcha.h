//xiangcha.h

//Sample for ITEM ���
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiangcha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���");	//set item name

	set_weight(50);

	set("long", "һ���Ȳ裬���Ƶ�ð������������");
	set("unit", "��");
	set("value", 1000);
	set("remaining", 2);
	set("drink_supply", 25);

};

virtual int do_use(CChar * me, CContainer * target)
{
	int  recover, jing, e_jing, m_jing;
	recover = 5;
	if( me->is_busy() )
	{
		tell_object(me,"����һ��������û����ɡ�");
		return 0;
	}
	
	set("value", 0l);
	me->add("hp", query("drink_supply"));
	jing   = me->query("hp");
	e_jing = me->query("eff_hp");
	m_jing = me->query("max_hp");

	if( me->is_fighting() ) me->start_busy(2);
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N������裬������ζ��Ʒ�˼��ڡ�һ������ֱ����Ƣ��$N���þ���ö��ˡ�", me);
	} 
	else 
	{ 
		message_vision("$N�����С������ʣ�µ����һ��������һ������ֱ����Ƣ��$N���þ���ö��ˡ�", me);
		destruct(this);
	}
	return 1;
}
/****************
int do_drink(string arg)
{
	int heal, recover, jing, e_jing, m_jing;
	recover = 5;

	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
if( this_player()->query("water")
	   >= this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0l);
	this_player()->add("water", query("drink_supply"));
	jing = this_player()->query("hp");
	e_jing = this_player()->query("eff_jing");
	m_jing = this_player()->query("max_jing");

	if( this_player()->is_fighting() ) this_player()->start_busy(2);
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N������裬������ζ��Ʒ�˼��ڡ�\n"+
		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
		message_vision("$N�����С������ʣ�µ����һ��������\n"+
		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		destruct(this_object());
	}
	return 1;
}
*************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp