//xiaolu4.h

//Sample for room:  Ѫ����С·4
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu4);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����С·4");
	
//	add_npc("xuedao_shuidai");        //add by zdn 2001-07-20
		
	add_door("Ѫ����С·3", "Ѫ����С·3", "Ѫ����С·4");
	add_door("Ѫ����ɽ��", "Ѫ����ɽ��", "Ѫ����С·4");
	
	
	/******************************************************************************
	******************************************************************************/
};


ROOM_END;
