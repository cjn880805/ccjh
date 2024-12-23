//shantang.h

//Sample for room:  重阳宫膳堂
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_shantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫膳堂");

	add_door("重阳宫", "重阳宫", "重阳宫膳堂");
	add_npc("quanzhen_zhangyao");

	set("long", "这里是全真教的膳堂，是弟子们用餐的地方。这个堂很大，整齐地摆放着一排一排的桌椅。现在桌椅上三三两两地坐着全真弟子，有的正在用餐，有的低头谈笑。看着可口的饭菜，你忍不住也想叫(order)一份。");

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