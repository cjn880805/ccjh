//shanlu6.h

//Sample for room: 山路6
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路6");

	add_npc("pub_daoke");
	add_npc("pub_nongfu2");    // add by zdn 2001-07-13

	add_door("大理城古道", "大理城古道", "大理城山路6");
	add_door("大理城山路5", "大理城山路5", "大理城山路6");

	set("long", "一条山路，两边是茂密的树林，西面是延绵不绝的大山，南面是一望无际的西双版纳大森林，传说有邪教教众在其中活动。道路两旁间或可见一些夷族的村镇。山路转向东蜿蜒着。" );
	
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
