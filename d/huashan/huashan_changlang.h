//changlang.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_changlang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");


	add_door("��ɽ��԰", "��ɽ��԰", "��ɽ����");
	add_door("��ɽ����", "��ɽ����", "��ɽ����");
	add_door("��ɽ������", "��ɽ������", "��ɽ����");

	set("long", "�����ڳ�����ֻ���������ߣ���������������紵����ϸ�����󣬿�����ɽ�����ɹ�Ȼ�����������������˵ľ��ҡ�");  
    
 
/*****************************************************
        set("exits", ([
            "west"  : __DIR__"jushi",
            "north" : __DIR__"songlin1",
            "south" : __DIR__"garden",
        ]));
********************************************/
};


ROOM_END;
