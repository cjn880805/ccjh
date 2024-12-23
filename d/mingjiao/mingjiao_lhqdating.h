//lhqdating.h


//Sample for room: ÁÒ»ðÆì´óÌü
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_lhqdating);

virtual void create()			//Call it when Room Create

{
	set_name( "ÁÒ»ðÆì´óÌü");

	add_npc("mingjiao_xinran");
	
	add_door("Ã÷½ÌÁÒ»ðÆìÅÆ·»", "Ã÷½ÌÁÒ»ðÆìÅÆ·»", "Ã÷½ÌÁÒ»ðÆì´óÌü");
	add_door("Ã÷½ÌÌìÎ¢ÌÃ", "Ã÷½ÌÌìÎ¢ÌÃ", "Ã÷½ÌÁÒ»ðÆì´óÌü");

};

ROOM_END;
