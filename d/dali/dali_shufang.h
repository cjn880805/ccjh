//shufang.h

//Sample for room: 书房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "书房");

	add_npc("dali_zhudanchen");	

	add_door("大理城王府内厅", "大理城王府内厅", "大理城王府书房");

	set("long", "这是大理国镇南王的书房，靠窗放着一个大木桌桌上放着不少书，靠墙的地方还有一个书架，镇南王经常在这里看书。" );

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
