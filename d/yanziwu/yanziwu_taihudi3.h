//taihudi3.h
//Sample for room: ������̫������

ROOM_BEGIN(CRyanziwu_taihudi3);

virtual void create()			//Call it when Room Create
{
	set_name( "������̫������");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");
	add_item("zhen_zhu"); 

	set("water",1);

	add_door("̫������2", "������̫������2", "������̫������3");
	add_door("̫������4", "������̫������4", "������̫������3");

};

ROOM_END;
