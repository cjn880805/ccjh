//xiaohebian.h

//Sample for room: 终南山小河边
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_xiaohebian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山小河边");

	add_npc("pub_huanu");          //2001-07-10  zdn add
	add_npc("pub_youke");

	add_door("终南山山间小径16", "终南山山间小径16", "终南山小河边");

	set("long","此处位於终南山角一偏僻处，只见浓荫匝地，花光浮动，周围尽是叁天古木，颇具幽静之美。不远处的小河由山洞(dong)中涌出的泉水所形成，淙淙的水声更让你觉得身心顺畅。往北可通往山林深处。往西可进入山洞中。." );

/*****************************************************
        set("item_desc", ([
                "dong" : "一个深邃、幽暗、恐怖的小山洞。\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong",
                "north" : __DIR__"shanlu16",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
