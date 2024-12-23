//dongnei.h

//Sample for room: 白驼山洞内
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dongnei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山洞内");

	//add npcs into the room
	add_npc("pub_shanzei3");
	add_door("白驼山洞口", "白驼山洞口", "白驼山洞内");

	set("long", "这里是山贼的老窝的所在。旁边有一侧洞，里面隐隐传来女子的哭声。");

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
