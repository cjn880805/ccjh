//zhulou1.h

//Sample for room: 竹楼下
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "竹楼下");

	//add npcs into the room
//	add_npc("animal_cow");
	add_npc("animal_dog");           //add by zdn 2001-07-13
	
	add_door("大理城武定镇", "大理城武定镇", "大理城竹楼下");

	set("long", "台夷人喜居竹林深处，房舍自然少不了用竹子搭成，竹为梁，竹为墙，竹楼建的相当精致。下层基本上只是四根柱子架空的，既可以作兽圈，也为了防蛇。一架竹梯通向上层的房舍。" );
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
