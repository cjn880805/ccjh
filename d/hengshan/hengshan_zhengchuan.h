//zhengchuan.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhengchuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");
	
	add_npc("henshan_qu");        //add by zdn 2001-07-20


	add_door("��ɽ���Ǹ�", "��ɽ���Ǹ�", "��ɽ������");
	add_door("��ɽ����ͤ", "��ɽ����ͤ", "��ɽ������");

    set("long","����������������ĵ�������Ժ���������ڵ��ʥ��������¥� " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"kuixingge",
           "north"  : __DIR__"yubeiting",
        ]));
********************************************/
};


ROOM_END;
