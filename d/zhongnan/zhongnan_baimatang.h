//baimatang.h

//Sample for room: 终南山白马潭
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baimatang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山白马潭");

	//add npcs into the room    20001-07-10 zdn add
	add_npc("pub_huanu");
	add_npc("pub_lady3");

	add_door("终南山山路6", "终南山山路6", "终南山白马潭");

    set("long","这个潭为於终南山主峰一带，一条名叫库峪河的上游。潭边有一块比三间房子还要大的白石头，这石头中间低两头高，石头的前半截伸在水里，後半截留在岸上。由伸在水中的那半截石头下面还不时冒出一串串白沫，老远看去活似一匹腾空欲飞的烈马，因此当地人都叫此潭为白马潭。往北是一条崎岖的山路。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup" : __DIR__"shanlu6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp