ITEM_BEGIN(CIcaishen);

virtual void create(int nFlag = 0)		
{
	set_name( "ľ�����ܡ�����ү");	
	set("no_get", "�Ѳ���ү͵�ߣ�������Ҳ̫�����쿪�˰ɡ�");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("ľ�����ܵ�һ�����ү����Ϊ�����Զ����Ƥ���䡣", me);
	AddMenuItem("�Բ���ү��ͷ", "$9kneel $1", me);
	AddMenuItem("ת���뿪", "", me);
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "kneel") == 0)
		return do_kneel(me, arg);
	return 0;
}

int do_kneel(CChar *me, char * arg)
{
	CContainer * obj;

	if (me->query("age")>14)
	{
		return notify_fail("�Ǹ���ʳ������ʱ���ˡ�");
	}	
	
	
	if (me->query("level")>5)
	{
		return notify_fail("�Ǹ���ʳ������ʱ���ˡ�");
	}	
	
	if(me->query("hp") < 30)
		return notify_fail("���Ѿ�ͷ���ۻ��ˡ�");

	me->receive_damage("hp", 30);	
	tell_object(me, "�㹧�������ĸ�����ү���˸�ͷ��");   

	if(me->query("guest"))	//�ÿͲ�����
		return 1;

	//��¼IP��ַ��lanwood 2001-02-28
	//begin---------
	char site[255];
	snprintf(site, 255, "site/%s", GetIP(me));
	if(query(site) > 29)
		return notify_fail("���������Ҫ̫̰��Ŷ��");
		
	add(site, 1);
	//end-----------

	if (me->query("balance")>10000 || ( (obj=me->present("coin")) && obj->query("value")>10000) || current_time < me->query("teapot/kneel_mcg") )
	//����д�����������Я��Ǯ������������
		return 1;	
	
	me->del("teapot/kneel_mcg");
	obj = load_item("coin");
	me->add_temp("teapot/kneel",1);	
	if (me->query_temp("teapot/kneel")>20)
	{
		me->set_temp("teapot/kneel",20);
		me->set("teapot/kneel_mcg", current_time + 86400);
	}
	obj->set_amount(me->query_temp("teapot/kneel") * 10);

	obj->move(me);

	tell_object(me, "����������������ƺ���������ү����΢΢һЦ��");   
	return 1;
}

ITEM_END;
