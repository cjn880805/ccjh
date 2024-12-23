//shack.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_shack);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	//add npcs into the room
	add_npc("pub_seller1");

	add_door("��ɽ��", "��ɽ��", "��ɽ�����");

  	set("long","����һ���򵥵Ĳ�����ϰ���һ�ѶѵĻ����ɽ���οͿ���������Щ��ɽ��Ʒ�������ǽ�����Ÿ����ӣ��Ǹ���Ŀ��(sign)��" );

/*****************************************************
        set("exits", ([ 
            "north" : __DIR__"eroad1",
        ]));
        set("objects", ([
                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ 
        "sign" : "������д����
	����(stick)	һ����
	��Ь(shoes)	һ����ʮ��
	ˮ��(bottle)	һ����

		���� Ƥ��(egg) ��ʮ�ģ���ˮ(not yet) xx�� \n"
        ]));
//        
*****************************************************/
};


ROOM_END;
