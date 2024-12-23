//taiheju2.h

//Sample for room: 太和居二楼
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_taiheju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "太和居二楼");

	//add npcs into the room
	add_npc("pub_genu");/////////////////////////

	add_door("大理城太和居", "大理城太和居", "大理城太和居二楼");

	set("long", "这是大理城内最大的酒楼，楼下卖些大理的小吃，过往行人常常买来作路菜。楼上是雅座。" );

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
