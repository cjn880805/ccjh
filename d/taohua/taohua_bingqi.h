//bingqi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_bingqi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_xiangke");

	add_door("�һ������߷�", "�һ������߷�", "�һ���������");

	set("long", "����һ���ű��������ӡ�����ǹ������ꪵȸ��ֱ�����������ڸ��Եı������ϡ��������������ҳ�����Ȼ�Ѿ��þ�û��������");
	set("valid_startroom", 1);
	set("no_beg", "1");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
	]) );
//	
********************************************/
};


ROOM_END;




