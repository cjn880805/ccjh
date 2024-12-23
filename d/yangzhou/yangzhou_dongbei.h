//yangzhou_dongbei.h

//Sample for room:  ���ݶ���
//coded by Fisho
//data: 2000-11-2

RESIDENT_BEGIN(CRyangzhou_dongbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ���");

	set("resident", "����");
	set("capacity", 25);

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("pub_playboy");
	add_npc("guiyun_zhangasheng");             //zdd by zdn 2001-07-20
	add_npc("helpnpc_jhlz");
	add_npc("pub_xiaoqiang");

	add_door("���ݿ͵�", "���ݿ͵�", "���ݶ���");
	add_door("������Ժ", "������Ժ", "���ݶ���");
	add_door("����ҩ��", "����ҩ��", "���ݶ���");
	add_door("��������¥", "��������¥", "���ݶ���");
	
	add_door("���ݶ���", "���ݶ���", "���ݶ���");
	add_door("��������", "��������", "���ݶ���");

};


RESIDENT_END;




