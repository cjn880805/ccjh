//shamo1.h

//Sample for room: �ƺ�ɳĮ2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shamo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ɳĮ2");
	
	add_npc("pub_xixiabing");      //add by zdn 2001-07-14


	add_door("�ƺ�ɳĮ1", "�ƺ�ɳĮ1", "�ƺ�ɳĮ2");
	add_door("�ƺ�ʯ��", "�ƺ�ʯ��", "�ƺ�ɳĮ2");

	set("long","����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽����ͷ·�����·�������и�ʯ����");
	

/*****************************************************
	set("exits", ([
		"north" : __DIR__"shamo",
		"south" : __DIR__"shamo",
		"east"  : __DIR__"shamo",
		"west"  : __DIR__"shamo",
		"enter" : __DIR__"shidong",
	]));
********************************************/
};


CHANGAN_END;
