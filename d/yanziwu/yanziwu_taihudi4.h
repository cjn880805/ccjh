//taihudi4.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi4);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("Ì«ºşºşµ×3", "Ñà×ÓÎëÌ«ºşºşµ×3", "Ñà×ÓÎëÌ«ºşºşµ×4");
	add_door("Ì«ºşºşµ×5", "Ñà×ÓÎëÌ«ºşºşµ×5", "Ñà×ÓÎëÌ«ºşºşµ×4");

};

ROOM_END;
