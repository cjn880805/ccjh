//songyueta.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_songyueta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	 add_npc("songshan_bu");         //add by zdn 2001-07-20


//	add_door("��ɽ������", "��ɽ������", "��ɽ������");

	set("long", "����ԭ�Ǳ�κ�빬��Т������Ϊ��Ժ�����巽�н�������Χ����ɮ�����ơ�Ժ�ڷ綯����ҡ���ң�����һ���徲�� " );
	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
********************************************/
};


ROOM_END;
