//baihuda.h

//Sample for room: 白虎堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_baihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白虎堂");
	
	add_npc("heimuya_renwuyue");         // add by zdn 2001-07-14

	add_door("黑木崖厨房", "黑木崖厨房", "黑木崖白虎堂");
	add_door("黑木崖圣姑堂", "黑木崖圣姑堂", "黑木崖白虎堂");
	add_door("黑木崖长廊", "黑木崖长廊", "黑木崖白虎堂");

	set("long", "这里是黑木崖的第二大堂“白虎堂”。堂内青砖铺地，堂内横尸满地。堂上北壁上有几个血字(zi)。");
    
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp