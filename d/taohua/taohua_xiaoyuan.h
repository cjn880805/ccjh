//xiaoyuan.h

//Sample for room: 桃花山庄小院
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiaoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花山庄小院");
	
	add_npc("taohua_yan"); 
	add_npc("taohua_binv");       //add by zdn 2001-07-20


	add_door("桃花岛山庄正厅", "桃花岛山庄正厅", "桃花山庄小院");
	add_door("桃花岛厨房", "桃花岛厨房", "桃花山庄小院");
	add_door("桃花岛小屋", "桃花岛小屋", "桃花山庄小院");
	add_door("桃花岛思过室", "桃花岛思过室", "桃花山庄小院");

    

/*****************************************************
    set("exits", ([
        "north" : __DIR__"damen",
        "south" : __DIR__"dating",
        "east"  : __DIR__"bingqi",
        "west"  : __DIR__"chufang",
    ]));
    set("outdoors", "taohua");
********************************************/
};


ROOM_END;
