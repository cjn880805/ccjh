//shamo.h

//Sample for room: �ƺ�ɳĮ1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shamo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ɳĮ1");
	
	add_npc("pub_tufeitou");  ///add by zdn 2001-07-14

	add_door("�ƺӾ�Զ", "�ƺӾ�Զ", "�ƺ�ɳĮ1");
	add_door("�ƺ�ɳĮ2", "�ƺ�ɳĮ2", "�ƺ�ɳĮ1");

	set("long","����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽����ͷ·�����·��");
	

/*****************************************************
	set("exits", ([
		"north" : __FILE__,
		"south" : __DIR__"shamo1",
		"east"  : __FILE__,
		"west"  : __FILE__,
	]));
********************************************/
};


CHANGAN_END;
