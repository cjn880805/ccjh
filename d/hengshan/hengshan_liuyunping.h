//liuyunping.h

//Sample for room: ��ɽ����ƺ
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_liuyunping);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ƺ");


	add_door("��ɽ������", "��ɽ������", "��ɽ����ƺ");

    set("long","ÿ���������ں�ɽ������������������ɽ����ӿ��������ɽ������ǰɽ��к��ֱ�����ӷ�к��εΪ׳�ۣ�����������ŵ������澰��" );
    

/*****************************************************
        set("exits", ([ 
           "westdown"  : __DIR__"nantian",
        ]));
********************************************/
};


ROOM_END;
