//qianzhuang.h

//Sample for room: Ǯׯ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_qianzhuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ǯׯ");

	//add npcs into the room
	add_npc("pub_huangzhen");////////////////////////////
				

	add_door("��������", "��������", "����Ǯׯ");

	set("no_fight", 1);
/*****************************************************
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]));
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
********************************************/
};


ROOM_END;
