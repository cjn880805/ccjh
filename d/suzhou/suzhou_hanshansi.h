//hanshansi.h

//Sample for room: 寒山寺
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hanshansi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "寒山寺");
	
	add_npc("pub_guest");       //add by zdn 2001-07-16

	add_door("苏州中", "苏州中", "苏州寒山寺");
	add_door("苏州枫桥", "苏州枫桥", "苏州寒山寺");

	set("long", "你走出西门约三十里地，就到了枫桥镇，在唐元和年间，有高僧寒山子曾来此居住，后希迁禅师在此建寺院时，更名寒山寺。唐开元年间，诗人张继赴京应试落第，返途舟船停靠枫桥，赋诗一首：“月落乌啼霜满天，江枫渔火对愁眠，姑苏城外寒山寺，夜半歌声到客船”。从此，诗韵钟声，脍炙人口，寺因诗而名扬天下。" );
	

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
