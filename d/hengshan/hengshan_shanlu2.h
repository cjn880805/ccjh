//shanlu2.h

//Sample for room: ��ɽɽ·2
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·2");
	
	add_npc("animal_dushe");             //add by zdn 2001-07-17

	add_door("��ɽɽ·1", "��ɽɽ·1", "��ɽɽ·2");
	add_door("��ɽ��۷�", "��ɽ��۷�", "��ɽɽ·2");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣" );
    

/*****************************************************
        set("exits", ([  
           "southeast"  : __DIR__"shanlu1",
           "northup"    : __DIR__"chidifeng",
        ]));
********************************************/
};


ROOM_END;
