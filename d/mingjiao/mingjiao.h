//mingjiao.h



//Sample for room:  ��������ɽ��

//coded by zouwenbin

//data: 2000-11-16

ROOM_BEGIN(CRMingJiaocity);


virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "��������ɽ��");

	add_npc("helpnpc003");		//add by qzj 2001-08-13
	add_npc("pub_dusha");

	add_door("����˿��֮·3", "����˿��֮·3", "��������ɽ��");
	add_door("������ʯ���1", "������ʯ���1", "��������ɽ��");


};

ROOM_END;
