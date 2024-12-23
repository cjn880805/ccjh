//sroad7.h

//Sample for room:  Ѫ���Ŵ�ѩɽ��7
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad7);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ���Ŵ�ѩɽ��7");

	add_npc("pub_caiyaoren");

	add_door("Ѫ���Ŵ�ѩɽɽ��8", "Ѫ���Ŵ�ѩɽɽ��8", "Ѫ���Ŵ�ѩɽ��7");
	add_door("Ѫ���Ŵ�ѩɽ��6", "Ѫ���Ŵ�ѩɽ��6", "Ѫ���Ŵ�ѩɽ��7");

    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad6",
                "southup"   : __DIR__"sroad8",
        ]));
        set("objects",([
                __DIR__"npc/caiyaoren": 1,
        ]));
******************************************************************************/
};


ROOM_END;
