//shanlu10.h

//Sample for room: ��ɽɽ·10
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·10");
	
	add_npc("pub_jianke");           //add by zdn 2001-07-17


	add_door("��ɽ������", "��ɽ������", "��ɽɽ·10");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ·10");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣ɽ·����ͨ�򷽹��¡������������塣" );
    

/*****************************************************
        set("exits", ([  
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
********************************************/
};


ROOM_END;
