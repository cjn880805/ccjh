//grassland.h

//Sample for room: 草地
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_grassland);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "草地");
	
	add_npc("wanjie_zhong");        //add by zdn 2001-07-20

	add_door("万劫谷大森林", "万劫谷大森林", "万劫谷草地");
	add_door("万劫谷小厅", "万劫谷小厅", "万劫谷草地");

};


ROOM_END;
