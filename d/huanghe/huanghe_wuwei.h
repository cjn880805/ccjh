//wuwei.h

//Sample for room: �ƺ�����
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wuwei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�����");

	//add npcs into the room
	add_npc("pub_xixiabing");

	add_door("�ƺ�������", "�ƺ�������", "�ƺ�����");
	add_door("�ƺ�������", "�ƺ�������", "�ƺ�����");

	set("long","���������Ĺ�����������פ���ر�����¥�ߴ����ɣ��ſ������Źٱ�����������̲�������ˣ����ſڵĸ�ʾ�ϻ������ͨ���Ľ�������ͼ�Σ�����ͷ����ȥ��ͦ���֡����Ͼ���ȥ���ǵķ����ˣ��������������ɽ����");

/*****************************************************
	set("exits", ([
		"southeast" : __DIR__"wuqiao",
		"north"     : __DIR__"tumenzi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 3,
	]));
********************************************/
};


CHANGAN_END;
