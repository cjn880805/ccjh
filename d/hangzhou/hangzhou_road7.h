//road7.h

//Sample for room: 杭州青石大道7
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道7");

	//add npcs into the room
	add_npc("quanzhen_youfang");
	
	add_door("杭州山路8", "杭州山路8", "杭州青石大道7");
	add_door("杭州西泠桥", "杭州西泠桥", "杭州青石大道7");
	add_door("杭州青石大道8", "杭州青石大道8", "杭州青石大道7");
	add_door("杭州青石大道6", "杭州青石大道6", "杭州青石大道7");

	set("long"," 大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。大道延伸向西边和东北边。朝北走便是上北山。南边则通往西泠桥。");

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
