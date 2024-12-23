//xianzhentang.h

//Sample for room:  重阳宫显真堂
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xianzhentang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫显真堂");

	add_door("重阳宫", "重阳宫", "重阳宫显真堂");
	
	add_npc("quanzhen_zhang");


	set("long", "这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不大，只摆放着一张桌子和几把椅子。桌上摆放着一盆高山流水的盆景，墙壁上挂着一些字画。西面有一间药剂室，是配药的地方。");

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
//last, register the room into ../server/RoomSetup.cpp