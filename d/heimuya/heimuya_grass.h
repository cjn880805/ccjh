//grass.h

//Sample for room: ��ľ�²ݵ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_grass);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�²ݵ�");

	add_npc("pub_maxiaofeng");
	add_door("��ľ�·����ô���", "��ľ�·����ô���", "��ľ�²ݵ�");
	add_door("��ľ�·�����", "��ľ�·�����", "��ľ�²ݵ�");
	add_door("��ľ�·����ó���", "��ľ�·����ó���", "��ľ�²ݵ�");

	set("long", "������һƬ�ݵء� ");
    

/*****************************************************
        set("exits", ([
            "east"    : __DIR__"mudi",
            "south"    : __DIR__"fen0", 
            "north"    :__DIR__"grass2",
        ]));
********************************************/
};


ROOM_END;
