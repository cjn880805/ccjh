//keting.h

//Sample for room:  ÷ׯӭ��ͤ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_keting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯӭ��ͤ");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-14
	add_item("meishu");

	add_door("÷ׯ�������", "÷ׯ�������", "÷ׯӭ��ͤ");
	add_door("÷ׯ��ľ԰", "÷ׯ��ľ԰", "÷ׯӭ��ͤ");

};


ROOM_END;
