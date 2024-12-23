//luyuxi.h

//Sample for room: 绿玉溪沿岸
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_luyuxi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "绿玉溪沿岸");

	add_npc("pub_girl1");
	add_npc("pub_playboy");   // add by zdn 2001-07-13

	add_door("大理城古道", "大理城古道", "大理城绿玉溪沿岸");
	add_door("大理城双鹤桥", "大理城双鹤桥", "大理城绿玉溪沿岸");

	set("long", "一条颇宽敞的土路沿着绿玉溪南岸横贯东西，一边是涓涓溪流碧波荡漾，另一边是青山翠柳，郁郁葱葱的林木。东面有桥渡溪通向大理城南门，西去不远就是五华楼了。" );
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
