//yuquan.h

//Sample for room: 杭州玉泉
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州玉泉");

	//add npcs into the room
	add_npc("pub_youke2");
	add_npc("pub_jiaojindaoren");

	add_door("杭州青石大道5", "杭州青石大道5", "杭州玉泉");

	set("long","玉泉寺建在玉泉山上，原名清涟寺。走进玉泉寺，只见这里有几个水池(pond)。朝东就是出寺下山的路。");
    

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
