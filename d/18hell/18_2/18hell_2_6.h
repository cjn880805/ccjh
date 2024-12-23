//18hell_2_6.h
//十八地狱入口黄泉之路六号房间

//coded by sound
//data: 2001-10-21

YEWAIROOM_BEGIN(CR18hell_2_6);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "黄泉之路");
	
	set("long", "这里是通往十八地狱的“黄泉”，四周的亡魂被一种莫名的力量引导着，走向一个巨大的地下洞穴边缘，并不断的跳了下去。");
	
	//add npcs into the room
	add_npc("diyu_shizhe2");

};

YEWAIROOM_END;
