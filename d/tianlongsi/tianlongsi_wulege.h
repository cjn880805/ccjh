//wulege.h

//Sample for room:  ���������ָ�
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wulege);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������ָ�");


	add_door("�����»�����", "�����»�����", "���������ָ�");
	add_door("�����������", "�����������", "���������ָ�");

    

/******************************************************************************
        set("exits", ([
            "north": __DIR__"xianghemen",
            "east" : __DIR__"huangtianmen",
	]));
	set("objects",([
             __DIR__"npc/xiaoshami" : 2,
        ]));
******************************************************************************/
};


ROOM_END;
