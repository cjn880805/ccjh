//shanlu3.h

//Sample for room: ��ɽɽ·3
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·3");
	
	add_npc("pub_caishiren");              //add by zdn 2001-07-17

	add_door("��ɽ��۷�", "��ɽ��۷�", "��ɽɽ·3");
	add_door("��ɽɽ·4", "��ɽɽ·4", "��ɽɽ·3");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣" );
    

/*****************************************************
        set("exits", ([  
           "southup"    : __DIR__"chidifeng",
           "northwest"  : __DIR__"shanlu4",
        ]));
********************************************/
};


ROOM_END;
