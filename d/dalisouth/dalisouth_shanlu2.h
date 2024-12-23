//shanlu2.h

//Sample for room: 山路2
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路2");

	add_npc("pub_playboy");
	add_npc("pub_guniang");   // add by zdn 2001-07-13

	add_door("大理城山路4", "大理城山路4", "大理城山路2");
	add_door("大理城拈花寺", "大理城拈花寺", "大理城山路2");
	add_door("大理城碧罗雪山", "大理城碧罗雪山", "大理城山路2");
	add_door("大理城山路3", "大理城山路3", "大理城山路2");

	set("long", "这是一座普通样式的台夷竹楼，建在鲁望镇中心，与四周其它竹楼比占地广大得多，也特别高大，似有三层，正是普麽部的祭祀大屋。此处下层也不养牲畜，打扫得干干净净。宽大的竹梯直通上层。" );
	
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
