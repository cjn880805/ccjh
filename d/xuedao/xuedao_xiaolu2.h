//xiaolu2.h
//Sample for room:  Ѫ����С·2
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu2);

virtual void create()			//Call it when Room Create

{
	//set name of our room
	set_name( "Ѫ����С·2");
	add_npc("pub_shenjia");
	add_door("Ѫ����С·1", "Ѫ����С·1", "Ѫ����С·2");
	add_door("Ѫ����С·3", "Ѫ����С·3", "Ѫ����С·2");

};
ROOM_END;
