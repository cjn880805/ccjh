//jiuping2.h

//Sample for ITEM ��ƿ
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIjiuping2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "һͰ��Ҷ��");	//set item name

	set_weight(700);
	
	set("long", "һ����ľ���Ĵ��Ͱ��װ��ѬѬ���˵���Ҷ�ࡣ");
	set("unit", "��");
	set("value", 1600);
	set("max_liquid", 15);
	set("liquid/type", "alcohol");
	set("liquid/name", "��Ҷ��");
	set("liquid/remaining", 15);
	set("liquid/drunk_supply", 3);
	set("m_exppoint",random(200));
	set("no_get",1);
	set("no_give",1);
	set("no_drop",1);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
//	CContainer * me = Environment();
	if (target != me)
		return notify_fail("��ֻ���Լ��ȡ�");

	char msg[255];

	int i;

	i=query("m_exppoint");

	if(!i)
	{
		tell_object(me,"��Ѿ�������һ���������������ˡ�");
		destruct(this);
		return 1;
	}

	if(!random(4))
	{
		me->add("combat_exp", i);
		snprintf(msg, 255, "$N��������Ʒζ��ԽƷԽ��ζ������\n$N�������еõ���%d�㾭�飡", i);
		message_vision(msg,me);
		me->FlushMyInfo();
		
	}
	else
	{
		snprintf(msg, 255, "$N��ཹ�ཱུİѾƺ��¡�\n$N����ɫһ���һ��ף������Ǻ����ˣ�", i);
		message_vision(msg,me);
		me->apply_condition("drunk", 20 + random(20));
		me->FlushMyInfo();

	}

	destruct(this);

	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp