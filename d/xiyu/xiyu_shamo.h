//shamo.h

//Sample for room: �Ͻ�ɳĮ
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
RESIDENT_BEGIN(CRXiYu_shamo);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ͻ�ɳĮ");
	
	add_npc("pub_xixiabing");       //add by zdn 201-07-16
//	add_npc("kunlun_jiangtao");        //add by zdn 2001-07-20
	add_npc("pub_dinyi");

	set("capacity", 5);
	set("price", 30);
	set("resident", "����");

	add_door("������ɽ����", "������ɽ����", "�����Ͻ�ɳĮ");

};


RESIDENT_END;
