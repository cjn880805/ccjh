//zhufeng.h

//Sample for room: 终南山主峰
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_zhufeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山主峰");

	add_npc("pub_youke");   // add by zdn 2001-07-13

	add_door("古墓山路", "古墓山路", "古墓终南山主峰");
	add_door("终南山山路4", "终南山山路4", "古墓终南山主峰");

	set("long","此时你已身在终南山主峰，视野更为广阔。往低望去，群山尽皆匍匐在脚下。重阳宫的翠绿琉瓦在山腰处，晶莹生辉。只见不少殿宇散布於山坳间，景色颇为美妙。一块巨石 (shi)立在一旁，似乎刻了什麽东西。往西和南各是一条山路。");
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
