//ehouse1.h

//Sample for room: ��լ
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_ehouse1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��լ");

	//add npcs into the room
	add_npc("pub_poorman");

	add_door("��ɽ��", "��ɽ��", "��ɽ����լ");

  	set("long","����һ��ʮ�ּ�ª���ı�©���С���ӣ���������һ�������Ĵ���û�У�ֻ��һ���Ű���������Щ�ɲݡ������ӵ�����һ����ƶ���ʵ�����Ķ����졣" );

/*****************************************************
        set("exits", ([ 
            "south" :__DIR__"wexit",
        ]));
//        
        set("objects", ([
            __DIR__"npc/poorman": 1
        ]) );
*****************************************************/
};


ROOM_END;
