//guancaidian.h

//Sample for room: 棺材店
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_guancaidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "棺材店");

	//add npcs into the room
	add_npc("shaolin_gaoyanch");
	
	add_door("北京西南", "北京西南", "北京棺材店");

	set("long", "这是一家棺材店，一进门，一股楠木味扑鼻而来。屋子里很阴暗，桌子椅子都很破旧。往东是一间内室，一个三十出头的精壮汉子挡在门口。" );

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
