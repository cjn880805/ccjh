//qianzhuang.h

//Sample for room: Ǯׯ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ǯׯ");

	//add npcs into the room
	add_npc("pub_banker");
	add_npc("pub_qian");
	
	add_door("��������", "��������", "����Ǯׯ");

	set("long", "����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ����    �ڶ����ǽ�Ϲ��˿�����(paizi)��" );
	
	set("no_fight", 1);
	set("no_beg", 1);
/*****************************************************
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
********************************************/
};


ROOM_END;
