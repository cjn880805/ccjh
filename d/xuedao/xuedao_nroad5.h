//nroad5.h

//Sample for room:  Ѫ����ɽ·5
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad5);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·5");



	add_door("Ѫ����ɽ·1", "Ѫ����ɽ·1", "Ѫ����ɽ·5");
	add_door("Ѫ����ɽ·6", "Ѫ����ɽ·6", "Ѫ����ɽ·5");


/******************************************************************************
        set("exits",([
                "northdown" : __DIR__"nroad6",
                "southup"   : __DIR__"nroad1",
                "westup"    : "/d/npc/m_weapon/lianchuishi",
        ]));
        set("objects",([
                __DIR__"npc/eagle" : 2,
        ]));
******************************************************************************/
};


ROOM_END;
