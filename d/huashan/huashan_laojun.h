//laojun.h

//Sample for room: ��ɽ�Ͼ���
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_laojun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�Ͼ���");
	add_npc("pub_murenjin");

	add_door("��ɽƽ��ʯ", "��ɽƽ��ʯ", "��ɽ�Ͼ���");
	add_door("��ɽ�����", "��ɽ�����", "��ɽ�Ͼ���");

	set("long", "��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤��ɽ�����ഫΪ̫���Ͼ����ˣ�����·��ͨ��������ϴ���ţ�������������������Ϊ��ɽͨ����");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"pingxinshi",
            "southup"  : __DIR__"husun",
        ]));
        set("objects", ([
             __DIR__"npc/lao-denuo": 1,
        ]));
********************************************/
};


ROOM_END;
