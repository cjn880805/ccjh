//grassland.h

//Sample for room: �ݵ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_grassland);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ݵ�");
	
	add_npc("wanjie_zhong");        //add by zdn 2001-07-20

	add_door("��ٹȴ�ɭ��", "��ٹȴ�ɭ��", "��ٹȲݵ�");
	add_door("��ٹ�С��", "��ٹ�С��", "��ٹȲݵ�");

};


ROOM_END;
