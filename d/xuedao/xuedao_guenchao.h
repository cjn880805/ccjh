//guenchao.h

//Sample for room:  Ѫ���Ź���
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_guenchao);


virtual void create()			//Call it when Room Creat
{
	//set name of our room
	set_name( "Ѫ���Ź���");
	add_npc("hero_oho");
	add_door("Ѫ����ʥ��", "Ѫ����ʥ��", "Ѫ���Ź���");
	set("no_fight", 1);
	set("no_beg", 1);

/******************************************************************************
******************************************************************************/
};


ROOM_END;
