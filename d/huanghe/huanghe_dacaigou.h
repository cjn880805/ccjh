//dacaigou.h

//Sample for room: �ƺӴ��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_dacaigou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӴ��");

	//add npcs into the room
	add_npc("pub_qiaofu");

	add_door("�ƺӹ���", "�ƺӹ���", "�ƺӴ��");
	add_door("�ƺ�������", "�ƺ�������", "�ƺӴ��");

	set("long","��񹵵��Ʋ���������������Ҫ���Ƚ�ƽ̹���ٵ�����ȫ�����֣�ʱ�����Է򿳲�����������д�����");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"gulang",
		"north"     : __DIR__"wuqiao",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu" : 1,
	]));
********************************************/
};


CHANGAN_END;
