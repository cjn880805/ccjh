//yipinzhang.h

//Sample for room: һƷ���ʷ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_yipinzhang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "һƷ���ʷ�");
	
	add_npc("lingzhou_zhangfang");        //add by zdn 2001-07-20


	add_door("����һƷ�ô���", "����һƷ�ô���", "����һƷ���ʷ�");

//	add_npc("pub_zhangfang");	//����Ӧ���и�һƷ�õ��ʷ���lanwood
  
};


ROOM_END;
