//shan_road3.h

//Sample for room: 山路3
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_shan_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路3");


	add_door("万劫谷山路2", "万劫谷山路2", "万劫谷山路3");
	add_door("万劫谷山路4", "万劫谷山路4", "万劫谷山路3");

	set("long","这是一条山间小路，两边山坡上张了许多树木，北风吹过，发出沙沙的响声。路上张着许多杂草，看起来这里很少有人走动。往西看，远远可见黑压压一片大森林。");
    
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
