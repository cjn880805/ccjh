//gebi.h

//Sample for room: 白驼山戈壁
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_gebi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山戈壁");

	set("monster_chance", 20);
	add_npc("pub_dinping");

	add_door("白驼山东街", "白驼山东街", "白驼山戈壁");
	add_door("西域大漠", "西域大漠", "白驼山戈壁");

	set("long", "这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠,西北方可以看见一座小镇。");
    
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
