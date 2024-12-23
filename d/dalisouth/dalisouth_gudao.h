//gudao.h

//Sample for room: 古道
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_gudao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古道");

	add_npc("pub_youke");
	add_npc("pub_playboy");   // add by zdn 2001-07-13

	add_door("大理城绿玉溪沿岸", "大理城绿玉溪沿岸", "大理城古道");
	add_door("大理城山路6", "大理城山路6", "大理城古道");
	add_door("大理城南五华楼", "大理城南五华楼", "大理城古道");

	set("long", "一条石板古道，两边树木苍翠，山势平缓，南面是一望无际的西双版纳大森林。大道北面有一片宏伟建筑，一堵里许长的红墙隔开，越过墙头可见一座高楼耸立，正是大理名胜五华楼。" );
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
