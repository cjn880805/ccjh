//zhengting.h

//Sample for room: �����ھ�����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_zhengting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھ�����");

	//add npcs into the room
	add_npc("pub_chengqi");
	add_npc("pub_baier");
	add_npc("fuzhou_linzhennan");      // add by zdn 2001-07-20
	
	add_door("������", "������", "���ݸ����ھ�����");
	add_door("���ݸ����ھ���լ", "���ݸ����ھ���լ", "���ݸ����ھ�����");
	add_door("���ݸ����ھֺ�Ժ", "���ݸ����ھֺ�Ժ", "���ݸ����ھ�����");
	set("no_fight",1);
 

};


ROOM_END;




