//shanlu12.h

//Sample for room: ��ɽɽ·12
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·12");
	
	add_npc("pub_daoke");       //add by zdn 2001-07-17


	add_door("��ɽɽ·11", "��ɽɽ·11", "��ɽɽ·12");
	add_door("��ɽˮ����", "��ɽˮ����", "��ɽɽ·12");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣������ɽ��·��������������ˮ�졣" );
    

/*****************************************************
        set("exits", ([  
           "west"    : __DIR__"shanlu11",
           "eastup"  : __DIR__"shuiliandong",
        ]));
********************************************/
};


ROOM_END;
