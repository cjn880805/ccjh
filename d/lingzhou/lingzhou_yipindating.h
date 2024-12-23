//yipindating.h

//Sample for room: 一品堂大厅
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipindating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "一品堂大厅");

	//add npcs into the room
	add_npc("pub_yipinwushi");
	add_npc("lingzhou_yunying");          //add by zdn 2001-07-20

	add_door("灵州西", "灵州西", "灵州一品堂大厅");
	add_door("灵州接引堂", "灵州接引堂", "灵州一品堂大厅");
	add_door("灵州一品堂帐房", "灵州一品堂帐房", "灵州一品堂大厅");


	set("no_fight",1);

};


ROOM_END;
