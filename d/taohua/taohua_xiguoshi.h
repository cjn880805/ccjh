//xiguoshi.h

//Sample for room: 思过室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiguoshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "思过室");

	//add npcs into the room
	add_npc("taohuadao_mei");/////////////////////////

	add_door("桃花山庄小院", "桃花山庄小院", "桃花岛思过室");
	add_door("桃花岛桃花轩", "桃花岛桃花轩", "桃花岛思过室");

	set("long", "这是桃花岛上供本门弟子闭门思过的地方。屋里仅仅放着一张床，显得空荡荡的。四面则是光秃秃的墙壁，看上去黑黝黝的，原来却是铁筑的。靠门的地方有一小洞，洞边放着一只碗。往东是一间不起眼的小屋，门上挂了个牌子「桃花轩」。");

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/mei" : 1,
	]) );    
//	
********************************************/
};


ROOM_END;
