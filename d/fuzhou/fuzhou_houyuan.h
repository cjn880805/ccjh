//houyuan.h

//Sample for room: �����ھֺ�Ժ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_houyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھֺ�Ժ");

	add_npc("pub_boy");   // add by zdn 2001-07-13
	add_npc("fuzhou_zheng");     //add by zdn 2001-07-20

	add_door("���ݸ����ھ�����", "���ݸ����ھ�����", "���ݸ����ھֺ�Ժ");
 

};


ROOM_END;
