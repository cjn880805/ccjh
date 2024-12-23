//road13.h

//Sample for room: 杭州青石大道13
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道13");
	
	
	add_npc("pub_daoke");
	add_npc("pub_jianke");           // add by zdn 2001-07-14


	add_door("杭州青石大道14", "杭州青石大道14", "杭州青石大道13");
	add_door("杭州青石大道12", "杭州青石大道12", "杭州青石大道13");
	add_door("杭州天外天客店", "杭州天外天客店", "杭州青石大道13");

	set("long","沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太平热闹景象。街东边有一家客店。" );

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
