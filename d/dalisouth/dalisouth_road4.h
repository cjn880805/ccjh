//road4.h

//Sample for room: ��·4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��·4");

	add_npc("pub_shennongdizi");  //add by zdn 2001-07-13

	add_door("�����˫����", "�����˫����", "����Ǵ�·4");
	add_door("�����������", "�����������", "����Ǵ�·4");

	set("long", "һ����ͨ�ϱ��Ĵ�·�����ɴ�������ϱ߽����Ĺٵ�����·���ϴ�������ï�ܣ���Ƭ���ָ���ɽ�룬�˼���ƽ�ƽ̹����·��ֱ�������ű��ߵĴ���Ǻ��ϱߵ�ϲ�ݵȳ���" );
	
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
