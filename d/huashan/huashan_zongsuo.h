//zongsuo.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zongsuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");

	//add npcs into the room
	add_npc("pub_xiaoer2");

    add_door("��ɽ", "��ɽ", "��ɽ����");
	add_door("Ⱥ�ɹ�", "��ɽȺ�ɹ�", "��ɽ����");

/*****************************************************
	set("exits", ([
		"east" : __DIR__"square",
	]));
//	
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
