//suti1.h

//Sample for room: 杭州苏堤1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤1");
	
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");               //add by zdn 2001-07-14

	add_door("杭州青石大道6", "杭州青石大道6", "杭州苏堤1");
	add_door("杭州苏堤2", "杭州苏堤2", "杭州苏堤1");

	set("long"," 苏堤是诗人苏东坡在主持浚深西湖时用湖泥和草筑成的。苏东坡曾有诗记述此事；“我在钱塘拓湖渌，大堤士女争昌丰。六桥横绝天汉上，北山始与南屏通。忽惊二十五万丈，老葑席卷苍烟空。”往北便是大道，南边是跨虹桥。跨虹桥乃苏堤六桥由北至南的第一座。桥一边是岳湖，桥的另一边是西湖。");

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
