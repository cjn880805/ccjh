//taihudi2.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi2);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("Ì«ºşºşµ×", "Ñà×ÓÎëÌ«ºşºşµ×", "Ñà×ÓÎëÌ«ºşºşµ×2");
	add_door("Ì«ºşºşµ×3", "Ñà×ÓÎëÌ«ºşºşµ×3", "Ñà×ÓÎëÌ«ºşºşµ×2");

};

ROOM_END;
