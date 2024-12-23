//cuiweiting.h

//Sample for room: 杭州翠微亭
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_cuiweiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州翠微亭");
	
	add_npc("pub_youke");         // add by zdn 2001-07-14
	add_npc("pub_shangguannanyan");
	add_door("杭州清林洞", "杭州清林洞", "杭州翠微亭");

	set("long","翠微亭建在飞来峰的半山间，是名将韩世忠为纪念岳飞而建的。岳飞有“经年尘土满征衣，特特寻芳上翠微”的诗句，故亭名“翠微”。西边是下山的路。" );

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
