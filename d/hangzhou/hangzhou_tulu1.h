//tulu1.h

//Sample for room: 杭州土路
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_tulu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州土路");

	//add npcs into the room
	add_npc("pub_boy");

	add_door("杭州茅家埠", "杭州茅家埠", "杭州土路");
	add_door("杭州山路5", "杭州山路5", "杭州土路");

	set("long","路旁一条小溪。溪水哗哗地流着，不时有鱼儿(fish)跃出水面。溪旁几各男孩正低着头专心在钓鱼。" );


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
