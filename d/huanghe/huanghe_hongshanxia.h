//hongshanxia.h

//Sample for room: �ƺӺ�ɽϿ
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_hongshanxia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӺ�ɽϿ");

	//add npcs into the room
	add_npc("pub_mazei");

	add_door("�ƺ�ʯ��", "�ƺ�ʯ��", "�ƺӺ�ɽϿ");
	add_door("�ƺӾ�Զ", "�ƺӾ�Զ", "�ƺӺ�ɽϿ");

	set("long","��ɽϿ�Ǹ��ǳ��վ���Ͽ�ȣ���������ʮ�ɵĻ����£����Ƕ��ͣ��м�ֻ��һ������ͨ��һ��һ���խ�����׳ơ�һ���족������û��ʲô���ȴ�����ó�������ʧ�١�");

/*****************************************************
	set("exits", ([
		"north"     : __DIR__"shimen",
		"south"     : __DIR__"jingyuan",
	]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));
********************************************/
};


CHANGAN_END;
