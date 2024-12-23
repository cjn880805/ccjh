//gongling.h

//Sample for room: 灵州恭陵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRlingzhou_wuminggu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州无名谷");

	add_item("mitao");
	add_item("mitao");
	add_item("mitao");
	add_item("mitao");
	add_item("mitao");
	add_item("mitao");
	//add_npc("gumu_yangguo");
	//add_npc("pub_xiangke");
//	add_door("灵州陵下", "灵州陵下", "灵州无名谷");
	set("valid_startroom", 1);

	set("long", "这是西夏先主拓跋思恭的陵墓，拓跋思恭当年率党项羌族归顺唐太宗李世民而被赐姓为李，这李思恭在唐初也是极有名的大将。如今因为年代久远他的陵墓也不复当年的雄伟而看上去有点破败。");  
	
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




