//kedian.h

//Sample for room: 悦来客栈
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRNanYang_kedian);

virtual void create()			
{
	set_name( "悦来客栈");

	add_npc("pub_xiaoer2");

	add_door("南阳城", "南阳城", "南阳悦来客栈");

	set("sleep_room", 1);
	set("valid_startroom", 1);
	set("no_fight", 1);
};


ROOM_END;
