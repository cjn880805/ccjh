//luyanpubu.h

//Sample for room: «���ٲ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_luyanpubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "«���ٲ�");

	add_npc("shaolin_wuying");

	add_door("��ɽɽ��1", "��ɽɽ��1", "��ɽ«���ٲ�");
	add_door("��ɽ����Ͽ", "��ɽ����Ͽ", "��ɽ«���ٲ�");

	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
********************************************/
};


ROOM_END;
