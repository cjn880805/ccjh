//nroad7.h

//Sample for room:  Ѫ����ɽ·7
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad7);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·7");

	add_npc("xueshan_shanyong");

	add_door("Ѫ����ɽ·6", "Ѫ����ɽ·6", "Ѫ����ɽ·7");
	add_door("Ѫ����ɽ��", "Ѫ����ɽ��", "Ѫ����ɽ·7");

	set("long","������һɽ·�ϣ�������һ����Сɽ��");

/******************************************************************************
        set("exits",([
                "eastdown" : "/d/xueshan/shanjiao",
                "south"    : __DIR__"nroad6",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/shanyong" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
