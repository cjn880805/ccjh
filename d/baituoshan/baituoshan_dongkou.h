//dongkou.h

//Sample for room: 白驼山洞口
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dongkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山洞口");

	//add npcs into the room
	add_npc("pub_shanzei2");
	add_door("白驼山洞内", "白驼山洞内", "白驼山洞口");
	add_door("白驼山小路4", "白驼山小路4", "白驼山洞口");

	set("long", "这里是山贼的老窝的洞口，守备森严。");

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
