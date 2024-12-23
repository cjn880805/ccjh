//xiaolu4.h

//Sample for room: 白驼山小路4
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山小路4");

	//add npcs into the room
	add_npc("pub_shanzei2");
	
	add_door("白驼山洞口", "白驼山洞口", "白驼山小路4");
	add_door("白驼山小路3", "白驼山小路3", "白驼山小路4");

	set("long", "这里是一条上山的小路向西分出一条岔道。北边是山贼的老窝。");

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
