//changlang.h

//Sample for room: 白驼山长廊
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山长廊");


	add_door("白驼山药房", "白驼山药房", "白驼山长廊");
	add_door("白驼山西门", "白驼山西门", "白驼山长廊");
	add_door("白驼山练功场", "白驼山练功场", "白驼山长廊");
	add_door("白驼山休息室", "白驼山休息室", "白驼山长廊");

	set("long", "这里是非常气派的长廊。北边是间休息室。南边有间药房，里面传来一阵器皿碰击的声音。西边是扇拱月形小敞门。东边是练功场.");

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
