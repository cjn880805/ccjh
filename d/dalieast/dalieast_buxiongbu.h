//buxiongbu.h

//Sample for room: ����ǲ��۲�
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_buxiongbu);

virtual void create()			//Call it when Room Create
{
	set_name( "����ǲ��۲�");

	set("resident", "���۲�");

	add_npc("pub_bshangfan");
	
	add_door("��������Ϸ�", "��������Ϸ�", "����ǲ��۲�");
	add_door("�����ũ��5", "�����ũ��5", "����ǲ��۲�");
	add_door("����ǰ�ɽ����", "����ǰ�ɽ����", "����ǲ��۲�");
	add_door("��������ƺ���", "��������ƺ���", "����ǲ��۲�");
	add_door("����Ǹ���3", "����Ǹ���3", "����ǲ��۲�");

};


RESIDENT_END;
