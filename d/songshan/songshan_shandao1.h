//shandao1.h

//Sample for room: ɽ��1
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��1");
	
	add_npc("pub_tiaofu");          // add by zdn 2001-07-15


	add_door("��ɽ�������", "��ɽ�������", "��ɽɽ��1");
	add_door("��ɽ«���ٲ�", "��ɽ«���ٲ�", "��ɽɽ��1");
	add_door("��ɽ��ĸʯ", "��ɽ��ĸʯ", "��ɽɽ��1");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"dadian",
		"northwest" : __DIR__"qimushi",
		"northeast" : __DIR__"luyanpubu",
	]));
********************************************/
};


ROOM_END;
