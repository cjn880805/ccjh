//riverside2.h

//Sample for room: ����С·2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С·2");
	
	add_npc("pub_poorman");      //add by zdn 2001-07-16


	add_door("��ٹȽ���С·1", "��ٹȽ���С·1", "��ٹȽ���С·2");
	add_door("��ٹȽ���С·3", "��ٹȽ���С·3", "��ٹȽ���С·2");


};


ROOM_END;
