//xiaowu2.h

//Sample for room: 孙婆婆小屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_xiaowu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "孙婆婆小屋");

	//add npcs into the room
//	add_npc("pub_sun");
	add_npc("pub_lady3");                  //add by zdn 2001-07-01--14

	CBox * box = Add_Box();
	box->add_object("ping", 1);	
	box->set_name( "铁柜");	
	
	add_door("古墓蜂屋", "古墓蜂屋", "古墓孙婆婆小屋");

	set("long","这里是远离正厅的一间小屋，收拾得整整洁洁一尘不染。摆设就如普通人家一般，红木的桌椅，细磁的杯壶，沉香的大床。你简直想象不到这幽深的古墓之中还有这等摆设。" );

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
