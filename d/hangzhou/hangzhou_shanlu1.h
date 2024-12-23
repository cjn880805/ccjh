//shanlu1.h

//Sample for room: 杭州山路1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路1");
	
	add_npc("pub_xiaozei");           //add by zdn 2001-07-14


	add_door("杭州法镜寺", "杭州法镜寺", "杭州山路1");
	add_door("杭州青石大道2", "杭州青石大道2", "杭州山路1");

	set("long","一条被人走出来的山路，弯弯曲曲地向上延伸。走在山路上，只见两旁峰峦秀丽，景色怡人。不时有进香客擦肩而过。南上便到了下天竺。北下就是大道。" );
 
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
