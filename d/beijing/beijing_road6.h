//road6.h

//Sample for room: 大驿道6
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大驿道6");


	add_door("北京大驿道7", "北京大驿道7", "北京大驿道6");
	add_door("北京大驿道5", "北京大驿道5", "北京大驿道6");
	add_door("恒山金龙峡", "恒山金龙峡", "北京大驿道6");

	set("long", "你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。从这里远远的就可以望见北京城。西南是通往恒山。" );

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
