//road5.h

//Sample for room: 大驿道5
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大驿道5");

	//add npcs into the room
	add_npc("pub_bing");

	add_door("北京皇城", "北京皇城", "北京大驿道5");
	add_door("北京大驿道6", "北京大驿道6", "北京大驿道5");
	add_door("黑木崖黄土路3", "黑木崖黄土路3", "北京大驿道5");

	set("long", "你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。北边就是永定门了。" );

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
