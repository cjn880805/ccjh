//shandao2.h

//Sample for room: ɽ��2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��2");
	
	add_npc("pub_poorman");               //add by zdn 2001-07-15


	add_door("��ɽ��ĸʯ", "��ɽ��ĸʯ", "��ɽɽ��2");
	add_door("��ɽ������Ժ", "��ɽ������Ժ", "��ɽɽ��2");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"shuyuan",
		"southdown" : __DIR__"qimushi",
	]));
********************************************/
};


ROOM_END;
