//baituoshan.h

//Sample for room:  ����ɽ
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShancity);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ");
	add_door("������", "������", "����ɽ");
	add_door("����ɽ��", "����ɽ��", "����ɽ");

	add_door("����ɽ����", "����ɽ����", "����ɽ");

};

ROOM_END;
