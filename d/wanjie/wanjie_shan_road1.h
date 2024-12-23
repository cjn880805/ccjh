//shan_road1.h

//Sample for room: 山路1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_shan_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路1");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-16


	add_door("万劫谷山坡", "万劫谷山坡", "万劫谷山路1");
	add_door("万劫谷山路2", "万劫谷山路2", "万劫谷山路1");


};


ROOM_END;
