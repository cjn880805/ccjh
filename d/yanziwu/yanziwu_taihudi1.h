//taihudi1.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi1);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");

	set("water",1);

	add_door("Ì«ºş", "Ñà×ÓÎëÌ«ºş", "Ñà×ÓÎëÌ«ºşºşµ×");
	add_door("Ì«ºşºşµ×2", "Ñà×ÓÎëÌ«ºşºşµ×2", "Ñà×ÓÎëÌ«ºşºşµ×");

};

ROOM_END;
