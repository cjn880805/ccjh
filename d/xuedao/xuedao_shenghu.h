//shenghu.h

//Sample for room:  Ѫ����ʥ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_shenghu);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ʥ��");
	
	add_npc("xuedao_lutianshu");        //add by zdn 2001-07-20

	add_door("Ѫ������·3", "Ѫ������·3", "Ѫ����ʥ��");
	add_door("Ѫ����С·1", "Ѫ����С·1", "Ѫ����ʥ��");
	add_door("Ѫ���Ź���", "Ѫ���Ź���", "Ѫ����ʥ��");


/******************************************************************************
******************************************************************************/
};


ROOM_END;
