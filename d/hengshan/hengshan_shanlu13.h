//shanlu13.h

//Sample for room: ��ɽɽ·13
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·13");
	
	add_npc("pub_youke");         //add by zdn 2001-07-17

	add_door("��ɽɽ·5", "��ɽɽ·5", "��ɽɽ·13");
	add_door("��ɽ������", "��ɽ������", "��ɽɽ·13");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣�����������������ˣ��߸ߴ������������ľ��Ǻ�ɽ���֮һ��ܽ�ط塣" );
    

/*****************************************************
        set("exits", ([ 
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
********************************************/
};


ROOM_END;
