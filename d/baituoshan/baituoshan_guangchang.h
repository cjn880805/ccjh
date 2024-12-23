//guangchang.h

//Sample for room: 白驼山广场
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山广场");

	//add npcs into the room
	add_npc("pub_kid");
	
	add_door("白驼山小桥", "白驼山小桥", "白驼山广场");
	add_door("白驼山山路", "白驼山山路", "白驼山广场");
	add_door("白驼山石阶", "白驼山石阶", "白驼山广场");
	add_door("白驼山农舍", "白驼山农舍", "白驼山广场");

	set("long", "这里是一块不小的广场，上面堆着农家晒的谷物。北上是『白驼山庄』。东面有间小农舍，西边有块菜地，东南方是一座小桥。");
	
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
