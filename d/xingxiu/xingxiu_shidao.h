//shidao.h

//Sample for room: ���޺�ʯ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_shidao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺�ʯ��");
        add_npc("xingxiu_caihua");
	add_door("���޺�", "���޺�", "���޺�ʯ��");
	add_door("���޺���ң��", "���޺���ң��", "���޺�ʯ��");

    set("long","�������޺���������ʯͷ�̳ɵ�һ��С������Χ�����������������һ��˵����������ζ��·���и�ʯ����" );

/*****************************************************
        set("exits", ([ 
            "east" : __DIR__"xxh4",
            "enter" : __DIR__"xiaoyao",
        ]));
        set("objects", ([ 
            __DIR__"npc/caihua" : 1,
        ]) );
********************************************/
};


ROOM_END;
