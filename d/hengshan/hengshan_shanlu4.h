//shanlu4.h

//Sample for room: ��ɽɽ·4
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·4");
	
	add_npc("pub_flowerg");        //add by zdn 2001-07-17


	add_door("��ɽɽ·3", "��ɽɽ·3", "��ɽɽ·4");
	add_door("��ɽ��ɽͤ", "��ɽ��ɽͤ", "��ɽɽ·4");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣" );
    

/*****************************************************
        set("exits", ([ 
           "southeast" : __DIR__"shanlu3",
           "northup"   : __DIR__"banshan",
        ]));
********************************************/
};


ROOM_END;
