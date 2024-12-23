//songyuesi.h

//Sample for room: 嵩岳寺
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShongShan_songyuesi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嵩岳寺");
	
	 add_npc("songshan_wan");         //add by zdn 2001-07-20


	add_door("嵩山山道3", "嵩山山道3", "嵩山嵩岳寺");
	add_door("嵩山山道4", "嵩山山道4", "嵩山嵩岳寺");
//	add_door("嵩山嵩岳塔", "嵩山嵩岳塔", "嵩山嵩岳寺");

	set("long", "这里原是北魏离宫。孝明帝舍为佛院，至隋方有今名，寺围阔大，僧舍连云。院内风动旌扬，松摇竹乱，别有一般清静。" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
********************************************/
};


ROOM_END;
