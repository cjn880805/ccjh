//xiaguan.h

//Sample for room: 大理城下关城
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_xiaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城下关城");

	set("resident", "下关城");

	//add npcs into the room
	add_npc("pub_tshangfan");/////////////////////////
	add_npc("pub_wyshangfan");

	add_door("大理城苍山", "大理城苍山", "大理城下关城");
	add_door("大理城洱水桥", "大理城洱水桥", "大理城下关城");
	add_door("大理城苍山中部", "大理城苍山中部", "大理城下关城");

	set("long", "下关城，又名龙尾城，为阁罗凤所筑，唐代已极繁荣。城区萦抱苍山南麓数里，洱水绕城南而过，端的风景如画。此去南边不远即是大理城，东面有太和城，另有道路通向西北。此附近居民以乌夷、台夷为主，也有少量摆夷。");

};

RESIDENT_END;
