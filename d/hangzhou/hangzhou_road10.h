//road10.h

//Sample for room: 杭州青石大道10
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道10");
	
	add_npc("pub_guest");          // add by zdn 2001-07-14


	add_door("杭州楼外楼", "杭州楼外楼", "杭州青石大道10");
	add_door("杭州红娘庄", "杭州红娘庄", "杭州青石大道10");
	add_door("杭州青石大道11", "杭州青石大道11", "杭州青石大道10");
	add_door("杭州青石大道9", "杭州青石大道9", "杭州青石大道10");

	set("long"," 沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太平热闹景象。街的东边是一座酒楼。");

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
