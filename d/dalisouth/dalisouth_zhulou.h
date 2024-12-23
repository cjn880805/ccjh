//zhulou.h

//Sample for room: 竹楼
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_zhulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "竹楼");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("大理城", "大理城", "大理城竹楼");

	set("long", "一间标准的台夷竹楼，四面墙壁皆是竹子，正中砌了一座正方形的灶台，其内架置着铁炉。夷族传统席地而睡，是以屋内无床，延墙摆有垫褥，屋舍内除了石堆祭台外别无家具。" );
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
