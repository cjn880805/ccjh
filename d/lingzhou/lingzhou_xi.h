//nanmen.h

//Sample for room: 灵州西
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xi);

virtual void create()			//Call it when Room Create
{

	set_name( "灵州西");

	//add npcs into the room
	add_npc("pub_xiaowei");/////////////////////////
	add_npc("pub_xixiabing");

	add_npc("pub_playboy");
	add_npc("lingzhou_helian");       //add by zdn 2001-07-20

	add_door("灵州酒馆", "灵州酒馆", "灵州西");
	add_door("灵州刀店", "灵州刀店", "灵州西");
	add_door("灵州骠骑营", "灵州骠骑营", "灵州西");
	add_door("灵州车马店", "灵州车马店", "灵州西");				
	add_door("灵州皇宫大门", "灵州皇宫大门", "灵州西");
	add_door("灵州一品堂大厅", "灵州一品堂大厅", "灵州西");
	add_door("灵州黄羊滩", "灵州黄羊滩", "灵州西");
	add_door("灵州东", "灵州东", "灵州西");

};


ROOM_END;
