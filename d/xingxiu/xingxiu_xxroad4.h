//xxroad4.h

//Sample for room: ���޺�С·
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xxroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺�С·");

	add_npc("xingxiu_chuchen");	

	add_door("���޺�ɽ��ƽ��", "���޺�ɽ��ƽ��", "���޺�С·");
	add_door("�����ɴ�����", "�����ɴ�����", "���޺�С·");
	add_door("���޺���ɽɽ·3", "���޺���ɽɽ·3", "���޺�С·");
	
    set("long","ɽ�������･�����ƽ�������Ѿ�������������ɽ���׵�ˮ����������һ��ɽ����" );

/*****************************************************
        set("exits", ([
            "south" : __DIR__"xxroad4",
            "enter" : __DIR__"cangku",
            "north" : __DIR__"xxroad6",
        ]));
        set("objects", ([
            CLASS_D("xingxiu")+"/chuchen" : 1,
        ]) );
********************************************/
};


ROOM_END;
