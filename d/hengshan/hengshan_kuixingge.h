//kuixingge.h

//Sample for room: ��ɽ���Ǹ�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_kuixingge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ���Ǹ�");

	add_door("��ɽ��ͤ", "��ɽ��ͤ", "��ɽ���Ǹ�");
	add_door("��ɽ������", "��ɽ������", "��ɽ���Ǹ�");
	add_door("��ɽ������", "��ɽ������", "��ɽ���Ǹ�");

    set("long","���Ǹ�����������ĵڶ�������Ϊһ������̨������Ϊ��ͤ��������ͤ��������ڳ�Ϸ�������������ַǷ��� " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"lingxingmen",
           "east"   : __DIR__"zhongting",
           "north"  : __DIR__"zhengchuan",
        ]));
********************************************/
};


ROOM_END;
