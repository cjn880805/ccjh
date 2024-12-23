//taihudi6.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi6);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("Ì«ºşºşµ×5", "Ñà×ÓÎëÌ«ºşºşµ×5", "Ñà×ÓÎëÌ«ºşºşµ×6");

};

ROOM_END;
