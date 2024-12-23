//longjing.h

//Sample for room: 龙井
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_longjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "龙井");
	
	add_npc("pub_girldizi");      //add by zdn 2001-07-14


	add_door("杭州山路5", "杭州山路5", "杭州龙井");

	set("long","只见井(jing)水澈可见底而且清冷异常。龙井原名龙泓涧，传说此井与海相通，其中必定有龙，祈祷必雨，故名“龙井”。苏东坡曾有诗“人言山佳水亦佳，下有万古蛟龙潭”。井旁建有茶室。往南便回大路。  蒙面人(Mengmian ren)" );
	
	set("resource/water", 1);

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
