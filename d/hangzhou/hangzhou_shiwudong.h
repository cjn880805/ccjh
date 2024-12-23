//shiwudong.h

//Sample for room: 杭州石屋洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shiwudong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州石屋洞");

	//add npcs into the room
////	add_npc("animal_xiezi");
        add_npc("pub_boy");               // add by zdn 2001-07-14

	add_door("杭州满觉陇", "杭州满觉陇", "杭州石屋洞");
	add_door("杭州青石大道18", "杭州青石大道18", "杭州石屋洞");

	set("long","山路旁是石屋洞。石屋洞，洞中有洞，洞洞相连。主洞高大宽敞，洁净明亮，上宽下窄，状如浮螺。西上便到了满觉陇；山路的尽头连着一条由北至南的大道。" );
    

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
