//liulangqiao.h

//Sample for room: 杭州柳浪桥
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_liulangqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州柳浪桥");
	
	add_npc("pub_girl");
	add_npc("pub_boy");         // add by zdn 2001-07-14


	add_door("杭州聚景园", "杭州聚景园", "杭州柳浪桥");

	set("long"," 每当春至，站在桥上，沿湖垂柳在风中摇曳如翠浪翻空，黄莺在枝头迎春嬉戏，鸣声婉转，故得名“浪桥闻莺”。    过桥往西走便是白堤了。东北边可通往青石大道");

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
