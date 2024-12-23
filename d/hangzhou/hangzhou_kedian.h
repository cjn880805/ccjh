//kedian.h

//Sample for room: 天外天客店
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天外天客店");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("杭州青石大道13", "杭州青石大道13", "杭州天外天客店");
	add_door("杭州天外天客店二楼", "杭州天外天客店二楼", "杭州天外天客店");

	set("long","这是杭州最有名的客店，里面雕梁画壁，装饰有如宫殿，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调的客人。墙上挂着一个牌子(paizi)。" );
	
	set("no_fight", 1);
    set("valid_startroom", 1);
    set("sleep_room",1);
	

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
