//dawu.h

//Sample for room: 林中大屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dawu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "林中大屋");

	//add npcs into the room
	//add_npc("ye");
	
	add_npc("pub_girl");     //add by zdn 2001-07-14
	
	add_door("灵州林中空地", "灵州林中空地", "灵州林中大屋");

	set("long", "这是一幢原木制成的三层高大建筑，看上去已有些年月但仍坚固异常，底层是由数根巨木架空，一座木梯通向二楼，三楼的楼顶上挂着一面绣着一条青龙的大旗，看上去已破旧不堪。人们只知道主人姓李。");  
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
