//gumu_mumen.h

//Sample for room: 古墓墓门
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_mumen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓墓门");

	add_npc("gumu_sun");

	add_door("古墓草地", "古墓草地", "古墓墓门");
	add_door("古墓前厅", "古墓前厅", "古墓墓门");
	add_door("古墓黄沙岭", "古墓黄沙岭", "古墓墓门");

    set("long","你走过了草地，眼前突然了一片开阔地，突兀地耸立着一座大墓，墓上砌的石头已经班驳了，看的出来这是座古墓。墓前没有立碑，也没有任何的标记，不知道这是前朝哪位王公大臣的墓穴。墓门口被一块黑黝黝的大石头(shi)封闭得丝毫不透。" );
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
