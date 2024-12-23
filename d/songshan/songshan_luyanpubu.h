//luyanpubu.h

//Sample for room: 芦岩瀑布
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_luyanpubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "芦岩瀑布");

	add_npc("shaolin_wuying");

	add_door("嵩山山道1", "嵩山山道1", "嵩山芦岩瀑布");
	add_door("嵩山铁梁峡", "嵩山铁梁峡", "嵩山芦岩瀑布");

	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
********************************************/
};


ROOM_END;
