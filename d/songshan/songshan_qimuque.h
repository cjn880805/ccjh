//qimuque.h

//Sample for room: ��ĸ��
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_qimuque);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĸ��");


	add_door("��ɽ��ĸʯ", "��ɽ��ĸʯ", "��ɽ��ĸ��");

	

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"qimushi",
	]));
********************************************/
};


ROOM_END;
