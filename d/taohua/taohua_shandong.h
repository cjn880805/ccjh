//shandong.h

//Sample for room: ɽ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_shandong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ��");


	add_door("�һ���", "�һ���", "�һ���ɽ��");

	set("long", "��������һ��Сɽ���С�������ߺܰ���ֻ������ԼԼ����������һ�Ѹɲݡ��ɲ��Ϻ������һ��ʯϻ(xia)�� ��ͻȻ�ŵ�һ�����ŵ���ζ����Ȼ�����˳���ס������ȴ����ɨ��Ե�ʡ�");

/*****************************************************
        set("item_desc", ([
        "xia" : @TEXT
        ����ϸ����һ��ʯϻ�����������ƺ�����һ���飬�ƺ����������ó���(pick book)��
        TEXT ]) );
        set("exits", ([
            "out"  : __DIR__"road5",
        ]));
        set("objects", ([
            __DIR__"npc/zhou" : 1,
        ]) );    
********************************************/
};


ROOM_END;
