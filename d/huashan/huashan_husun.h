//husun.h

//Sample for room: ��ɽ�����
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_husun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�����");

	//add npcs into the room
//	add_npc("animal_monkey");
//	add_npc("animal_monkey");

	add_door("��ɽ�Ͼ���", "��ɽ�Ͼ���", "��ɽ�����");
	add_door("��ɽ������", "��ɽ������", "��ɽ�����");

	set("long", "ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨�ϣ���˵��ǰ�ӻ�ɽˮ����������Գ�ÿ�������Ҫ����ȥ��������Ҳ�е����ڳ�Խ���������������");  
    
 
/*****************************************************
        set("exits", ([  
            "northdown" : __DIR__"laojun",
            "southup"   : __DIR__"shangtianti",
        ]));
        set("objects", ([  
            "/d/wudang/npc/monkey": 1,
            "/d/wudang/npc/little_monkey": 2,
        ]));
********************************************/
};


ROOM_END;
