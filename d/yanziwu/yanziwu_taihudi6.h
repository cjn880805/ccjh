//taihudi6.h
//Sample for room: ������̫������

ROOM_BEGIN(CRyanziwu_taihudi6);

virtual void create()			//Call it when Room Create
{
	set_name( "������̫������");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("̫������5", "������̫������5", "������̫������6");

};

ROOM_END;
