//kedian1.h

//Sample for room: 客店
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_kedian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "客店1");

	add_npc("shaolin_xingzhe");
	add_npc("pub_xiaoer2");
//	add_npc("wiz_teacher3");

	add_door("北京皇城", "北京皇城", "北京客店1");

	set("long", "这是一家价钱低廉的客栈，生意非常兴隆。据说全国各地都有这样的分店，而且所有的客栈都归一个人所有。不过他从来不露面，谁也不知道他究竟是怎样一个人。" );
	set("no_fight", 1);
	set("valid_startroom", 1);
	
	set("sleep_room", 1);


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




