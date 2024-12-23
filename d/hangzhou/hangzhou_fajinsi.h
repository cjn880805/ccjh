//fajinsi.h

//Sample for room: 杭州法净寺
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fajinsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州法净寺");

	//add npcs into the room
	add_npc("pub_shami");/////////////////////////
	add_npc("pub_guest");

	add_door("杭州山路3", "杭州山路3", "杭州法净寺");
	add_door("杭州山路2", "杭州山路2", "杭州法净寺");

	set("long","法净寺依山而立，寺前小溪流水。进香的游客不时的进进出出。南上往上天竺。朝北是下山的路。" );


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
