//majiu.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_majiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
//	add_npc("animal_zaohongma");
//	add_npc("animal_ziliuma");
//	add_npc("animal_huangbiaoma");
//	add_npc("pub_mafu");				

	add_door("����Ϸ԰��", "����Ϸ԰��", "�������");

	set("long", "���Ǳ���ֵ���ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��    ����жѷ������Ѳ��ϣ�������һ����ۡ� " );
 	set("outdoors", "city");
	set("no_fight", "1");
	set("no_beg", "1");
	
/*****************************************************
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz

TEXT]));
	set("exits",([  
		"east"  : __DIR__"beidajie1",
		"south" : __DIR__"xiyuan",
	]));

********************************************/
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
