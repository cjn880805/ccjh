//yangzhou_dongnan.h

//Sample for room:  ���ݶ���
//coded by Fisho
//data: 2000-11-2


RESIDENT_BEGIN(CRyangzhou_dongnan);



virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ���");

	set("resident", "����");

	//add npcs into the room
	add_npc("pub_boy");
	add_npc("pub_bing");
	add_npc("guiyun_hanxiaoyin");
	add_npc("guiyun_zhucong");               //zdd by zdn 2001-07-20


	add_door("���ݵ���", "���ݵ���", "���ݶ���");
	add_door("��������Ժ", "��������Ժ", "���ݶ���");

	add_door("��������", "��������", "���ݶ���");
	add_door("���ݶ���", "���ݶ���", "���ݶ���");
	add_door("���ݶ���", "���ݶ���", "���ݶ���");

};


RESIDENT_END;
