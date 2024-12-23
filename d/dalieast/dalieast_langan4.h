//langan4.h

//Sample for room: 大理城杆栏4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城杆栏4");

	//add npcs into the room
	add_npc("pub_fangshanu");

//	add_door("大理城杆栏3", "大理城杆栏3", "大理城杆栏4");

	set("long", "这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉自己部族特有的神明，家家户户都居中室设案供奉。中层的其余房间则为寝所。此屋靠窗摆了一部纺纱机。" );

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
