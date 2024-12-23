//suti5.h

//Sample for room: 杭州苏堤5
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州苏堤5");
	
	add_npc("pub_xiaozei");        //add by zdn 2001-07-14 


	add_door("杭州苏堤4", "杭州苏堤4", "杭州苏堤5");
	add_door("杭州苏堤6", "杭州苏堤6", "杭州苏堤5");

	set("long"," 每当盛夏，游客到此纷纷寻荫小息，堤上绿树交柯，鸣蝉噪鼓。北边是望山桥，南面锁澜桥。");

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
