//xiyuan.h

//Sample for room: 长安戏院
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_xiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "北京长安戏院");

	//add npcs into the room
	add_npc("pub_guanzho");
	add_npc("pub_guanzho1");
	add_npc("pub_guanzho2");
	add_npc("pub_guanzho3");
	add_npc("pub_guanzho4");
	add_npc("pub_guanzho5");
	add_npc("pub_xizi");
	
	add_door("北京西南", "北京西南", "北京长安戏院");

	set("long", "这里就是著名的长安戏院，几个戏子在台上(stage)唱戏。台下黑压压的一片都是人。唱到妙处，观众们禁不住大声喝采。东边是后台。" );
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
