//feilihusouth

//Sample for room: �������ϰ�
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihusouth);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ϰ�");

	set("resident", "ϲ��");

	add_npc("pub_boy");
	add_npc("pub_playboy");    // add by zdn 2001-07-13

	add_door("����Ǻ�����", "����Ǻ�����", "������������ϰ�");


	set("long", "���������Բ����洬��ͷ��������̨�Ĵ������������񷤣�һЩ���������º����㣬���ʵ��������ڸ�����ϲ�ݡ����ڵȳ��������ü�Ǯ��" );
};


RESIDENT_END;
