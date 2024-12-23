//fajingsi.h

//Sample for room: 杭州法镜寺
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fajingsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州法镜寺");

	//add npcs into the room
	add_npc("pub_shami");/////////////////////////
	add_npc("pub_guest");
	add_item("juhua");

	add_door("杭州山路2", "杭州山路2", "杭州法镜寺");
	add_door("杭州山路1", "杭州山路1", "杭州法镜寺");

	set("long","法镜寺建在小溪旁，格外的幽雅。进香的游客不时的进进出出。南上往中天竺。朝北是下山的路。" );

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
