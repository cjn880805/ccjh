//shop.h

//Sample for room: �ӻ���
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ӻ���");

	//add npcs into the room
	add_npc("wudang_lisi");

	add_door("��ɽ��", "��ɽ��", "��ɽ���ӻ���");

  	set("long","����һ��СС���ӻ��꣬��ӪЩ�͡��Ρ������׼����ðٻ�����������˶����Ǻ�������������Ʒ��������ٷ���������Ʒ��" );

/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"eroad3",
        ]));
//        
        set("objects", ([
            __DIR__"npc/xiejian": 1
        ]) );
********************************************/
};


ROOM_END;
