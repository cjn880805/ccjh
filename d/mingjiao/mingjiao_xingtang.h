//xingtang.h
//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_xingtang);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "��������");
	
	add_npc("mingjiao_lengqian");

	add_door("���̹㳡", "���̹㳡", "��������");

	set("long", "���������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����ҹһ�㣬ÿ��������ǽ�ϣ���ȼ�ż�֦ţ�;����м���һ������裬�������ڡ��·�����һ����������ˮţƤ�ޡ�������弰���������̾ߡ�����վ�����ֱֳ��е�ִ�����ڡ�����������������������㣬���㲻���������������    ��ǫִ���������á�");
	

	set("no_fight", "1");

/*****************************************************



	set("exits", ([

		"west" : __DIR__"square",

	]));

	set("objects",([

		__DIR__"npc/lengqian" : 1

	]));

********************************************/

};


ROOM_END;
