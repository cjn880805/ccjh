//songyueta.h

//Sample for room: 嵩岳塔
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_songyueta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嵩岳塔");
	
	 add_npc("songshan_bu");         //add by zdn 2001-07-20


//	add_door("嵩山嵩岳寺", "嵩山嵩岳寺", "嵩山嵩岳塔");

	set("long", "这里原是北魏离宫。孝明帝舍为佛院，至隋方有今名，寺围阔大，僧舍连云。院内风动旌扬，松摇竹乱，别有一般清静。 " );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
********************************************/
};


ROOM_END;
