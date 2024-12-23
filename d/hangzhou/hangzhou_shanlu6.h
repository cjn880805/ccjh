//shanlu6.h

//Sample for room: 杭州山路6
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路6");

	//add npcs into the room
	add_npc("animal_laofu");

	add_door("杭州玉皇山", "杭州玉皇山", "杭州山路6");
	add_door("杭州玉皇山顶", "杭州玉皇山顶", "杭州山路6");

	set("long"," 山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁有一山洞，据说洞里有时会传出虎哮声，故名老虎洞。西边是下山的路，往东下山便到了山底。");

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
