//jiayingmen.h

//Sample for room: ��ɽ��Ӧ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_jiayingmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ӧ��");


	add_door("��ɽ����ͤ", "��ɽ����ͤ", "��ɽ��Ӧ��");
	add_door("��ɽ����¥", "��ɽ����¥", "��ɽ��Ӧ��");

    set("long","�����ǵط���ӭ�Ӿ�ʦ��ʷ�����������ĵط��������������������ˡ����ϵ���Ҳ�Ͼ�ϸЩ�����ʵ���ʱʱ���¡� " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"yubeiting",
           "north"  : __DIR__"yushulou",
        ]));
********************************************/
};


ROOM_END;
