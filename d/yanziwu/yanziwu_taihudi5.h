//taihudi5.h
//Sample for room: ������̫������

ROOM_BEGIN(CRyanziwu_taihudi5);

virtual void create()			//Call it when Room Create
{
	set_name( "������̫������");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");
	
	add_item("zhen_zhu");

	set("water",1);

	add_door("̫������4", "������̫������4", "������̫������5");
	add_door("̫������6", "������̫������6", "������̫������5");

};

ROOM_END;
