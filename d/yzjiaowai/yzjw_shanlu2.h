//yzjw_shanlu2.h
//Sample for room:  ����ɽ·2
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shanlu2);


virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "����ɽ·2");
	
	add_npc("pub_punk");      //add by zdn 2001-07-16


	add_door("������ʯ�ٵ�2","������ʯ�ٵ�2","����ɽ·2");

	add_door("��������","��������","����ɽ·2");

};

ROOM_END;
