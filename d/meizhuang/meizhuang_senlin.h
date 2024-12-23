//senlin.h

//Sample for room:  ÷ׯ��ľ԰
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_senlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ��ľ԰");
	
	add_npc("pub_shinu1");         //add by zdn 2001-07-14

	add_item("meishu");
	add_item("meishu");

	add_door("÷ׯӭ��ͤ", "÷ׯӭ��ͤ", "÷ׯ��ľ԰");
	add_door("÷ׯ��Ժ", "÷ׯ��Ժ", "÷ׯ��ľ԰");
	add_door("÷ׯ�滱��", "÷ׯ�滱��", "÷ׯ��ľ԰");
	add_door("÷ׯƫ��", "÷ׯƫ��", "÷ׯ��ľ԰");

};


ROOM_END;
