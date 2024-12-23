//diziju.h

//Sample for room:  重阳宫弟子居
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_diziju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫弟子居");

	add_door("重阳宫静修室", "重阳宫静修室", "重阳宫弟子居");
	add_npc("quanzhen_zhangjing");

	set("long", "这里是全真教弟子居住的房间。房间很大，整齐地铺着一排一排的床，床上被褥都折叠得整整齐齐，但是一个人都没有，也许所有的弟子都去练功去了。靠墙的地方有一个柜子(cabinet)。");

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