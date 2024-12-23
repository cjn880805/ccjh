//dianchi.h

//Sample for room: 大理城滇池
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城滇池");

	add_npc("pub_youke");
	add_npc("pub_cunfu");   // add by zdn 2001-07-12 
	add_npc("pub_yaoyue");

	add_door("大理城沿池堤岸1", "大理城沿池堤岸1", "大理城滇池");

	set("long", "滇池四周的山脉均属昆仑山系，云岭山脉的东支逶迤南下，总称乌蒙山，有大小数十个山峰。湖身紧靠西山脚下，山环水抱，天光云影，构成天然的图画。滇池的“滇”在彝语中即是大坝子，兼司马迁的《史记·西南夷列传》记载，在古代就是这一地区的最大的部族名称，是名滇池。" );
	
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
