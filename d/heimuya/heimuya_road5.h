//road5.h

//Sample for room: ����·5
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����·5");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("��ľ�³���", "��ľ�³���", "��ľ�»���·5");
	add_door("��ľ��ʥ����", "��ľ��ʥ����", "��ľ�»���·5");
	add_door("��ľ�°׻��ô���", "��ľ�°׻��ô���", "��ľ�»���·5");

	set("long", "������һ������·�ϡ������Ѿ������������ˣ�����һ����������������������Ļ������£�û��һ˿���ĵ���ɫ����������������ˮ�����졣");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : "/d/huanghe/weifen",
                "south"     : __DIR__"road6",
        ]));
********************************************/
};

	

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp