//tianzhu.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_tianzhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽɽ·7", "��ɽɽ·7", "��ɽ������");
	add_door("��ɽɽ·10", "��ɽɽ·10", "��ɽ������");

    set("long","�����Ϻ�ɽ���֮һ�������壬����Ⱥɽ��������У�ÿÿ������ʪʱ������������������������ˡ�" );
    

/*****************************************************
        set("exits", ([
           "westdown"   : __DIR__"shanlu10",
           "eastdown"   : __DIR__"shanlu7",
        ]));
********************************************/
};


ROOM_END;
