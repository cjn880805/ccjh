//taihudi1.h
//Sample for room: ������̫������

ROOM_BEGIN(CRyanziwu_taihudi1);

virtual void create()			//Call it when Room Create
{
	set_name( "������̫������");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("̫��", "������̫��", "������̫������");
	add_door("̫������2", "������̫������2", "������̫������");

};

ROOM_END;
