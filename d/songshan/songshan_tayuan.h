//tayuan.h

//Sample for room: 塔院
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_tayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "塔院");
	
	add_npc("songshan_deng");         //add by zdn 2001-07-20
	add_npc("songshan_di");

		

	add_door("嵩山法王寺", "嵩山法王寺", "嵩山塔院");

	set("long", "法王寺北山坡上，是法王寺塔院。院内有十五层密檐方塔，高近二十丈，造型优美。院内其它三座单檐墓塔，亦玲珑秀丽。" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	
	set("outdoors", "songshan");
********************************************/
};


ROOM_END;
