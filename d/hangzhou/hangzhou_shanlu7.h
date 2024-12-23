//shanlu7.h

//Sample for room: 杭州山路7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路7");
	
	add_npc("pub_playboy");         //add by zdn 2001-07-14


	add_door("杭州玉皇山顶", "杭州玉皇山顶", "杭州山路7");
	add_door("杭州玉皇山脚", "杭州玉皇山脚", "杭州山路7");

	set("long"," 山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁是涵碧亭，在这里极目远眺，群山环湖尽收眼底。西边是上山的路，往东便是下山的路。");

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
