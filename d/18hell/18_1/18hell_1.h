//18hell_1.h
//十八地狱第一层BOSS房间

//coded by sound
//data: 2001-10-21

CUNLUOROOM_BEGIN(CR18hell_1);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "高昌迷宫");
	
	set("long", "这里是十八地狱入口“黄泉”，四周的亡魂被一种莫名的力量引导着，走向一个巨大的地下洞穴边缘，并不断的跳了下去。");
	
//	add npcs into the room
	add_npc("diyu_shizhe1");
	add_npc("ningfeng");

};

CUNLUOROOM_END;
