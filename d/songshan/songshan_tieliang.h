//tieliang.h

//Sample for room: 铁梁峡
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_tieliang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "铁梁峡");
	
	add_npc("songshan_gao");         //add by zdn 2001-07-20


	add_door("嵩山山道5", "嵩山山道5", "嵩山铁梁峡");
	add_door("嵩山芦岩瀑布", "嵩山芦岩瀑布", "嵩山铁梁峡");


/*****************************************************
	set("exits", ([
		"down"    : __DIR__"luyanpubu",
		"northup" : __DIR__"shandao5",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
********************************************/
};


ROOM_END;
