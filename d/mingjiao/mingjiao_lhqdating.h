//lhqdating.h


//Sample for room: �һ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_lhqdating);

virtual void create()			//Call it when Room Create

{
	set_name( "�һ������");

	add_npc("mingjiao_xinran");
	
	add_door("�����һ����Ʒ�", "�����һ����Ʒ�", "�����һ������");
	add_door("������΢��", "������΢��", "�����һ������");

};

ROOM_END;
