//dating.h

//Sample for room: 白驼山大厅
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山大厅");

	//add npcs into the room
	add_npc("pub_yahuan");
	add_npc("btshan_ouyangfeng");
	
	add_door("白驼山院子", "白驼山院子", "白驼山大厅");
	add_door("白驼山练功场", "白驼山练功场", "白驼山大厅");

	set("long", "这是『白驼山庄』的大厅，内部摆设极尽豪华，当中一张黑色檀木条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名家的字画。.第子们在里边砌磋武艺，绝对不允许外人打搅。");
	set("valid_startroom",1);

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
