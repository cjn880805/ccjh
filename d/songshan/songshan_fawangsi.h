//fawangsi.h

//Sample for room: 法王寺
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRSongShan_fawangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "法王寺");

	add_npc("pub_zhenfang");
	add_door("嵩山塔院", "嵩山塔院", "嵩山法王寺");
	add_door("嵩山月台", "嵩山月台", "嵩山法王寺");
	add_door("嵩山山道4", "嵩山山道4", "嵩山法王寺");
	add_door("嵩山山道5", "嵩山山道5", "嵩山法王寺");

	set("long", "法王寺北山坡上，是法王寺塔院。院内有十五层密檐方塔，高近二十丈，造型优美。院内其它三座单檐墓塔，亦玲珑秀丽。" );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"fawangsi",
	]));
	set("outdoors", "songshan");
********************************************/
};


ROOM_END;
