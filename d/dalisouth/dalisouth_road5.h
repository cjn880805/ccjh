//road5.h

//Sample for room: 黄土路
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路");

	//add npcs into the room
//	add_npc("animal_yetu");
        add_npc("dali_wuliangdizi");        //add by zdn 2001-07-20
	
	add_door("大理城双鹤桥", "大理城双鹤桥", "大理城黄土路");
	add_door("佛山林间道1", "佛山林间道1", "大理城黄土路");

	set("long", "这里是大理境内，你走在一条黄土大路上，行人多是本地的摆夷族人。也间或有些中原打扮的人事走动，此路北面通向官道，向西北有路通往大理城的南门，东行可达广东佛山。" );
	
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
//last, register the room into ../server/RoomSetup.cpp