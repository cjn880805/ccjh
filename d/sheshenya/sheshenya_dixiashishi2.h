//dixiashishi2.h

//Sample for room: ����ʯ��2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_dixiashishi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����µ���ʯ��2");

	add_npc("pub_qingyun");/////////////////////////

	add_door("�����µ���ʯ��1", "�����µ���ʯ��1", "�����µ���ʯ��2");

/*****************************************************
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
		__DIR__"npc/qingyun" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
