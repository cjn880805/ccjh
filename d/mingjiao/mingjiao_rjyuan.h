//rjyuan.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_rjyuan);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "���̴�Ժ");

	add_door("��΢��", "������΢��", "���̴�Ժ");
	add_door("��΢��", "������΢��", "���̴�Ժ");

	set("long", "���߽��������Ĵ�Ժ��ȴ����������Ӱϡ�裬�������������˵Ĵ�������ȴ�����������̣��������ƺ��Ǵ���Զ�ĵ��´����ġ������ߣ���Ҫ������¥�ˡ�Ժ�����׿��������䳡����Լ����������������һ��������������������᳡����    ��ǫִ���������á�");
    

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
