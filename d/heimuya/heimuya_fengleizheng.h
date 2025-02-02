//fengleizheng.h

//Sample for room: 风雷堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_fengleizheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "风雷堂");

	//add npcs into the room
	add_npc("heimuya_tongbx");  //add zdn by 2001-07-20

	add_door("黑木崖草地", "黑木崖草地", "黑木崖风雷堂");

	set("long", "这是『日月神教』下第一大堂：风雷堂的大厅，四目望去，满朴素的，堂梁上有一副联子(vote)。");

/*****************************************************
        set("exits", ([
            "south" : __DIR__"grass2",
            "northdown" : __DIR__"linjxd5",
        ]));
 
        set("objects",([
            __DIR__"npc/jiaotu" : 2,
        ]));
        set("item_desc", ([
            "vote": "日月神教，文成武德，泽被苍生。\n"
        ]) );
********************************************/
};


ROOM_END;
