//duchang.h

//Sample for room: 赌场
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "赌场");


	add_door("北京西北", "北京西北", "北京赌场");

	set("long", " 这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。北边是赌「大小」的房间，墙上挂着一块牌子(paizi)。楼上可以拱猪. 一进门，只见房中人声嘈杂，十分混乱。有一桌围着一群人，其中一胖一瘦两个头陀十分惹眼。一个老叫化正和他们赌得起劲。" );
	

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
