//xiaolu1.h
//Sample for room:  Ѫ����С·1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRXueDao_xiaolu1);

virtual void create()			//Call it when Room Create

{
	//set name of our room
	set_name( "Ѫ����С·1");
	add_npc("pub_yuanyanggang");

	add_door("Ѫ����ʥ��", "Ѫ����ʥ��", "Ѫ����С·1");

	add_door("Ѫ����С·2", "Ѫ����С·2", "Ѫ����С·1");

};

ROOM_END;
