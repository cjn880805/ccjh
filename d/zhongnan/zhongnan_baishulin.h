//baishulin.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baishulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("pub_playboy");

	add_door("����ɽ������", "����ɽ������", "����ɽ������");
	add_door("����ɽ�����嶥", "����ɽ�����嶥", "����ɽ������");

    set("long","�ƹ������ȵ�ɽ�ڣ���ǰ��һƬ������֣���������ɽ�ڵ�ס�����ߣ���ɽ�µ�ɽ·�ϸ����벻������İ�����������ô����ô�ߡ���̤���������У�����ȫ��ͷ������Ҷ��ס�ˣ�Խ�������������Խ���İ���" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
