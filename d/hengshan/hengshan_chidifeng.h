//chidifeng.h

//Sample for room: ��ɽ��۷�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_chidifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��۷�");


	add_door("��ɽɽ·3", "��ɽɽ·3", "��ɽ��۷�");
	add_door("��ɽɽ·2", "��ɽɽ·2", "��ɽ��۷�");
	add_door("��ɽɽ·11", "��ɽɽ·11", "��ɽ��۷�");

    set("long","�ഫף���� '�Ի�ʩ��' ���ǻƵ۵� '������' ���������Ϸ��������������ڴˣ�������۷塣" );
    

/*****************************************************
        set("exits", ([  
           "southdown"  : __DIR__"shanlu2",
           "eastdown"   : __DIR__"shanlu11",
           "northdown"  : __DIR__"shanlu3",
        ]));
********************************************/
};


ROOM_END;
