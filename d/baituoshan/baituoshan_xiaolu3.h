//xiaolu3.h

//Sample for room: 白驼山小路3
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山小路3");

	set("monster_chance", 1);
	//add npcs into the room
	add_npc("pub_shanzei1");
	
	add_door("白驼山小路2", "白驼山小路2", "白驼山小路3");
	add_door("白驼山小路4", "白驼山小路4", "白驼山小路3");

	set("long", "这里是一条上山的小路。东北方有山贼出没，要格外小心。");

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
