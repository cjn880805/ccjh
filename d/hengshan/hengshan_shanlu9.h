//shanlu9.h

//Sample for room: ��ɽɽ·9
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanlu9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽɽ·9");


	add_door("��ɽ������", "��ɽ������", "��ɽɽ·9");
	add_door("��ɽ��̨��", "��ɽ��̨��", "��ɽɽ·9");

    set("long","�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣��������ƣ��������ش�졣�ϱ�����̨�£�����ͨ�������¡�" );
    

/*****************************************************
        set("exits", ([  
           "southup"  : __DIR__"nantaisi",
           "northup"  : __DIR__"fuyansi",
        ]));
********************************************/
};


ROOM_END;
