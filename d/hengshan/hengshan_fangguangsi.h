//fangguangsi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_fangguangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");


	add_door("��ɽɽ·10", "��ɽɽ·10", "��ɽ������");
	add_door("��ɽɽ��", "��ɽɽ��", "��ɽ������");

    set("long","���������������¡��������а˸�ɽͷ�����������꣬�����¾ͽ������������ĵ�һƬƽ���ϡ��������ţ��� '���η����£���֪����֮��' ֮˵���� '������֮��' Ϊ��ɽ���ľ�֮һ��" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
********************************************/
};


ROOM_END;
