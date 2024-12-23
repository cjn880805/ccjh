//xiaohuayuan2.h

//Sample for room:  重阳宫小花园2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaohuayuan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫小花园2");
	
	add_npc("quanzhen_wangzhi");

	add_door("重阳宫小花园1", "重阳宫小花园1", "重阳宫小花园2");
	add_door("重阳宫小花园3", "重阳宫小花园3", "重阳宫小花园2");

	set("long", "这里是重阳观里的小花园，种植着一些叫不出名字来的花木，园角砌着一座假山，假山下是一潭小小的金鱼池，池水清澈见底，你看见有数条红色的金鱼在里面悠哉游哉地游来游去。几个道童正在这里嬉戏着。");

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