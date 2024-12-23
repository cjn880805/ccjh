//qsjie2.h

//Sample for room:  峨嵋青石阶
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_qsjie2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋青石阶");

	add_npc("pub_jianke");     // add by zdn 2001-07-14
				
	add_door("峨嵋报国寺山门", "峨嵋报国寺山门", "峨嵋青石阶");	
	add_door("峨嵋小路", "峨嵋小路", "峨嵋青石阶");
	add_door("大理城官道1", "大理城官道1", "峨嵋青石阶");
	add_door("万劫谷江边小路1", "万劫谷江边小路1", "峨嵋青石阶");		

	set("long","已经是峨嵋山脚下了。南面一条通往峨嵋的青石阶，两旁绿树荫蔽，空气十分清新。西南方通向南诏的大理国。西边好象有人搭了个小草棚。");

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
