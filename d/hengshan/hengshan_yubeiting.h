//yubeiting.h

//Sample for room: ��ɽ����ͤ
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_yubeiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ͤ");
	
	add_npc("henshan_xiaoqu");        //add by zdn 2001-07-20


	add_door("��ɽ������", "��ɽ������", "��ɽ����ͤ");
	add_door("��ɽ��Ӧ��", "��ɽ��Ӧ��", "��ɽ����ͤ");

    set("long","����Ϊ�����������ʯ���������ɣ�ʯ���������������ǧ��Ĵ�ʯ���ϣ�������ϸ�壬��Ϊ������ " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"zhengchuan",
           "north"  : __DIR__"jiayingmen",
        ]));
********************************************/
};


ROOM_END;
