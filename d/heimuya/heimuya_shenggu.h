//shenggu.h

//Sample for room: ʥ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shenggu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ʥ����");

	//add npcs into the room
	add_npc("pub_shinu");
	add_npc("heimuya_renyingying");      // add by zdn 2001-07-20

	add_door("��ľ�°׻���", "��ľ�°׻���", "��ľ��ʥ����");

	set("long", "�����Ǻ�ľ�µ�ʥ�����ڵء�ʥ���á�������������ޣ�ɷ��Ư��������һλ����Ů�ӣ�����С�䣬���޲��ɷ��");

/*****************************************************
        set("exits", ([
            "east"   : __DIR__"chitang",
        ]));
        set("objects", ([
            __DIR__"npc/ren" : 1,
            __DIR__"npc/shinu":2,
        ]));       
//        
********************************************/
};


ROOM_END;
