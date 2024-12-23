//road1.h

//Sample for room: 杭州青石大道1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道1");
	
	add_npc("pub_playboy");            // add by zdn 2001-07-14


	add_door("杭州灵隐寺", "杭州灵隐寺", "杭州青石大道1");
	add_door("杭州飞来峰", "杭州飞来峰", "杭州青石大道1");
	add_door("杭州青石大道2", "杭州青石大道2", "杭州青石大道1");
	add_door("泉州山路3", "泉州山路3", "杭州青石大道1");

	set("long","大道上挤满了来灵隐寺上香和上飞来峰的游客。北边过了小溪就是灵隐寺了。南边是上飞来峰的路。" );

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
