//zhurongdian.h

//Sample for room: ף�ڵ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan_zhurongdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ף�ڵ�");
	
	add_npc("henshan_liuzf");         //add by zdn 2001-07-20


	add_door("��ɽ����̨", "��ɽ����̨", "��ɽף�ڵ�");
	add_door("��ɽף�ڷ�", "��ɽף�ڷ�", "��ɽף�ڵ�");
	add_door("��ɽ����̨", "��ɽ����̨", "��ɽף�ڵ�");

    set("long","ף�ڵ������ʥ�������ף�ڡ�����ʯ��ǽ�����߸�����������հ�ѩ��ΡȻ�����ں�ɽ����������ʯ��Ͽ���:  '�����ճ�����������' ��������'ʥ���ػ�'��鹶���������Ǻ�ɽ���������ڡ�" );

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"wangritai",
           "northdown"  : __DIR__"wangyuetai",
           "westup"     : __DIR__"zhurongfeng",
        ]));
	set("objects", ([
		__DIR__"npc/moda" : 1,
	]));
********************************************/
};


ROOM_END;
