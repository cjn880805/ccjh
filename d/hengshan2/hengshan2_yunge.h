//yunge.h

//Sample for room: ��ɽ�Ƹ����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_yunge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�Ƹ����");


	add_door("��ɽ��ʽջ��", "��ɽ��ʽջ��", "��ɽ�Ƹ����");
	add_door("��ɽ������", "��ɽ������", "��ɽ�Ƹ����");

    set("long","����ջ�����͵��Ƹ���š�ǰ����ɽ������Է壬��Ҫ�������������ӡ������Բ���ˮ�������������ؽ��泩�� " );
    

/*****************************************************
        set("exits", ([ 
           "east"      : __DIR__"daziling",
           "northdown" : __DIR__"zhandao",
        ]));
	set("objects", ([
		__DIR__"npc/zhi" : 1,
	]));
********************************************/
};


ROOM_END;
