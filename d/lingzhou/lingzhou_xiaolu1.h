//xiaolu1.h

//Sample for room: 灵州林中小路1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州林中小路1");


	add_npc("pub_liujue");

	add_door("灵州林中大路1", "灵州林中大路1", "灵州林中小路1");
	add_door("灵州林中小路2", "灵州林中小路2", "灵州林中小路1");

	set("long", "这是陡坡上的一条杂草丛生的羊肠小路，看起来平时没什么人迹，路边开着不知名的野花，两边的松树依然高大、挺拔。阳光透下来照的你身上是斑斑驳驳的影子。");  
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




