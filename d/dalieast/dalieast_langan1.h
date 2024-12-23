//langan1.h

//Sample for room: 大理城杆栏
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城杆栏");

	//add npcs into the room
//	add_npc("animal_shanyang");
        add_npc("dali_guigongzi");         //add by zdn 2001-07-20
	
	add_door("大理城农田2", "大理城农田2", "大理城杆栏");

	set("long", "摆夷族大多依树积木以居其上，就是杆栏，在夷语里叫做榔盘。其构造大致略似楼，侧面开门，有梯可上下，上阁如车盖状，中层住人，这里是下层，一般为牛羊圈。" );
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
