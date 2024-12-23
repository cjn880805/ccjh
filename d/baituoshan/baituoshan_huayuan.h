//huayuan.h

//Sample for room: 白驼山花园
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_huayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山花园");

	//add npcs into the room
	add_npc("pub_lady1");
	
	add_door("白驼山门廊", "白驼山门廊", "白驼山花园");
	add_door("白驼山内室", "白驼山内室", "白驼山花园");
	add_door("白驼山厨房", "白驼山厨房", "白驼山花园");
	add_door("白驼山竹园", "白驼山竹园", "白驼山花园");

};


ROOM_END;
