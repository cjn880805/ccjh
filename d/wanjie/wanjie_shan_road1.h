//shan_road1.h

//Sample for room: ɽ·1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_shan_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ·1");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-16


	add_door("��ٹ�ɽ��", "��ٹ�ɽ��", "��ٹ�ɽ·1");
	add_door("��ٹ�ɽ·2", "��ٹ�ɽ·2", "��ٹ�ɽ·1");


};


ROOM_END;
