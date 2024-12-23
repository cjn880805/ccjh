//road8.h

//Sample for room: 大驿道8
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大驿道8");


	add_door("北京大驿道9", "北京大驿道9", "北京大驿道8");
	add_door("北京大驿道4", "北京大驿道4", "北京大驿道8");

	set("long", "你走在一条尘土飞扬的大驿道上。北上就是北京城。挑担子的、行商的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。" );
	
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
