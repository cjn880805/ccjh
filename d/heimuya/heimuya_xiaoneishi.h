//xiaoneishi.h

//Sample for room: 小舍内室
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaoneishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小舍内室");

	//add npcs into the room
	add_npc("heimuya_dongfang");

	add_door("黑木崖小舍", "黑木崖小舍", "黑木崖小舍内室");

	set("long", "这里是小舍内室。收拾得精细异常。你一进去，就发现床沿坐着一个打扮妖艳的人。那人也诧异地抬头，你发现他居然是个男人，手里执着一枚绣花针！");

/*****************************************************
        set("exits", ([
             "west" : __DIR__"xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
        ]));
//                              
********************************************/
};


ROOM_END;
