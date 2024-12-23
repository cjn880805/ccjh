//jingzhuang4.h

//Sample for room: 大理城经幢4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城经幢4");


//	add_door("大理城经幢3", "大理城经幢3", "大理城经幢4");
//	add_door("大理城经幢5", "大理城经幢5", "大理城经幢4");

	set("long", "雕有八坐佛，四隅略大，其中东、南两佛面目驳落，容不可辨。坐佛莲花座皆有梵文佛经。经文尾处刻有“慈济和尚--大理人”字样。" );
	
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
