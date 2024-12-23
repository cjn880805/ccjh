//taiyi.h

//Sample for room: 终南山太乙池
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_taiyi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山太乙池");

	//add npcs into the room   2001-07-10 zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");
	add_npc("pub_manxiangke");

	add_door("终南山山道3", "终南山山道3", "终南山太乙池");

	set("long","你眼前出现一个山间湖泊，这就是著名的太乙池 (chi)，传为唐天宝年间地震造成，四周高峰环列，池面碧波荡漾，山光水影，风景十分优美。" );

};


virtual int do_look(CChar * me)
{
	say("你眼前出现一个山间湖泊，这就是著名的太乙池 (chi)，传为唐天宝年间地震造成，四周高峰环列，池面碧波荡漾，山光水影，风景十分优美。" ,me);
	if (me->query_temp("gumu/tan"))
	{
		say("就在这山水之间，一块岩石并不显目的突出在池边，你走近岩石往下一看，云雾缭绕处显露出眼前深不可测的悬崖，跳下去(tiao)的冲动立刻截然而止。" ,me);
	}
	SendMenu(me);
	return 1;
}


virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if (strcmp(comm, "tiao") == 0)
	{
		if(me->query_temp("gumu/tan") )
		{
			message_vision("$N壮了壮胆，眼睛一闭，屏住呼吸向下一跳……", me);
			if(random(2))
			{
				me->set_temp("gumu/ask",1);
				me->delete_temp("gumu/tan");
				me->move(load_room("终南山翠屏谷底"));
			}
			else
				me->move(load_room("终南山小河边"));		
			me->unconcious();
			return 1;
		}
	}
	return 0;
}

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp




