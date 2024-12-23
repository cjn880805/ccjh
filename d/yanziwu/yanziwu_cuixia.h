//cuixia.h

//Sample for room: Ñà×ÓÎë´äÏ¼ÌÃ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_cuixia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ñà×ÓÎë´äÏ¼ÌÃ");

	add_npc("yanziwu_azhu");
	
	add_door("Ñà×ÓÎë´©ÌÃ", "Ñà×ÓÎë´©ÌÃ", "Ñà×ÓÎë´äÏ¼ÌÃ");
	add_door("Ñà×ÓÎëÏşº®Ìü", "Ñà×ÓÎëÏşº®Ìü", "Ñà×ÓÎë´äÏ¼ÌÃ");
	add_door("Ñà×ÓÎëÖñÁÖ", "Ñà×ÓÎëÖñÁÖ", "Ñà×ÓÎë´äÏ¼ÌÃ");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp