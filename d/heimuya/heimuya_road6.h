//road6.h

//Sample for room: ����·6
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·6");
	
	add_npc("heimuya_heiyiren");       //add by zdn 2001-07-20


	add_door("��ľ�³���", "��ľ�³���", "��ľ�»���·6");
	add_door("��ľ��ʥ����", "��ľ��ʥ����", "��ľ�»���·6");
	add_door("��ľ�°׻��ô���", "��ľ�°׻��ô���", "��ľ�»���·6");

	set("long", "������һ������·�ϡ������ĵ��棬���ǿ������Ļ��������Ϸ�����ԶԶ�и�ɽ���ƣ����������и�СС���䡣��������Ȯ�ͼ��䣬���㳤;�ı�������һ˿������");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "southeast" : "/d/village/wexit",
                "north"     : __DIR__"road5",
        ]));
********************************************/
};

	

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp