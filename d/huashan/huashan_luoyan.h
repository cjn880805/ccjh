//luoyan.h

//Sample for room: ��ɽ�����
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_luoyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�����");

	add_npc("huashan_feng");	

	add_door("��ɽ����ջ��", "��ɽ����ջ��", "��ɽ�����");

	set("long", "�Ϸ���������壬�ǻ�ɽ��߷塣��ͷ��̼��࣬�硰̫����ͷ�������������족����������ǡ��ȣ����Ի���֮�ߡ��������ܣ��������¡���׼ʫ��Ի��ֻ�������ϣ�����ɽ���룻��ͷ���ս������װ��Ƶ͡���˵���ʱ�����ʿ���Ҿ������������̫��������گ������ɽ���٣�����������д��лگ��˵����һƬҰ�Ķ���������ס�����س�گ�ݽ̵�������������ʾ��Ը��ɽ���١�");  
 
/*****************************************************
        set("objects", ([
//            CLASS_D("huashan") + "/feng-qingyang":1,
            CLASS_D("huashan") + "/feng" : 1,
        ]));
        set("exits", ([ 
           "northdown" : __DIR__"zhandao",
        ]));
********************************************/
};


ROOM_END;
