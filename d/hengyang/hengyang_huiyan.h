//huiyan.h

//Sample for room: ����¥
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_huiyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");
	
	add_npc("pub_xiaoer2");        //add by zdn 2001-07-14
	add_npc("pub_xiafuren"); 

	add_door("������", "������", "��������¥");

};


ROOM_END;
