//xueshan.h

//Sample for room  ѩɽ��
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ��");

	add_npc("xueshan_gelunbu");
	add_npc("zm_xueshan");

	add_door("Ѫ����ѩɽ��´", "Ѫ����ѩɽ��´", "ѩɽ��");

	add_door("ѩɽ�³���", "ѩɽ�³���", "ѩɽ��");
	add_door("ѩɽ�µ���", "ѩɽ�µ���", "ѩɽ��");
	add_door("ѩɽ�´��", "ѩɽ�´��", "ѩɽ��");
	add_door("ѩɽ�¿ⷿ", "ѩɽ�¿ⷿ", "ѩɽ��");

};


ROOM_END;
