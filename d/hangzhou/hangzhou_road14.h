//road14.h

//Sample for room: 杭州青石大道14
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道14");
	
	add_npc("pub_playboy");      // add by zdn 2001-07-14


	add_door("杭州清波门", "杭州清波门", "杭州青石大道14");
	add_door("杭州胡庆余堂", "杭州胡庆余堂", "杭州青石大道14");
	add_door("杭州青石大道13", "杭州青石大道13", "杭州青石大道14");
	add_door("杭州青石大道15", "杭州青石大道15", "杭州青石大道14");

	set("long"," 沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太平热闹景象。西边有一花园，游人进进出出，十分热闹。东边是名医胡庆余开的药铺。    过桥往西走便是白堤了。东北边可通往青石大道");

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
