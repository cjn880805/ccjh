//zhandao.h

//Sample for room: ��ɽ����ջ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_zhandao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����ջ��");


	add_door("��ɽɽ��", "��ɽɽ��", "��ɽ����ջ��");
	add_door("��ɽ�����", "��ɽ�����", "��ɽ����ջ��");

	set("long", "ջ������б�壬�ϸ���ʯ�壬����˴硣���˾��ڣ�������ڡ����������ϣ�ֻ��ɽ���Х������ŭ��Զ��ż��һ����������˻����ʹ��ë���Ȼ��̤�����յ�ջ����������������Ϣ����������Ų�������ܹ�ȥ��");  
    

/*****************************************************
        set("exits", ([  
           "southup"   : __DIR__"luoyan",
           "northdown" : __DIR__"sgyhole",
        ]));
********************************************/
};


ROOM_END;
