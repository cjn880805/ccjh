//mudao.h

//Sample for room: 墓道
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_mudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "墓道");

	add_npc("taohua_huang");
	add_npc("taohua_shoumu");        //add by zdn 2001-07-20


	add_door("桃花岛", "桃花岛", "桃花岛墓道");

	set("long", "这是通往墓室的通道。通道十分宽敞，顶部悬挂着一颗大大的夜明珠，照得整个墓道如同白昼。墓道尽头便是墓室。");
	

/*****************************************************
	set("exits", ([
		"up"   : __DIR__"mudi",
		"down" : __DIR__"mushi",
	]));
********************************************/
};


ROOM_END;
