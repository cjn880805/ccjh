//bridge.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_bridge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("wanjie_zhongling");        //add by zdn 2001-07-20



	add_door("��ٹ����˶�", "��ٹ����˶�", "��ٹ�������");
	add_door("��ٹ����׽���", "��ٹ����׽���", "��ٹ�������");

};


ROOM_END;
