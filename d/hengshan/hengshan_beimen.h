//beimen.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_beimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽ���", "��ɽ���", "��ɽ������");
	add_door("��ɽɽ·1", "��ɽɽ·1", "��ɽ������");

    set("long","���������������Ǵ���ĺ��ţ����ں�ɽɽ´������������ǽ���ߣ���̻Ի͡���������ɽ����С·��" );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"houdian",
           "northup": __DIR__"shanlu1",
        ]));
********************************************/
};


ROOM_END;
