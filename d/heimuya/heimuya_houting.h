//houting.h

//Sample for room: 黑木崖后厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_houting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖后厅");

	//add npcs into the room
	add_npc("pub_zishanshizhe");

	add_door("黑木崖成德殿", "黑木崖成德殿", "黑木崖后厅");
	add_door("黑木崖小花园", "黑木崖小花园", "黑木崖后厅");

	set("long", "这里是日月神教的后厅。看上去满是灰尘，但中间有一个瓷碗 (wan)，似乎有古怪。 ");
 
/*****************************************************
        set("exits", ([
                "east" : __DIR__"house1",
                "west" : __DIR__"restroom",
                "south":__DIR__"chengdedian",
        ]));
        set("objects" , ([
             __DIR__"npc/zish" : 4,
        ]));
        set("item_desc", ([
            "wan" : "这是一个自汉代流传下的古董，很别致。\n",
        ]));
********************************************/
};


ROOM_END;
