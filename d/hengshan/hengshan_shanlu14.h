//shanlu14.h

//Sample for room: ��ɽɽ·14
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·14");
	
	add_npc("pub_gongzi");           //add by zdn 2001-07-17


	add_door("��ɽ������", "��ɽ������", "��ɽɽ·14");
	add_door("��ɽ�ؾ���", "��ɽ�ؾ���", "��ɽɽ·14");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣ɽ·ת��ܽ�ط壬����ԶԶ�����ؾ��󣬶��Ϸ���ͨ�������š�" );
    

/*****************************************************
        set("exits", ([ 
           "west"       : __DIR__"cangjingdian",
           "southeast"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
