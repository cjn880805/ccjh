//tiandi2.h

//Sample for room: �ƺ����2
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_tiandi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ����2");

	//add npcs into the room
//	add_npc("animal_cow");
        add_npc("pub_cunfu");        // add by zdn 2001-07-14

	add_door("�ƺ����1", "�ƺ����1", "�ƺ����2");
	add_door("�ƺ�����5", "�ƺ�����5", "�ƺ����2");

	set("long","������һ��Ƭũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ�");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"shulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("objects", ([
		"/d/wudang/npc/cow" : 1,
	]));
********************************************/
};


CHANGAN_END;
