//xuanbing.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xuanbing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");


	add_door("���ջ���13", "���ջ���13", "����������");

	set("long", " ���������ڹ��ĵط��� ����������һ��ǧ������(ice)������ð��˿˿������ ������˺������ˣ��㲻�ɵô���һ��������" );
	

/*****************************************************
    set("exits", ([
		"east" : __DIR__"changl13",
        ]));
	set("item_desc", ([
	    "ice" : "����һ�������ɽ֮�۵�ǧ������,��˵������������°빦��.\n�����������(climb)��ȥ.\n",
	]));
********************************************/
};


ROOM_END;
