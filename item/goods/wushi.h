ITEM_BEGIN(CIwushi);

virtual void create(int nFlag = 0)		
{
	set_name( "ʯ����ʿ", "shi wus hi");
	set("no_get", 1);
	set_weight(10000);
	set("idle",1);
};

virtual int do_look(CChar * me)
{
	say("һ��ߴ��ʯ����ʿ��", me);

	if (me->query("teapot/yangguo"))
	{
		AddMenuItem("��ǰ�ƶ�", "$9trans $1 a", me);
		AddMenuItem("��������", "$9transx $1 b", me);
		AddMenuItem("ת���뿪", "", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_gox(me, arg);
	if(strcmp(comm, "transx") == 0)
		return do_go(me, arg);
	return 0;
}

int do_go(CChar * me , char  * dest)
{
	if (!strlen(dest))
		return 0;
	long i;
	i=query("idle");
		message_vision("$N�����İ�ʯ������������",me);
		i=i+1;
	set("idle",i);

	if (i==2451)
	{
		set("idle",1);
		message_vision("ʯ�˷�����֨��֨������������ͻȻ¶��һ���󶴣�$N�㲻������������ȥ��",me);
		me->move(load_room("��������"));
	}
	return 1;
	
}


int do_gox(CChar * me , char  * dest)
{
	if (!strlen(dest))
		return 0;
	long i;
	i=query("idle");
		message_vision("$N�����İ�ʯ����ǰ�ơ���",me);
		i=i*2;

	set("idle",i);

	if (i==2451)
	{
		set("idle",1);
		message_vision("ʯ�˷�����֨��֨������������ͻȻ¶��һ���󶴣�$N�㲻������������ȥ��",me);
		me->move(load_room("��������"));
	}
	return 1;
	
}
ITEM_END;
//1110101000010110101
//23489 19           305  711 712  1425 2851
//    18 38 76 152 304 710       1424 2850
