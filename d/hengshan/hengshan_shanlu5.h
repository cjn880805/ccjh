//shanlu5.h

//Sample for room: ��ɽɽ·5
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·5");


	add_door("��ɽɽ·6", "��ɽɽ·6", "��ɽɽ·5");
	add_door("��ɽ��ɽͤ", "��ɽ��ɽͤ", "��ɽɽ·5");
	add_door("��ɽɽ·13", "��ɽɽ·13", "��ɽɽ·5");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣�����в�·ͨ��ĥ��̨�������塣����������ܽ�ط��ˣ�ף�ڷ�Ҳ�����������" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"banshan",
           "west"       : __DIR__"shanlu6",
           "northwest"  : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
