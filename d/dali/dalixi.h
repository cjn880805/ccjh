//dalixi.h

//Sample for room:  �������
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLixi);

virtual void create()			
{
	set_name( "�������");

	set("resident", "����");
	set("capacity", 30);
	set("price", 120);

	add_npc("pub_playboy");
	add_npc("pub_flowerg");
	add_npc("dali_guigongzi");        //add by zdn 2001-07-20

	add_door("���������", "���������", "�������");
	add_door("����Ǳ���", "����Ǳ���", "�������");
	add_door("����Ƕ�", "����Ƕ�", "�������");

	add_door("����ǻʹ�ǰ��", "����ǻʹ�ǰ��", "�������");
//	add_door("�����̫�;�", "�����̫�;�", "�������");
	add_door("����Ǳ�Ӫ", "����Ǳ�Ӫ", "�������");
};


RESIDENT_END;
