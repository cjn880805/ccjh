//road5.h

//Sample for room: 杭州青石大道5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道5");

	//add npcs into the room
	add_npc("honghua_honghua1");
	add_npc("pub_tiaofu");

	add_door("杭州玉泉", "杭州玉泉", "杭州青石大道5");
	add_door("杭州青石大道6", "杭州青石大道6", "杭州青石大道5");
	add_door("杭州沿湖大道1", "杭州沿湖大道1", "杭州青石大道5");
	add_door("杭州青石大道4", "杭州青石大道4", "杭州青石大道5");

	set("long","大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。往西是去玉泉寺的路。大道则延伸向东边和西南边。");

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
