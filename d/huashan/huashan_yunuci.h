//yunuci.h

//Sample for room: ��ɽ��Ů��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunuci);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ů��");


	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽ��Ů��");

	set("long", "��Ů���﹩��ĵ�������λ��Ů������಻ͬ��˵�����������ܿ�����ֻһ������ʯ�����д�ʯ����һ�����ݣ�������ˮ��̣�������Ů��ϴ���裬��ˮ���겻�ɡ�");  
    
    set("resource/water", 1);
 
/*****************************************************
        set("exits", ([  
            "east" : __DIR__"yunu",
        ]));
********************************************/
};


ROOM_END;
