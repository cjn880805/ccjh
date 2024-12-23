//yuxuguanqian.h

//Sample for room: 大理城玉虚观前
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_yuxuguanqian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城玉虚观前");

	//add npcs into the room
	add_npc("pub_xiaodaogu");
	
	add_door("大理城蝴蝶泉", "大理城蝴蝶泉", "大理城玉虚观前");
	add_door("大理城玉虚观", "大理城玉虚观", "大理城玉虚观前");

	set("long", "东面一座庙观，门前匾上写着“玉虚观”三个大字，西边一个碧水荡漾的小湖，四周绿柳成荫，实乃修心养性的好地方。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
