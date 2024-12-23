//jubaozhai.h

//Sample for room: �۱�ի
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_jubaozhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�۱�ի");

	//add npcs into the room
	add_npc("pub_sun");/////////////////////////

	add_door("������", "������", "���ݾ۱�ի");

	set("long", "����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ����    �ڶ����ǽ�Ϲ��˿�����(paizi)��  " );
 	
	
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );
	set("exits", ([
		"east"  : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/sun": 1,
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
