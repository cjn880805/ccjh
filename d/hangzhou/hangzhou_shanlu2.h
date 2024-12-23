//shanlu2.h

//Sample for room: 杭州山路2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州山路2");

	//add npcs into the room
	add_npc("honghua_honghua1");
	
	add_door("杭州法净寺", "杭州法净寺", "杭州山路2");
	add_door("杭州法镜寺", "杭州法镜寺", "杭州山路2");

	set("long","走在这条不是很宽的山路上，只见两旁峰峦秀丽，景色怡人。一条小溪在路边潺潺流过，溪畔有一农家。山村小景，使人有退隐江湖之意。南上便到了中天竺。北下就是下天竺。" );

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
