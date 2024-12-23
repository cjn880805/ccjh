//shanlu5.h

//Sample for room: 杭州山路5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路5");

	//add npcs into the room
	add_npc("pub_caichanu");
	
	add_door("杭州土路", "杭州土路", "杭州山路5");
	add_door("杭州龙井", "杭州龙井", "杭州山路5");
	add_door("杭州山路4", "杭州山路4", "杭州山路5");
	add_door("杭州烟霞洞", "杭州烟霞洞", "杭州山路5");

	set("long","走在小路上，只见漫山遍野都是绿油油的茶蓬。农家少女们在欢笑声中采茶。山路延伸向东西两边，北边就是龙井，东北边有一条土路。" );

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
