//nroad1.h

//Sample for room:  Ѫ����ɽ·1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_nroad1);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ɽ·1");
	
	add_npc("pub_jianke");          //add by zdn 2001-07-16

	add_door("Ѫ����ѩɽ·3", "Ѫ����ѩɽ·3", "Ѫ����ɽ·1");
	add_door("Ѫ����ɽ·2", "Ѫ����ɽ·2", "Ѫ����ɽ·1");
	add_door("Ѫ����ɽ·5", "Ѫ����ɽ·5", "Ѫ����ɽ·1");

    

/******************************************************************************
        set("exits",([
                "westup"     : __DIR__"nroad2",
                "southup"    : __DIR__"sroad3",
                "northdown"  : __DIR__"nroad5",
        ]));
        set("outdoors", "xueshan");
******************************************************************************/
};


ROOM_END;
 