//xuedaomen.h

//Sample for room:  Ѫ����
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����");
	
	add_npc("pub_zhuoma");        //add by zdn 2001-07-20




	add_door("������", "������", "Ѫ����");

	add_door("Ѫ����ѩɽ·1", "Ѫ����ѩɽ·1", "Ѫ����");


    

/******************************************************************************

******************************************************************************/
};


ROOM_END;
