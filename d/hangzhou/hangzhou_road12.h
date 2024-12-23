//road12.h

//Sample for room: 杭州青石大道12
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道12");

	add_npc("pub_playboy");

	add_door("杭州凤池书院", "杭州凤池书院", "杭州青石大道12");
	add_door("杭州青石大道13", "杭州青石大道13", "杭州青石大道12");
	add_door("杭州青石大道11", "杭州青石大道11", "杭州青石大道12");

	set("long"," 沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太平热闹景象。街东边是一古朴书院，书院里不时传来朗朗的笑声。    过桥往西走便是白堤了。东北边可通往青石大道");

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
