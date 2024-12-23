//zhongnan.h

//Sample for room  终南山口
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRZhongNancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山口");

	add_npc("pub_youngwoman");
	add_npc("pub_jianke");        //2001-07-10  zdn add

	add_door("终南山大官道", "终南山大官道", "出口");

	set  ("long","终南山又称太乙山，距长安城八十多里，素有“锦秀巨屏拱长安”之说。据传老子曾在山中讲经。这条大官道穿越终南山口，两面秀峰入云，这里却没有一条路可以上山。西面是往长安的大道，东面前往中原。");
};


ROOM_END;
