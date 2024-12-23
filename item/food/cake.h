//cake.h

//Sample for ITEM ����
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIcake);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{

	 static char xunbuname[7][13]={"��ʽ����","�������⵰��","�󵰸�","����ʻ浰��","�����͵���","ӣ�ҵ���","��鵰��"};

	 set_name(xunbuname[random(7)]);
	 
	set_weight(200);
	
	set("long", "һ�����������˵ĵ��⡣");
	set("unit","��");
	set("value",0l);
	set("no_get",1);
	set("no_give",1);
	set("no_drop",1);
//	set("food_remaining",4);
	set("m_exppoint",random(200));
	
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
//	CContainer * me = Environment();
	if (target != me)
		return notify_fail("����ֻ���Լ��ԡ�");

	char msg[255];

	if(! me || ! me->Query(IS_CHAR)) return 0;	//������
	int i;

	i=query("m_exppoint");

	if(!i)
	{
		tell_object(me,"��ѵ����������ڿ��˸�����");
		destruct(this);
		return 0;
	}

	if(!random(3))
	{
		me->add("combat_exp", i);
		snprintf(msg, 255, "$N���𵰸⣬�����������������죬��ʼϸ��Ʒ����\n$N�ӵ����з�����%d�㾭�飡", i);
		message_vision(msg,me);
		me->FlushMyInfo();		
	}
	else
	{
		snprintf(msg, 255, "$N���𵰸⣬�����������������̲�ס�����ڳԹ⡣\n$N�Ķ�����ͻȻ������ը����������", i);
		message_vision(msg,me);
		me->receive_damage("hp", 50 + i);
		me->FlushMyInfo();

	}

		destruct(this);

	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp