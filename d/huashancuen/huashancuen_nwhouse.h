//nwhouse.h

//Sample for room: ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_nwhouse);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��");

	//add npcs into the room
	add_npc("pub_cuihua");

	add_door("��ɽ��", "��ɽ��", "��ɽ����");
   	set("long","����һ��С���䣬������Ʈ��һ�ɴ�м���۵�ζ������ǽ�����Ŵ󴲣���ͷ�и�С��ױ̨." );
    
/*****************************************************
        set("exits", ([ 
            "northeast" : __DIR__"nwroad2",
        ]));
        set("objects", ([
                __DIR__"npc/cuihua": 1
        ]) );
//        
********************************************/
};


ROOM_END;
