//simenguangchang.h
//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_simenguangchang);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "�������Ź㳡");

	add_door("������ʯ���1", "������ʯ���1", "�������Ź㳡");

	add_door("������������", "������������", "�������Ź㳡");
	add_door("���̵���Ů��", "���̵���Ů��", "�������Ź㳡");
	add_door("������������", "������������", "�������Ź㳡");
	add_door("���̵�������", "���̵�������", "�������Ź㳡");

	set("long", "������һƬͥԺ����Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡�����м���С����ͨ�����̵ġ���ط��ס����š�    ��ǫִ���������á�");
    

/*****************************************************
        "north"     : __DIR__"mjsimen",
        "northwest" : __DIR__"mjtianmen",
        "northeast" : __DIR__"mjdimen",
        "southeast" : __DIR__"mjfengmen",
        "southwest" : __DIR__"mjleimen",
    ]));
    set("outdoors", "mingjiao");
********************************************/

};


ROOM_END;
