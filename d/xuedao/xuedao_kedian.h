//kedian.h

//Sample for room:  Ѫ���ſ͵�
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_kedian);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ���ſ͵�");
	
	add_npc("pub_xiaoer2");          //add by zdn 2001-07-16

	add_door("Ѫ������·2", "Ѫ������·2", "Ѫ���ſ͵�");


/******************************************************************************
******************************************************************************/
};


ROOM_END;
