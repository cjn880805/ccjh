//shulin1.h

//Sample for room: �ƺ�����1
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shulin1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����1");

	//add npcs into the room
	add_npc("animal_dushe");
	add_npc("pub_zongjinquan");

	add_door("���ݱ����", "���ݱ����", "�ƺ�����1");

	add_door("�ƺ�����2", "�ƺ�����2", "�ƺ�����1");
	add_door("�ƺ�����3", "�ƺ�����3", "�ƺ�����1");

	set("long","��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ�����������һ������(paizi)��");
	

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("item_desc", ([
		"paizi" : HIR"\n�ǻƺӰ�����    �����ɱ����\n\n"NOR,
	]));
	set("objects", ([
		"/d/shenlong/npc/dushe" : 1,
		"/d/hangzhou/obj/shuzhi" : 1,
	]));
********************************************/
};


CHANGAN_END;
