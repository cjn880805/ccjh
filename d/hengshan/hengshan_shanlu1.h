//shanlu1.h

//Sample for room: ��ɽɽ·1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·1");
	
	add_npc("pub_xiaozei");        //add by zdn 2001-07-17


	add_door("��ɽ������", "��ɽ������", "��ɽɽ·1");
	add_door("��ɽɽ·2", "��ɽɽ·2", "��ɽɽ·1");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣" );
    

/*****************************************************
        set("exits", ([  
           "southdown"  : __DIR__"beimen",
           "northwest"  : __DIR__"shanlu2",
        ]));
********************************************/
};


ROOM_END;
