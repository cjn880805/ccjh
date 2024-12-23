//dongjie.h

//Sample for room: 白驼山东街
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dongjie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山东街");

	//add npcs into the room
	add_npc("pub_playboy");
	add_npc("helpnpc005");

	add_door("白驼山戈壁", "白驼山戈壁", "白驼山东街");
	add_door("白驼山西街", "白驼山西街", "白驼山东街");
	add_door("白驼山小路1", "白驼山小路1", "白驼山东街");
	add_door("白驼山打铁铺", "白驼山打铁铺", "白驼山东街");

	set("long", "这里是小镇的东街。南边有个打铁铺，里面传来丁丁当当的声音。东南方是荒凉的戈壁，东北方有条小路可上山。");

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
