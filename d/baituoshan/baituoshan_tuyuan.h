//tuyuan.h

//Sample for room: 兔苑
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_tuyuan);

virtual void create()			//Call it when Room Create
{
	set_name( "兔苑");

	set("monster_chance", 1);
//	add_npc("animal_baitu");/////////////////////////
//	add_npc("animal_baitu");

	add_door("白驼山蛇园", "白驼山蛇园", "白驼山兔苑");
	add_door("白驼山兽舍", "白驼山兽舍", "白驼山兔苑");
	add_door("白驼山竹园", "白驼山竹园", "白驼山兔苑");

	set("long", "这是个好玩的兔苑，几只大白兔静静地蹲在绿草地上吃草。往北是后门，西南方是竹园。西面传来阵阵猛兽的嚎叫，东面有一个蛇园。");  

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
