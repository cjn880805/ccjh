//dali.h

//Sample for room:  �����
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLicity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	add_npc("pub_huanu");
	add_npc("pub_tiaofu");
	add_npc("pub_girl1");			//zdn 2001-07-12 add
	add_npc("dali_bing");			//zdn  2001-07-20 add
	add_npc("dali_duanyanqing");    //add by zdn 2001-07-20
	add_npc("helpnpc002");			//add by qzj 2001-08-13	

	add_door("���������", "���������", "�����");
	add_door("����Ǳ���", "����Ǳ���", "�����");


	add_door("�����ʯ��", "�����ʯ��", "�����");
	add_door("�����ҩ��", "�����ҩ��", "�����");
	add_door("�������˾��", "�������˾��", "�����");
	add_door("�������������", "�������������", "�����");
	add_door("�����Ѧ�ǳ�����", "�����Ѧ�ǳ�����", "�����");
	add_door("����ǻʹ�����", "����ǻʹ�����", "�����");
	add_door("�����̫�;�", "�����̫�;�", "�����");
	add_door("����Ǳ�Ӫ", "����Ǳ�Ӫ", "�����");

};


ROOM_END;
