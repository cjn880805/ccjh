//yuhuangsj.h

//Sample for room: 杭州玉皇山脚
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangsj);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州玉皇山脚");

	//add npcs into the room
	add_npc("honghua_honghua1");
	add_npc("honghua_honghua1");

	add_door("杭州山路7", "杭州山路7", "杭州玉皇山脚");
	add_door("杭州青石大道15", "杭州青石大道15", "杭州玉皇山脚");

	set("long"," 只见往上的山路曲折蜿延。山路旁有一座小六角亭，几个游人正在亭里歇脚。东北边是一条青石大道，往西是上山的路。");
    

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
