//kedian.h

//Sample for room: 客店
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "客店");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("大理城喜州城", "大理城喜州城", "大理城客店");

	set("long", "这是喜州城里唯一的一家客栈，专门接待过往客商，生意非常兴隆。店小二里里外外忙得团团转。此间虽偏远，却不因势坑宰客人，住店一宿只要五两银子。" );
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
