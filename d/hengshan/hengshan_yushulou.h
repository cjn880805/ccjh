//yushulou.h

//Sample for room: ����¥
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_yushulou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");
	
	add_npc("pub_shutong");          //add by zdn 2001-07-17


	add_door("��ɽ��Ӧ��", "��ɽ��Ӧ��", "��ɽ����¥");
	add_door("��ɽ���", "��ɽ���", "��ɽ����¥");

    set("long","����¥Ϊ��������������֮�����������ͣ��ʹ��־裬�������������ۡ�" );
    

/*****************************************************
         set("exits", ([ 
           "south"  : __DIR__"jiayingmen",
           "north"  : __DIR__"dadian",
        ]));
********************************************/
};


ROOM_END;
