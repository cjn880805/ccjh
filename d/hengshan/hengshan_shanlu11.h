//shanlu11.h

//Sample for room: ��ɽɽ·11
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·11");


	add_door("��ɽ��۷�", "��ɽ��۷�", "��ɽɽ·11");
	add_door("��ɽɽ·12", "��ɽɽ·12", "��ɽɽ·11");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣������ɽ�ǳ�۷塣����ԶԶ���Կ�����ɽ���֮һ���ϸǷ���" );
    

/*****************************************************
        set("exits", ([  
           "westup"  : __DIR__"chidifeng",
           "east"    : __DIR__"shanlu12",
        ]));
********************************************/
};


ROOM_END;
