//road2.h

//Sample for room: ����·2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·2");
	
	add_npc("heimuya_jiaotu");       //add by zdn 2001-07-20


	add_door("��ľ����ʯ��", "��ľ����ʯ��", "��ľ�»���·2");
	add_door("��ľ��ƽ����", "��ľ��ƽ����", "��ľ�»���·2");

	set("long", "������һ������·�ϡ�������һ��С�߸ڣ������ն񣬿��öϾ��������������Կ���ƽ���ݳǡ�");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
            "southwest" : __DIR__"road1",
            "east" : __DIR__"pingdingzhou",
        ]));
********************************************/
};


ROOM_END;
