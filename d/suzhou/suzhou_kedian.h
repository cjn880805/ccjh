//kedian.h

//Sample for room: �͵�
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_kedian);

virtual void create()			//Call it when Room Create
{
	set_name( "�͵�");

	add_npc("pub_xiaoer2");

	add_door("���ݱ�", "���ݱ�", "���ݿ͵�");

	set("no_fight", 1);
	set("valid_startroom", 1);
    set("sleep_room",1);
	

};


ROOM_END;
