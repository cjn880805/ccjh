//nantaisi.h

//Sample for room: ��ɽ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_nantaisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ");

	add_door("��ɽɽ·9", "��ɽɽ·9", "��ɽ��̨��");

    set("long","��̨��Ϊ�������滳�õĵ���ʯͷϣǨ�ĵ������������Ʒ�����ʯͷ����Ĺ����������е�������ͨ�ģ�Ȫ�����ˣ�����׷ɣ�ɽ�紵��ʱ��ҶϤ�������ȥ����" );
    

/*****************************************************
        set("exits", ([ 
           "northdown"  : __DIR__"shanlu9",
        ]));
        set("outdoors", "henshan");
********************************************/
};


ROOM_END;
