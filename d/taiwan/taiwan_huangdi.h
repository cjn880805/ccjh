//huangdi.h

//Sample for room: ̨��ĵ�
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_huangdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̨��ĵ�");

	set("monster_chance", 20);
	
	add_npc("pub_dipi");   //add by zdn 2001-07-16

	add_door("̨���Ƕ��", "̨���Ƕ��", "̨��ĵ�");
	add_door("̨��򹷸�", "̨��򹷸�", "̨��ĵ�");
//	add_door("̨����ҩ������", "̨����ҩ������", "̨��ĵ�");
	add_door("̨�弦����", "̨�弦����", "̨��ĵ�");
	add_door("̨������̶", "̨������̶", "̨��ĵ�");


/*****************************************************

********************************************/
};


ROOM_END;
