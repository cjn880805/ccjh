//xuantianya.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_xuantianya);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "����������");

	add_npc("mingjiao_xiaozhao");

	add_door("������ʯ���3", "������ʯ���3", "����������");
	add_door("�����һ����Ʒ�", "�����һ����Ʒ�", "����������");

	set("long", "����ɽ·���ͣ�����һ�˶��·�����ͱڸ��ʣ�·�ҽ���������Ԩ��ʵ����һ�򵱹ء����Ī������Ҫ֮�����������ʣ���Ҫ���������������ˡ�����·�ң���Ȼ����һ���ʯ���߽����ɣ���Ϊ������ʯ����������������Զ���ƺ���    ��ǫִ���������á�");
    

/*****************************************************
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
        "out": __DIR__"rjqmen",
	]));
********************************************/

};



ROOM_END;
