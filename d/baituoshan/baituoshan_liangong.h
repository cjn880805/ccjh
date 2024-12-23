//liangong.h

//Sample for room: 练功场
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "练功场");

	add_npc("pub_tongzi");
	add_npc("btshan_li");
	add_npc("pub_tongzi");

	add_door("白驼山大厅", "白驼山大厅", "白驼山练功场");
	add_door("白驼山长廊", "白驼山长廊", "白驼山练功场");
	add_door("白驼山门廊", "白驼山门廊", "白驼山练功场");
	add_door("白驼山练功房", "白驼山练功房", "白驼山练功场");

	set("long", "这里是白驼山弟子的练功场。东边是一个练功房。北边是个门廊，西边连着一条长廊，雕梁画柱，非常气派。南面可见巍巍大厅");

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
