//chongsheng.h

//Sample for room: ��ʥ��
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRSongShan_chongsheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ʥ��");
	
	add_npc("pub_youke");             // add by zdn 2001-07-15


	add_door("��ɽ���и�", "��ɽ���и�", "��ɽ��ʥ��");
	add_door("��ɽ�������", "��ɽ�������", "��ɽ��ʥ��");

	set("long", "��ʥ��ǰ�����������������ˣ��ߴ����������ȭ��ŭĿͦ�أ������۽����򱱾������������ĵ�����������ˡ� ");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"tianzhongge",
	]));
********************************************/
};


ROOM_END;
