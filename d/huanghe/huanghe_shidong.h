//shidong.h

//Sample for room: �ƺ�ʯ��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_shidong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ʯ��");

	//add npcs into the room
	add_npc("honghua_chenjuyang");

	add_door("�ƺ�ɳĮ2", "�ƺ�ɳĮ2", "�ƺ�ʯ��");

	set("long","����ɳĮ����Ȼ�γɵ�һ��ʯ�������й��߻谵����ȴʮ�ָ���������߼��ѵ��ݣ��ƺ��ǹ���˯��֮�ã��������������з·�������ˮ��������һ�Ƿ���������ͷ��(skulls)��");

/*****************************************************
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "һ���������������ͷ����һ�������壬���಻�٣�ǡ��
�ſŰ׹�����ͷ��\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
********************************************/
};


CHANGAN_END;
