//caodi.h

//Sample for room: 古墓草地
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_caodi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓草地");

	add_npc("animal_dushe");

	add_door("古墓树林2", "古墓树林2", "古墓草地");
	add_door("古墓墓门", "古墓墓门", "古墓草地");
	add_door("古墓草地2", "古墓草地2", "古墓草地");

    set("long","这里是一片草地，草很深，几乎淹没了小腿。草间散布着一些奇花，微风吹过，芬芳扑鼻。你听到时而有“嗡嗡嗡”的声音，看见有一些个头奇大的白色的蜜蜂在草地上飞舞盘旋。" );

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
