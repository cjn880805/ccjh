//beiyuedian.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_beiyuedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");


	add_door("��ɽ������", "��ɽ������", "��ɽ������");
	add_door("��ɽ���Է�ɽ��1", "��ɽ���Է�ɽ��1", "��ɽ������");

    set("long","�������ϸ����ڣ����ٹ��ݣ����Ƽ����죬�������£�񷱮ɭ�������������������ң����顰��Ԫ֮������ڱ�����ɽ֮��ȫ�����񣬸߿����ࡣ " );
    

/*****************************************************
        set("exits", ([ 
           "westup"    : __DIR__"huixiantai",
           "eastup"    : __DIR__"yuyang",
           "northup"   : __DIR__"shandao1",
           "southdown" : __DIR__"beiyuemiao",
        ]));
********************************************/
};


ROOM_END;
