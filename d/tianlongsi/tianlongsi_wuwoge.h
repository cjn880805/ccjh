//wuwoge.h

//Sample for room:  ���������Ҹ�
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wuwoge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������Ҹ�");

	add_npc("dali_xiaoshami");
				
	add_door("������������1", "������������1", "���������Ҹ�");
	add_door("�����������", "�����������", "���������Ҹ�");


/******************************************************************************
        set("exits", ([
            "south": __DIR__"ruihemen",
            "west" : __DIR__"ta1",
        ]));
        set("objects",([
            __DIR__"npc/xiaoshami" : 2,
        ]));
******************************************************************************/
};


ROOM_END;
