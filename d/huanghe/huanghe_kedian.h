//kedian.h

//Sample for room: �ƺӿ͵�
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӿ͵�");

	//add npcs into the room
	add_npc("pub_xiaoer2");

	add_door("�ƺ�����", "�ƺ�����", "�ƺӿ͵�");
	add_door("�ƺ����", "�ƺ����", "�ƺӿ͵�");

	set("long","����һ�ҵ��ؾ��񿪵ļ�ëС�꣬¥����Щ±�˺��Ӿƣ�¥�����ǿͷ��������ڽ�����ɽ��ǰ��Ψһ��Ϣ֮�����������䣬��ҩ�͵Ƚ��ڴ�������ʱ���ɿ���һ����Ѱ�ɷõ�֮����ǽ����һ������(paizi)��������һ����ǡ�");
    
    set("no_fight", 1);
    set("valid_startroom", 1);
    set("sleep_room",1);

/*****************************************************
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                "/d/hangzhou/npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"majiu",
                "east" : __DIR__"yongdeng",
                "up"   : __DIR__"kedian2",
        ]));
********************************************/
};


CHANGAN_END;
