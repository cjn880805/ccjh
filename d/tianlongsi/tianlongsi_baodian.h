//baodian.h

//Sample for room:  �����³�ʥ����
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_baodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����³�ʥ����");

				
	add_door("������������1", "������������1", "�����³�ʥ����");


/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "north" : __DIR__"ta1",
	]));
	set("objects",([
                __DIR__"npc/benyin" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
