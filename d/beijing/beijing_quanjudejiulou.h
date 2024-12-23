//quanjudejiulou.h

//Sample for room: 全聚德酒楼
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_quanjudejiulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "全聚德酒楼");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////
				

	add_door("北京东北", "北京东北", "北京全聚德酒楼");

	set("long", "方圆数百里内提起全聚德酒楼可以说是无人不知，无人不晓。楼下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。楼上是雅座。" );
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
