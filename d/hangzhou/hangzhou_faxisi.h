//faxisi.h

//Sample for room: 杭州法喜寺
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_faxisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州法喜寺");

	//add npcs into the room
	add_npc("pub_guest");
	
	add_door("杭州山路4", "杭州山路4", "杭州法喜寺");
	add_door("杭州山路3", "杭州山路3", "杭州法喜寺");

	set("long","法喜寺是天竺三寺中最敞朗深幽的一座。进香的游客不时的进进出出。往东可达龙井，朝北是下山的路。" );


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
