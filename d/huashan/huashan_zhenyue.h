//zhenyue.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zhenyue);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("huashan_feng_buping");

	add_door("��ɽ������", "��ɽ������", "��ɽ������");
	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽ������");
	add_door("��ɽ������С·", "��ɽ������С·", "��ɽ������");

	set("long", "�������бڶ������ı����ֱ��գ���ɫ��������ǰ����(jing)���ഫ��������ǧҶ���������������Ϊƽ̹���ϡ���ɽ���οͶ��ڴ�������Ϣ�ټ���ǰ�С������м����ª�����磬���Ƕ�����ճ��ߣ�����ͷ��ЪϢ�ڴˡ�");  
    set("resource/water", 1);

/*****************************************************
        set("exits", ([ 
            "northdown"  : __DIR__"jinsuo",
            "eastup"     : __DIR__"yunu",
            "southwest"  : __DIR__"lianpath1",
        ]));
        set("objects", ([
            __DIR__"npc/gao-genming" : 1,
        ]));
        set("item_desc", ([
            "jing" : "����ˮɫ��͸�����ֿ�����\n",
        ]));

//        
        set("outdoors", "huashan" );
********************************************/
};


ROOM_END;
