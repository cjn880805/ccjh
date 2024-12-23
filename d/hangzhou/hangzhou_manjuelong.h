//manjuelong.h

//Sample for room: 杭州满觉陇
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_manjuelong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州满觉陇");

	//add npcs into the room
	add_npc("pub_playboy");

	add_door("杭州水乐洞", "杭州水乐洞", "杭州满觉陇");
	add_door("杭州石屋洞", "杭州石屋洞", "杭州满觉陇");

	set("long","山路旁有一个小村落，村落四周桂花成林。每当仲秋，桂花盛开，飘香数里。被称为“金雪世界”。西上是水乐洞，东下石屋洞。" );

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
