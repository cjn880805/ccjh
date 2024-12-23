//songlin.h

//Sample for room: 华山松树林
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_songlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山松树林");
	add_npc("pub_yumu");

	add_door("华山长廊", "华山长廊", "华山松树林");

	set("long", "这是一片松树林。几丈高的松树密密麻麻，遮得不见天日。地上落满松针，有不知名的野兔偷偷逃过。四周一片寂静。");  
    
 
/*****************************************************

********************************************/
};


ROOM_END;
