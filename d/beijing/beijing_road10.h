//road10.h

//Sample for room: 小道10
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_road10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小道10");

	//add npcs into the room
	add_npc("pub_tiaofu");
	
	add_door("北京", "北京", "北京小道10");
	add_door("北京", "北京", "北京小道10");

	set("long", "你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。东边就是大海之滨了。" );
	
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
