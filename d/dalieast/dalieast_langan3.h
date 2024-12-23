//langan3.h

//Sample for room: 大理城杆栏3
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城杆栏3");

	//add npcs into the room
	add_npc("pub_yangcannu");
	
	add_door("大理城农田5", "大理城农田5", "大理城杆栏3");
	add_door("大理城步雄部", "大理城步雄部", "大理城杆栏3");

	set("long", "一间摆夷族的杆栏民居，此间下层没有牛羊，却用竹席围成一个养桑蚕的小棚屋，有竹架竹盘。楼上传来阵阵纺纱机的梭飞声。" );
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
