//shanmen.h

//Sample for room: ���͵�ɽ��
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ɽ��");
	
	add_npc("pub_shiwei");         //add by zdn 2001-07-16

	add_door("���͵���̲", "���͵���̲", "���͵�ɽ��");
	add_door("���͵�ɽ·1", "���͵�ɽ·1", "���͵�ɽ��");

    set("long", "�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ɽ����ɽ�����죬��ʱ�м��������ú���������߹������Ƕ��ǵ����͵���ר���书�ġ�ʯ���Ͽ����������� �����͵��� ������ǽ����ϴ��ŵ����͵���" );
    

/*****************************************************
        set("exits", ([
                "southup" : __DIR__"road1",
                "north" : __DIR__"lin8",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2" : 1]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp