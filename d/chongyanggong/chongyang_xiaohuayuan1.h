//xiaohuayuan1.h

//Sample for room:  重阳宫小花园1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaohuayuan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫小花园1");
	
	add_npc("quanzhen_zhangyuan");

	add_door("重阳宫", "重阳宫", "重阳宫小花园1");
	add_door("重阳宫小花园2", "重阳宫小花园2", "重阳宫小花园1");

	set("long", "这里是重阳观里的小花园，空气中飘着一股鲜花的香味。再往北去，就是金鱼池了。这个花园不大，却是全真弟子练功间隙最爱来游玩的地方。园中见不到一根杂草，也许专门有人负责管理这里。");

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