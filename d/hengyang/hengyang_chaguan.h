//chaguan.h

//Sample for room: 衡阳茶馆
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡阳茶馆");


	add_npc("pub_chaboshi");
        add_npc("hengshan1_moju");

	add_door("衡阳城", "衡阳城", "衡阳茶馆");

 	set("resource/water", 1);
/*****************************************************
	set("long", "你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，
这里是个好所在。
 " );
	set("exits", ([
		"north" : __DIR__"hengyang",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));

********************************************/
};


ROOM_END;
