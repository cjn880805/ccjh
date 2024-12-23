//xiaoting.h

//Sample for room: 小厅
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_xiaoting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小厅");

	add_npc("pub_xier");	//add by lanwood 2001-03-18

	add_door("万劫谷草地", "万劫谷草地", "万劫谷小厅");

	add_door("万劫谷卧室", "万劫谷卧室", "万劫谷小厅");
	add_door("万劫谷石屋", "万劫谷石屋", "万劫谷小厅");
	add_door("万劫谷药房", "万劫谷药房", "万劫谷小厅");


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"grassland",
            "north" : __DIR__"hall",
        ]));
        set("objects", ([
            __DIR__"npc/gan" : 1,
        ]));
*****************************************************/
};


ROOM_END;
