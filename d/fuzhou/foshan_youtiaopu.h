//youtiaopu.h

//Sample for room: 烧饼油条铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_youtiaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "烧饼油条铺");

	add_npc("pub_xiaoer2");   // add by zdn 2001-07-13
	add_npc("wiz_paihangbang");
	add_npc("wiz_shangshanshi");
//	add_npc("wiz_teacher1");

	add_door("佛山", "佛山", "佛山烧饼油条铺");

	set("long", "这家烧饼油条铺是新开张的。铺面不大，正中央摆了一个大炸锅和一个烤炉。" );
	set("outdoors", "foshan");
	set("no_fight",  1);

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
