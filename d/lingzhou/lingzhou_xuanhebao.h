//xuanhebao.h

//Sample for room: �������ͱ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xuanhebao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ͱ�");
	
	add_npc("pub_youke"); 
	add_npc("pub_caodongyun");
//	add_npc("lingzhou_helianchunshui");    //add by zdn 2001-07-14


	add_door("������ɳ��", "������ɳ��", "�������ͱ�");
	add_door("�ƺ�", "�ƺ�", "�������ͱ�");

};


ROOM_END;




