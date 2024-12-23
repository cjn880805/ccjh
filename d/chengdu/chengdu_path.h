//path.h

//Sample for room: 溪岸小路
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_path);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "溪岸小路");

	add_npc("pub_girl1");    // zdn 2001-07-12 add
	add_npc("pub_boy");

	add_door("成都杜甫草堂", "成都杜甫草堂", "成都溪岸小路");
	add_door("成都南河桥", "成都南河桥", "成都溪岸小路");

	set("long",	"溪源转北，阵阵水响带着你来到草堂前。站在草堂照壁前，回首浣花溪，想象万红漂坠，少女清歌浣花时节，别是一般滋味。北边就是“万里桥西宅，百花潭北庄”的杜甫草堂了。"	);

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
