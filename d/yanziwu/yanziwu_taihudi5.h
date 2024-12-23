//taihudi5.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi5);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");
	
	add_item("zhen_zhu");

	set("water",1);

	add_door("Ì«ºşºşµ×4", "Ñà×ÓÎëÌ«ºşºşµ×4", "Ñà×ÓÎëÌ«ºşºşµ×5");
	add_door("Ì«ºşºşµ×6", "Ñà×ÓÎëÌ«ºşºşµ×6", "Ñà×ÓÎëÌ«ºşºşµ×5");

};

ROOM_END;
