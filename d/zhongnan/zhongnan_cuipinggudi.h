//zhongnan_cuipinggudi.h 终南山翠屏谷底
//秦波 2002、3、14

ROOM_BEGIN(CRZhongNan_cuipinggudi);

virtual void create()			
{
	set_name( "终南山翠屏谷底");

	add_npc("gumu_lin");

//	add_door("终南山翠屏谷", "终南山翠屏谷", "终南山翠屏谷底");

};


virtual int do_look(CChar * me)
{
	say("这是终南山下翠屏谷。绿竹幽幽，茂树浓荫。阳光透过枝丫萝蔓间的缝隙撒落到满地翠微上,令人直欲躺下小息片刻。" ,me);
	if (me->query_temp("gumu/tan"))
	{
		say("侧旁的山崖上似乎布满了青色的蔓藤，你可以试着爬(pa)上去。" ,me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (me->query_temp("gumu/tan") && strcmp(comm, "pa") == 0)
	{
		message_vision("$N手足并用，顺着山崖上长长的蔓藤爬了上去。……", me);
		me->move(load_room("终南山翠屏谷"));
		return 1;
	}
	return 0;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp




