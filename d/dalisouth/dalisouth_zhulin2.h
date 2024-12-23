//zhulin2.h

//Sample for room: �����
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	add_npc("pub_kanzhuren");  // add by zdn 2001-07-13
	
	add_door("����Ǻ�����", "����Ǻ�����", "����������");

	set("long", "����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣������ڶࡣ�о����̨�������������������ס����£���׽�á�¹��С�ޣ��������������ɽ��׽��Щ�����ޡ�" );
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
