//baihua.h

//Sample for ITEM �ٻ����߸�
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbaihua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ٻ����߸�");	//set item name
	
	set("unit", "ö");
	set("long", "����һö���İٻ����߸ࡣ");
	set("value", 20000);
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "tu") == 0)
		return do_tu(me);

	return 0;
}

int do_tu(CChar * me)
{
//	CContainer * obj;

	if (! me->query_weapon() )
		return notify_fail("�����������²��аɣ�");

	message_vision("$Nȡ��һö�ٻ����߸࣬����Ĩ�ڱ��м�����֮��.", me);
	message_vision("$Nʹ�õİٻ����߸�ҩЧ��ʼ����.", me);
//	obj=load_item("/d/shenlong/obj/usedgao");
//	obj->move(me);
	destruct(this);
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	int force_limit, mp_limit ;
	force_limit = me->query_skill("force")*10;
	mp_limit = me->query("max_mp");
	
	if ( mp_limit <= force_limit  )
	{
		me->add("max_mp",1);		
		message_vision( "$N����һö�ٻ����߸࣬��Ȼ��ֻ��һ������֮��ֱ���ķ�..." , me);
	}
	else
		message_vision( "$N����һö�ٻ����߸࣬���Ǻ���ûʲô��." , me);
	
	destruct(this);
	return 1;
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp