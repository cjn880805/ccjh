//denggaotai.h

//Sample for room: ��ɽ�Ǹ�̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_denggaotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�Ǹ�̨");


	add_door("��ɽ������", "��ɽ������", "��ɽ�Ǹ�̨");

    set("long","�����������ŵǸ���Զ�ĺ�ȥ������վ�����������壬���������衣���潭��ȥ������ű���ʱ��ʱ�֡���Χ��ϼ�����ޣ��ϸǣ�������廷����������ǧ��" );
    

/*****************************************************
        set("exits", ([ 
           "northdown"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
