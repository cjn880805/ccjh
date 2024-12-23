//suti7.h

//Sample for room: 杭州苏堤7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤7");
	
	add_npc("pub_playboy");   // add by zdn 2001-07-14


	add_door("杭州苏堤6", "杭州苏堤6", "杭州苏堤7");
	add_door("杭州青石大道20", "杭州青石大道20", "杭州苏堤7");

	set("long"," 苏堤是诗人苏东坡在主持浚深西湖时用湖泥和草筑成的。苏东坡曾有诗记述此事；“我在钱塘拓湖渌，大堤士女争昌丰。六桥横绝天汉上，北山始与南屏通。忽惊二十五万丈，老葑席卷苍烟空。”往南便是大道，北边是映波桥。映波桥乃苏堤六桥由至北南的第一座。");

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
