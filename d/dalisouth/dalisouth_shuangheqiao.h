//shuangheqiao.h

//Sample for room: 双鹤桥
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shuangheqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "双鹤桥");

	add_npc("pub_playboy");
	add_npc("pub_playboy");    // add by zdn 2001-07-13

	add_door("大理城大路4", "大理城大路4", "大理城双鹤桥");
	add_door("大理城南门", "大理城南门", "大理城双鹤桥");
	add_door("大理城绿玉溪沿岸", "大理城绿玉溪沿岸", "大理城双鹤桥");

	set("long", "这是一个岔路口，北边是座青石拱桥名叫双鹤桥，此桥跨在绿玉溪上，桥北即是大理城，由此南去是通往南方的喜州、龙口等城镇的官道，东去的岔路通往广西，沿绿玉溪南岸西行可达五华楼。" );
	
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
