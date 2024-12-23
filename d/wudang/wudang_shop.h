//shop.h

//Sample for room: 小吃店
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小吃店");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("武当石梁", "武当石梁", "武当小吃店");


/*****************************************************
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
*****************************************************/
};


ROOM_END;
