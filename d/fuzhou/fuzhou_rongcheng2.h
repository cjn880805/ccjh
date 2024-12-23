//rongcheng2.h

//Sample for room: 榕城驿二楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_rongcheng2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "榕城驿二楼");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13

	add_door("福州榕城驿", "福州榕城驿", "福州榕城驿二楼");

	set("long", "这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，不少客人正和衣而卧，满屋子都是呼呼的打酣声。你看到西边有张床是空的，就蹑手蹑脚地走了过去。" );

	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);
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
