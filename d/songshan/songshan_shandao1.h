//shandao1.h

//Sample for room: 山道1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山道1");
	
	add_npc("pub_tiaofu");          // add by zdn 2001-07-15


	add_door("嵩山中岳大殿", "嵩山中岳大殿", "嵩山山道1");
	add_door("嵩山芦岩瀑布", "嵩山芦岩瀑布", "嵩山山道1");
	add_door("嵩山启母石", "嵩山启母石", "嵩山山道1");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"dadian",
		"northwest" : __DIR__"qimushi",
		"northeast" : __DIR__"luyanpubu",
	]));
********************************************/
};


ROOM_END;
