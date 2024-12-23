//fang.h

//Sample for room: 白驼山练功房
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_fang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山练功房");

	//add npcs into the room
	add_npc("pub_trainer");
	add_npc("btshan_tongzi");
	
	add_door("白驼山练功场", "白驼山练功场", "白驼山练功房");

	set("long", "这里是白驼山弟子的练功房。里面有几个单间，是练功室.第子们在里边砌磋武艺，绝对不允许外人打搅。");

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
