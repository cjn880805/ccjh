//jingxiushi.h

//Sample for room:  重阳宫静修室
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_jingxiushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫静修室");

	add_npc("quanzhen_liu");

	add_door("重阳宫", "重阳宫", "重阳宫静修室");
	add_door("重阳宫小路", "重阳宫小路", "重阳宫静修室");
	add_door("重阳宫弟子居", "重阳宫弟子居", "重阳宫静修室");

	set("long", "这里是全真教弟子静修参悟道情的房间，房间很小，但收拾的干干净净，桌椅都摆放得整整齐齐，让人一看就心无杂念。");
    

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