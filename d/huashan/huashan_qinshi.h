//qinshi.h

//Sample for room: ��ɽ����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_qinshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");
	
	add_npc("pub_lady3");           //add by zdn 2001-07-20


	add_door("��ɽ������Ϊ��", "��ɽ������Ϊ��", "��ɽ����");

    set("long","����������Ⱥ�����ң�����Ⱥ�ڽ������˳ơ����ӽ���������Ϊһ�������ţ�����������ȴ���õĺܼ򵥡�����һ�Ŵ�����ֻ���ӣ�ǽ�����Ż�ױ̨��ֻ�п�ǽһ�ź�ľ����(desk)���Ե���������");
	

/*****************************************************
     set("exits", ([
            "south" : __DIR__"buwei1",
        ]));
	set ("item_desc", ([
		"desk" : 
    "����һ�źܽ�ʵ�ĺ�ľ�����������ϰ��ż�ֻ�Ǻ��ʣ�ĥ��һ���ī��\n"
    "����һ��δ�õİ�ֽ��\n"
	])  ) ;

********************************************/
};


ROOM_END;
