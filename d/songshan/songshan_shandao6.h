//shandao6.h

//Sample for room: ɽ��6
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��6");
	
	add_npc("pub_poorman");        //add by zdn 2001-07-15      


	add_door("��ɽ������", "��ɽ������", "��ɽɽ��6");
	add_door("��ɽ������Ժɽ��", "��ɽ������Ժɽ��", "��ɽɽ��6");

	

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"junjigate",
		"southdown" : __DIR__"chaotian",
	]));
********************************************/
};


ROOM_END;
