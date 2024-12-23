//yangcanfang.h

//Sample for room: 养蚕房
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaliEast_yangcanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "养蚕房");

	//add npcs into the room
	add_npc("pub_yangcannu");
	
	add_door("大理城步雄部", "大理城步雄部", "大理城养蚕房");

	set("long", "这是一间摆夷族的杆栏民居，此间下层却没有牛羊，三面用竹席围住，似一个棚屋，中置数座竹架竹盘，饲养着一些桑蚕。一位摆夷姑娘正在用新鲜的桑叶喂养桑蚕。" );

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
