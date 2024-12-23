//jingzhuang2.h

//Sample for room: 大理城经幢2
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城经幢2");

//	add_door("大理城经幢1", "大理城经幢1", "大理城经幢2");
//	add_door("大理城经幢3", "大理城经幢3", "大理城经幢2");

	set("long", "为四神坐像，各有表情，衣褶隆起，筋节毕现，肌肉暴起，极富立体感。" );
	
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
