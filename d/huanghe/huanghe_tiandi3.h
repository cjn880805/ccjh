//tiandi3.h

//Sample for room: �ƺ����3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����3");
	
	add_npc("pub_nongfu2");     //add by zdn 2001-07-14
	add_item("daotian");


	add_door("�ƺ����1", "�ƺ����1", "�ƺ����3");
	add_door("�ƺ����4", "�ƺ����4", "�ƺ����3");

	set("long","������һ��Ƭũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ�");
	

/*****************************************************
	set("exits", ([
		"west"      : __DIR__"tiandi1",
		"northeast" : __DIR__"tiandi4",
	]));
********************************************/
};


CHANGAN_END;
