//shijie.h

//Sample for room: ��ľ��ʯ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ��ʯ��");

    add_npc("pub_boy");         // add by zdn 2001-07-14
	add_npc("helpnpc004");

	add_door("��ľ��ɽ��", "��ľ��ɽ��", "��ľ��ʯ��");
	add_door("��ľ��ʯ��", "��ľ��ʯ��", "��ľ��ʯ��");

};


ROOM_END;
