//riyueping.h

//Sample for room: ��ľ������ƺ
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_riyueping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ������ƺ");
	
	add_npc("heimuya_fansong");       //add by zdn 201-07-20


	add_door("��ľ��ʯ��", "��ľ��ʯ��", "��ľ������ƺ");
	add_door("��ľ�³ɵµ�", "��ľ�³ɵµ�", "��ľ������ƺ");

};


ROOM_END;
