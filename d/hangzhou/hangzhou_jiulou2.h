//jiulou2.h

//Sample for room: 杭州楼外楼二楼
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_jiulou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州楼外楼二楼");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("杭州楼外楼", "杭州楼外楼", "杭州楼外楼二楼");


};


ROOM_END;
