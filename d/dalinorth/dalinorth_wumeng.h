//wumeng.h

//Sample for room: ��������ɴ���
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_wumeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ɴ���");

	set("resident", "��Ū��");

	add_npc("pub_shaonu");   //add by zdn 2001-07-13

	add_door("�������Ū��", "�������Ū��", "��������ɴ���");
	add_door("����Ǵ������", "����Ǵ������", "��������ɴ���");
	add_door("������������1", "������������1", "��������ɴ���");
	add_door("������������2", "������������2", "��������ɴ���");

	set("long", "������ɽ�Ļ��£������˰�ʯȥ�����������޳�һ������״��ƽ̨����ӷֱ��ڸ���ƽ̨�ϣ��������ӣ�������ʯ��Χǽ�����е�·Ҳ��ʯͷ�̳ɡ�");
	
};


RESIDENT_END;
