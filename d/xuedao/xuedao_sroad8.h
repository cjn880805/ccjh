//sroad8.h

//Sample for room:  血刀门大雪山山谷8
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad8);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门大雪山山谷8");
	add_npc("pub_yanqiansui");

	add_door("血刀门忘忧谷", "血刀门忘忧谷", "血刀门大雪山山谷8");
	add_door("血刀门大雪山口7", "血刀门大雪山口7", "血刀门大雪山山谷8");
	add_door("血刀门山洞1", "血刀门山洞1", "血刀门大雪山山谷8");

	set("long","一个宽大山谷, 群山环绕, 山顶上全是白闪闪的积雪, 山谷南方有两个山洞。");
    

/******************************************************************************
        set("exits",([
                "enter"  : __DIR__"shandong1",
                "north"  : __DIR__"wangyougu",
                "northup": __DIR__"sroad7",
        ]));
******************************************************************************/
};


ROOM_END;
