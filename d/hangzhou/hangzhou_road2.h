//road2.h

//Sample for room: 杭州青石大道2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道2");

	//add npcs into the room
	add_npc("pub_xianghuo");
	
	add_door("杭州山路1", "杭州山路1", "杭州青石大道2");
	add_door("杭州青石大道3", "杭州青石大道3", "杭州青石大道2");
	add_door("杭州青石大道1", "杭州青石大道1", "杭州青石大道2");

	set("long","大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西边是灵隐寺和飞来峰。往南是上天竺。" );

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
