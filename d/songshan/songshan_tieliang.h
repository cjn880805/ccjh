//tieliang.h

//Sample for room: ����Ͽ
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_tieliang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ͽ");
	
	add_npc("songshan_gao");         //add by zdn 2001-07-20


	add_door("��ɽɽ��5", "��ɽɽ��5", "��ɽ����Ͽ");
	add_door("��ɽ«���ٲ�", "��ɽ«���ٲ�", "��ɽ����Ͽ");


/*****************************************************
	set("exits", ([
		"down"    : __DIR__"luyanpubu",
		"northup" : __DIR__"shandao5",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
********************************************/
};


ROOM_END;
