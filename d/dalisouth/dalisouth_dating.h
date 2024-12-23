//dating.h

//Sample for room: 大厅
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大厅");

	//add npcs into the room
	add_npc("pub_zishanshizhe");
	add_npc("pub_zishanshizhe");
	add_npc("pub_zishanshizhe");
	
	add_door("大理城古道", "大理城古道", "大理城大厅");

	set("long", "这里是五华楼的前大厅，异常宽敞明亮，足有一里见方，全是云石铺地，黑白相间，足足可以容纳二、三千人。时时可见锦衣侍者手托美食来回行走。" );
	
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
//last, register the room into ../server/RoomSetup.cpp