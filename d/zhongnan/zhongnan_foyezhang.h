//foyezhang.h

//Sample for room: 终南山佛爷掌
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_foyezhang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山佛爷掌");

	//add npcs into the room 2001-07-10  zdn add
	add_npc("pub_huanu");
	add_npc("pub_youke");

	add_door("终南山神禾原", "终南山神禾原", "终南山佛爷掌");

	set("long","只见此处颇为荒凉，是一处寺院的遗址。四周青松翠柏环绕，寺院的断垣残璧依稀可见，似乎还是一座不小的寺院。往北是一片平原" );

/*****************************************************
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
