//taihudi3.h
//Sample for room: Ñà×ÓÎëÌ«ºşºşµ×

ROOM_BEGIN(CRyanziwu_taihudi3);

virtual void create()			//Call it when Room Create
{
	set_name( "Ñà×ÓÎëÌ«ºşºşµ×");
	
	add_npc("wei_baiyu"); 
	if(random(2))
		add_npc("wei_baiyu");
	add_item("zhen_zhu"); 

	set("water",1);

	add_door("Ì«ºşºşµ×2", "Ñà×ÓÎëÌ«ºşºşµ×2", "Ñà×ÓÎëÌ«ºşºşµ×3");
	add_door("Ì«ºşºşµ×4", "Ñà×ÓÎëÌ«ºşºşµ×4", "Ñà×ÓÎëÌ«ºşºşµ×3");

};

ROOM_END;
