//jushi.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_jushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	set_temp("have_book",1);

	add_npc("huashan_yue_wife");

	add_door("��ɽ����", "��ɽ����", "��ɽ����");

};


ROOM_END;
