//sanbuguan.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sanbuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱������");

	//add npcs into the room
//	add_npc("animal_cow");/////////////////////////
	add_npc("pub_wufa");
	add_npc("pub_wutian");

	add_door("�䵱��ʯ���1", "�䵱��ʯ���1", "�䵱������");
	add_door("����С·", "����С·", "�䵱������");
	add_door("�ɶ���������", "�ɶ���������", "�䵱������");

   	
 
/*****************************************************
        set("outdoors", "wudang");
        set("exits", ([
            "east"      : __DIR__"wdroad8",
            "southeast" : __DIR__"wdroad9",
            "southwest" : "/d/emei/wdroad",
        ]));
        set("objects", ([
		__DIR__"npc/cow": 1,
        ]));
*****************************************************/
};


ROOM_END;
