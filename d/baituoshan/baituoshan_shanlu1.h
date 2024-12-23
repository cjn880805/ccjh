//shanlu1.h

//Sample for room: 白驼山山路1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山山路1");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("pub_qiaofu");
	
	add_door("白驼山山路", "白驼山山路", "白驼山山路1");
	add_door("白驼山树林", "白驼山树林", "白驼山山路1");

	set("long", "这里是山上的泥路。");

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
