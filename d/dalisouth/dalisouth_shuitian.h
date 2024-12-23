//shuitian.h

//Sample for room: 水田
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shuitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "水田");

	//add npcs into the room
//	add_npc("animal_cow");
	add_npc("pub_nongfu1");


	add_door("大理城鲁望镇", "大理城鲁望镇", "大理城水田");

	set("long", "这是一片低洼平地的农田，除了田埂，全部都被水淹没着，一些普麽部的妇女赤着脚在田里插秧。这个地区雨水充足，虽然没有江河流过，无需特别的灌溉，每至春夏田里自然雨水溢满。" );
	
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
