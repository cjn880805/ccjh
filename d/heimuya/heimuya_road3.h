//road3.h

//Sample for room: ����·3
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·3");
	
	add_npc("heimuya_heiyiren");    //add by zdn 2001-07-20


	add_door("��ľ��ƽ����", "��ľ��ƽ����", "��ľ�»���·3");

	add_door("���������5", "���������5", "��ľ�»���·3");

	set("long", "������һ������·�ϡ�������ɽ���ؽ磬�����ͽ���ӱ��ˡ��������ﲻ��̫ƽʱ�ڣ����ǿ���߰ɡ�");
    

/*****************************************************
         set("outdoors", "heimuya");
        set("exits", ([
                "east" : "/d/city2/ximenwai",
                "west" : __DIR__"pingdingzhou",
        ]));
********************************************/
};


ROOM_END;
